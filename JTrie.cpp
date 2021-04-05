//
// Created by Josiah Castillo on 3/31/2021.
//

#include "JTrie.h"

//constructor for JTrieNode
JTrieNode::JTrieNode(int keyInput) {
    key = keyInput;
}

//Used to retrieve the key for a child node
int JTrieNode::getKey() {
    return key;
}

//Used to set the key for a child node
void JTrieNode::setKey(int keyInput) {
    key = keyInput;
}

//used to insert a string into the trie character by character
void JTrieNode::insert(std::string input, int depth) {

    //newNode holds the node that will be inserted into data if the node doesnt already exist
    JTrieNode* newNode = new JTrieNode(input[depth]);

    //if the end of the word has been reached
    if(depth >= input.size()){

        //a full word has been inserted. end the call and set isWord to true
        isWord = true;
        return;
    }

    //nodeLoc used to store the value of the current node, possible values being 0 - 25 ( a = 0, z = 25)
    int nodeLoc = input[depth] - 97;

    //if data is empty
    if(data.size() == 0){

        //insert the new node at the end of data
        data.push_back(newNode);

        //call insert for the new node so it continues to insert the rest of the characters. depth is incremented as we go one level deeper into the tree
        data[data.size() - 1]->insert(input, depth + 1);

        //if there is a child at location nodeLoc (nodeLoc < data.Size)
    } else if(nodeLoc < data.size()){

        //and the key of this child is equal to the current character (0 = 'a')
        if(data[nodeLoc]->getKey() == input[depth]){

            //call insert for this child without creating a new node. depth is incremented as we go one level deeper into the tree
            data[nodeLoc]->insert(input, depth + 1);

            //if the key is not equal to the current character
        } else {

            //insert the new node at the nodeLoc. EX: if nodeLoc is 0 (current character is a), then the new node will be inserted at 0 while everything else is pushed back
            auto it = data.insert(data.begin() + nodeLoc, newNode);

            //call insert for the new node so it continues to insert the rest of the characters. depth is incremented as we go one level deeper into the tree
            data[nodeLoc]->insert(input, depth + 1);
        }

        //if there is not a child at location nodeLoc (nodeLoc >= data.size())
    } else {

        //check currently existing values starting from the end of the vector (the correct position is likely near the end)
        for(int i = data.size(); i > 0; i--){

            //if the key at i - 1 is less than the current character
            if (data[i - 1]->getKey() < input[depth]){

                //insert the new node at the i - 1, its correct sorted position
                auto it = data.insert(data.begin() + i - 1, newNode);

                //call insert at index i - 1 to continue entering further characters
                data[i - 1]->insert(input, depth + 1);
                break;

                //if the key at i - 1 is a duplicate of the current character
            } else if (data[i - 1]->getKey() == input[depth]){

                //call insert at index i - 1 to continue entering further characters
                data[i - 1]->insert(input, depth + 1);
                break;

            }
        }

    }

}

//used to check if values currently exist in the trie
bool JTrieNode::search(std::string input, int depth) {
    //if the end of the word has been reached
    if(depth >= input.size()){

        //return isWord (set during insert)
        return isWord;
    }

    //nodeLoc used to store the value of the current node, possible values being 0 - 25 ( a = 0, z = 25)
    int nodeLoc = input[depth] - 97;

    if(data.size() == 0){
        return isWord;
    } else if (nodeLoc < data.size()){
            if (data[nodeLoc]->getKey() == input[depth]) {
                return data[nodeLoc]->search(input, depth + 1);
            } else {
                return false;
            }
    } else {
        for(int i = data.size() - 1; i >= 0; i--){
            if(data[i]->getKey() == input[depth]){
                return data[i]->search(input, depth + 1);
            }
        }
    }

    return false;
}

//used to remove words from the trie
int JTrieNode::remove(std::string input, int depth) {
    //if the end of the word has been reached
    if(depth >= input.size()){
        std::cout << "End of word reached at size: " << data.size() << std::endl;
        //set isWord to false
        isWord = false;

        //return data size
        return data.size();
    }

    //if the current data size is 0
    if(data.size() == 0){
        std::cout << "Data Size at: " << input[depth] << " is: " << data.size() << std::endl;

        //return data size
        return data.size();

        //otherwise if the node exists within the range of data
    } else {
        std::cout << "Data Size at: " << input[depth] << " is: " << data.size() << std::endl;
        for (int i = 0; i < data.size(); i++) {

            //if the value at i is equal to the value being searched
            if (data[i]->getKey() == input[depth]) {
                std::cout << data[i]->getKey() << " is equivalent to: " << input[depth] << std::endl;

                //if data size at the node is 0
                if (data[i]->remove(input, depth + 1) == 0) {
                    std::cout << data[i]->getKey() << " has no children" << std::endl;

                    //delete the node
                    delete data[i];

                    std::cout << "pointer deleted, current value is: " << input[depth] << std::endl;

                    //remove the new node at i, its correct sorted position
                    auto it = data.erase(data.begin() + i);

                    //return the new data size
                    return data.size();

                } else {
                    std::cout << data[i]->getKey() << " has children" << std::endl;
                    return data.size();
                }
            }
        }
    }
}

//constructor for JTrie
JTrie::JTrie(){
    root = new JTrieNode(' ');
}

//Used to insert strings into the trie
void JTrie::insert(std::string input) {
    root->insert(input, 0);
}

bool JTrie::search(std::string input) {
    return root->search(input, 0);
}

void JTrie::remove(std::string input) {
    root->remove(input, 0);
}






