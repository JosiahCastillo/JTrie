# JTrie
A custom Implementation of the Trie data structure.

In this implementation of the Trie data structure I am trying to achieve the base functionality of a trie while reaching a comfortable middle ground between memory usage and time complexity.

To use this, just download the JTrie.h and JTrie.cpp files and #include JTrie.h in the header of whatever program you're using.

So far this Trie has the very basic functionality of a Trie and is only able to accept alphabets (no numbers ofr special characters). I plan to update this somewhere down the line so it can support other inputs and functionalities.

Below I have provided a bit of information from a blog post I made about the Trie data structure to give a bit of insight on the functionality of Tries. Feel free to look around in the source files as well.

Insertion and Deletion
In a Trie, insertion and deletion have an edge in performance because they do not have to make any computations, balances, or handle collisions. To understand why we'll take a look at a small example. ![Trie Example](https://user-images.githubusercontent.com/47875741/113561373-17ca5300-95ca-11eb-8c22-8cf63150cdaa.png)
Blue indicates ending of a complete word. Red is the opposite. In the Trie above, the words "Hello", "Helps", and "Hand" have been inserted. Each character in a Trie has its own node, and all nodes have max number of children depending on the kind of input the Trie will be receiving. In this example, upper-case letters are the input so each node has a max of 26 children. If inputs were codes that included a wider range of alpha numeric values this would change. Tries place a heavy emphasis on the reuse of nodes to hold multiple entries ("H-E-L" both hold "HELLO" and "HELPS"). This basically removes the need for balancing and collision handling entirely. This also means that when inserting, it is important to be able to trace and reuse existing nodes while being able to branch off whenever the sequence of characters change, otherwise this will use a heavy amount of space in a program. Deletion on the other hand needs to be able to recognize when to remove a node in its entirety or to simply remove a child otherwise entire subsets of words could be unintentionally deleted. Lets take a look at what happens when we delete the word "HELPS" from the Trie and insert the word "He".
![Trie Example Post Delete and Insert](https://user-images.githubusercontent.com/47875741/113561386-1ef16100-95ca-11eb-84be-3b2a774067d9.png)
Unshared nodes for HELPS have been deleted and the node for HE was changed. When the delete operator is called on the Trie, the Trie is traversed until it reaches the end of the input it was given. At this point it will check to see if the node is considered a complete word. In the images used, blue indicates a node is flagged as a complete word, while red is the opposite. If it is a complete word, the program will iterate backwards and delete all unique nodes (nodes with no other children) until it reaches the root of the Trie. During the deletion of "HELPS", only the unique nodes "P-S" were deleted from the Trie. If one were to search for the word afterwards, the search would end at the first "L" and return false. When the insert operator is called on a Trie, the program will search for every individual character in the word until the end of the word is reached. If the character being checked for doesn't exist in the Trie, it will simply insert a new node wherever the branch is. At the end of this process the final node in the sequence will be flagged as a complete word. In this example, since "HE" already exists within the Trie, no new nodes were required and the final node in "HE" was simply changed to indicate it now exists within the Trie. For searching a Trie the program only needs to traverse the tree until the word is found and return the flag associated with the final node, however if the end of the word cant be reached, it doesn't exist so search should naturally return false.
