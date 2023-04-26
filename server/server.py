from cgi import parse_header, parse_multipart
from http.server import BaseHTTPRequestHandler, HTTPServer
import json
import time


# Server settings
hostname = 'localhost'
serverPort = 8001
dataName = "1"


# Hacky way to expose stuff publicly for the request handler
data = {}
with open("nettside/tekst.json", "r") as file:
    data = json.loads("".join(file.readlines()))[dataName]
screenTime = int(time.time() * 1000) # Time expressed in ms
curIndex = 0


# Server
class MyServer(BaseHTTPRequestHandler):
    def do_POST(self):
        global dataName, screenTime, curIndex
        if self.path() != "/setvideo":
            self.send_error(400, message="bad POST", explain="POST request was sent on a path that is not supported")
            self.log_error(code=400)

        self.send_response(200)
        postvars = self.parse_POST()
        dataName = postvars[id]
        screenTime = int(time.time() * 1000) - float(postvars[time])
        curIndex = 0


    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        if self.path == "/favicon.ico":
            # Fuck denne, trengs ikke
            pass
        elif self.path == "/":
            self.getCurrentIndex()
        else:
            self.getData(int(self.path[1:]))
    
    
    def parse_POST(self):
        content_length = self.headers.getheaders('content-length')
        length = int(content_length[0]) if content_length else 0
        ctype, pdict = parse_header(self.headers['content-type'])
        print(self.rfile.read(length))
        if ctype == 'multipart/form-data':
            postvars = parse_multipart(self.rfile, pdict)
        elif ctype == 'application/json':
            postvars = {}
        else:
            postvars = {}
        return postvars


    def getCurrentIndex(self):
        global screenTime, curIndex
        # Update index
        while int(time.time() * 1000) - screenTime >= data[curIndex][0]:
            if data[curIndex+1][1] == "\n":
                curIndex = 0    # Reset to screen 0
            else:
                curIndex += 1   # Progress to next screen
            screenTime += data[curIndex-1][0]

        self.wfile.write(bytes(str(curIndex), "utf-8"))


    def getData(self, index: int=-1):
        self.wfile.write(bytes("\n\n" + data[index][1], "utf-8"))


# Loop to run shit
if __name__ == "__main__":    
    webServer = HTTPServer((hostname, serverPort), MyServer)
    print("Server started http://%s:%s" % (hostname, serverPort))

    try:
        webServer.serve_forever()
    except KeyboardInterrupt:
       pass

    webServer.server_close()
    print("Server stopped.")