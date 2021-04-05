#include <iostream>
#include <vector>
#include "JTrie.h"

int getKey(int input){
    std::cout << "Input: " << input << std::endl << "Output: ";
    return 'q';
}

int main(){
    std::cout << isalpha('a') << std::endl << isalpha ('A') << std::endl << isalpha(0) << std::endl << isalpha('1') << std::endl;
    std::vector<int> myvector = {10,20,30};
    for(int i = 0; i < myvector.size(); i++){
        std::cout << myvector[i] << std::endl;
    }

    auto it = myvector.insert(myvector.begin() + 1, 40);

    for(int i = 0; i < myvector.size(); i++){
        std::cout << myvector[i] << std::endl;
    }

    if ('e' % 97 > myvector.size()){
        std::cout << "HI" << std::endl;
    }

    std::cout << getKey('x') << std::endl;

    std::string mystring = "greetings";
    for(int i = 0; i < 5; i++){
        std::cout << mystring[i] << std::endl;
    }

    JTrie myTrie;
    myTrie.insert(mystring);

    mystring = "greet";

    myTrie.insert(mystring);

    mystring = "great";

    myTrie.insert(mystring);

    mystring = "greatness";

    myTrie.insert(mystring);

    mystring = "grateful";

    myTrie.insert(mystring);

    mystring = "great";

    std::cout << myTrie.search(mystring) << std::endl;

    std::cout << "remove called" << std::endl;
    myTrie.remove(mystring);
    std::cout << "remove finished" << std::endl;


    std::cout << myTrie.search(mystring) << std::endl;

    mystring = "greatness";
    std::cout << myTrie.search(mystring) << std::endl;
    return 0;
}
