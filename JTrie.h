//
// Created by Josiah Castillo on 3/31/2021.
//

#ifndef JTRIE_JTRIE_H
#define JTRIE_JTRIE_H

#include <iostream>
#include <vector>

struct JTrieNode{
public:
    //constructor for JTrieNode
    JTrieNode(int keyInput);

    //Used to retrieve the key for a child node
    int getKey();

    //Used to set the key for a child node
    void setKey(int keyInput);

    //used to insert a string into the trie character by character
    void insert(std::string input, int depth);

    //used to determine if a string exists within the trie
    bool search(std::string input, int depth);

    //used to remove a string from a trie
    int remove(std::string input, int depth);

private:
    //ascii value of the current character
    int key;
    
    //all of the child nodes
    std::vector<JTrieNode*> data;
    
    //determines if this node represents a complete word
    bool isWord = false;
};

class JTrie{
public:
    //constructor for a JTrie
    JTrie();

    //used to insert a string into the trie character by character
    void insert(std::string input);

    //used to determine if a string exists within the trie
    bool search(std::string input);

    //used to remove a string from a trie
    void remove(std::string input);

private:
    //points to the root node of the trie
    JTrieNode* root;

};

#endif //JTRIE_JTRIE_H
