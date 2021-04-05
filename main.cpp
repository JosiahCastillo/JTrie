#include <iostream>
#include <vector>
#include "JTrie.h"

int main(){
    //creates a Trie
    JTrie myTrie;
    
    //setting up strings to insert
    std::string myStrings[3];
    std::string myStrings[0] = "hello";
    std::string myStrings[1] = "helps";
    std::string myStrings[2] = "hand";
    
    //inserting strings
    for(int i = 0; i < 3; i++){
        myTrie.insert(myStrings[i]);
    }
    
    //confirming they exist
    for(int i = 0; i < 3; i++){
        if(myTrie.search(myStrings[i])){
            std::cout << myStrings[i] << " exists." << std::endl;
        } else {
            std::cout << myStrings[i] << " doesn't exist." << std::endl;
        }
    }
    
    //removing "helps"
    myTrie.remove(myStrings[1]);
    std::cout << myStrings[1] << " removed." << std::endl;
    
    //confirming new trie
    for(int i = 0; i < 3; i++){
        if(myTrie.search(myStrings[i])){
            std::cout << myStrings[i] << " exists." << std::endl;
        } else {
            std::cout << myStrings[i] << " doesn't exist." << std::endl;
        }
    }
    
    return 0;
}
