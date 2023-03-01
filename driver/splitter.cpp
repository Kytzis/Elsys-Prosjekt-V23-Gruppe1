#include "splitter.h"

    
void splitter::splitBuffer() {
    /*
    char* token;
    char delimiters[] = " ";
    int i = 0;
    char* words[100];  // assuming a maximum of 100 words in the string
    
    token = strtok(charbuffer, delimiters);
    while (token != NULL) {
        words[i] = token;
        i++;
        token = strtok(NULL, delimiters);
    }
    */
    String words[100];
    int i = 0;
    while (charbuffer.peek() != decltype(charbuffer)::traits_type::eof()) {
        charbuffer >> words[i];
        ++i;
    }
    
    String* printWords = new String[100];  // assuming a maximum of 100 words in the string
    int numWords = 0;
    String temp = "";
    for (int k = 0; k < i; k++) {
    if((temp.length() + strlen(words[k]) + 1) <= 20) {
        if(temp.length()>0){
            temp += " ";
        }
        temp += words[k];
    }
    else {
        printWords[numWords] = temp;
        numWords++;
        temp = String(words[k]);
    }
    
    if(temp.length() > 0) {
        printWords[numWords] = temp;
        numWords++;
    }
    
    for (int j = 0; j < numWords; j++) {
        screens.push_back({SCREEN_WIDTH_CHARS, SCREEN_HEIGHT_CHARS, printWords[j]});
    }

    delete[] words;
    delete[] printWords;
}


splitter::splitter() {
    
}


void splitter::addInput(std::stringstream& stream) {
    charbuffer << stream;
}

screen& splitter::getScreen() {
    screen temp = {screens.front()};
    screens.erase(screens.begin());
    return temp;
}
