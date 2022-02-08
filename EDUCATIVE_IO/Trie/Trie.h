#include <iostream>
#include<bits/stdc++.h>

using namespace std;

#define CHAR_SIZE 256
#if 0
class TrieNode {
  public:
    TrieNode *children[CHAR_SIZE];
    bool isEndWord;
    TrieNode();
    void markAsLeaf();
    void unMarkAsLeaf();
};
#endif
class Trie {
  public:
    //TrieNode *root;

    Trie *children[CHAR_SIZE];
    bool isEndWord;
    // TrieNode();
    void markAsLeaf();
    void unMarkAsLeaf();

  public:
    Trie() {
			this->isEndWord = false;
			for (int i = 0; i < CHAR_SIZE; i++) {
				this->children[i] = nullptr;
			}
    }

    Trie *getRoot() {
      Trie *root;
      root = this;
      return root;
    }

    int getIndex(char t);

    void insertNode(string key) {
      Trie *curr = this;
      for (int i = 0; i < key.length(); i++) {
        if (curr->children[key[i]] == nullptr) {
          curr->children[key[i]] = new Trie();
        }
        curr = curr->children[key[i]];
      }
      curr->isEndWord = true;
    }

    
    bool searchNode(string key) {
      // return false if Trie is empty
			if (this == nullptr) {
				return false;
			}
	 
			Trie* curr = this;
			for (int i = 0; i < key.length(); i++) {
				// next node
				curr = curr->children[key[i]];
				if (curr == nullptr) {
					return false;
				}
			}
	 
			return curr->isEndWord; 
		}

    bool hasNoChildren(Trie * currentNode);
    bool deleteHelper(string key, Trie * currentNode, int length, int level);
    void deleteNode(string key);
};
