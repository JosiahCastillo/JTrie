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

    bool search(std::string input, int depth);

    int remove(std::string input, int depth);

private:
    int key;
    std::vector<JTrieNode*> data;
    bool isWord = false;
};

class JTrie{
public:
    JTrie();

    void insert(std::string input);

    bool search(std::string input);

    void remove(std::string input);

private:
    JTrieNode* root;

};

#endif //JTRIE_JTRIE_H
