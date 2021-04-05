#include <iostream>
#include <vector>
#include "JTrie.h"

int main(){
    //creates a Trie
    JTrie myTrie;
    std::string mystring = "hello";
    
    //inserting hello
    myTrie.insert(mystring);

    mystring = "hand";

    //inserting hand
    myTrie.insert(mystring);

    mystring = "helps";

    //inserting helps
    myTrie.insert(mystring);
    
    
    std::cout << myTrie.search(mystring) << std::endl;

    std::cout << "remove called" << std::endl;
    myTrie.remove(mystring);
    std::cout << "remove finished" << std::endl;


    std::cout << myTrie.search(mystring) << std::endl;

    mystring = "greatness";
    std::cout << myTrie.search(mystring) << std::endl;
    return 0;
}
