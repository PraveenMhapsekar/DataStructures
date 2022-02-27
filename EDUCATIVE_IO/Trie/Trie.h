#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define CHAR_SIZE 256

class Trie {
  public:
    Trie *children[CHAR_SIZE];
    bool isEndWord;
    // TrieNode();
    void markLeaf();
    void unMarkLeaf();

  public:
    Trie() {
			this->isEndWord = false;
			for (int i = 0; i < CHAR_SIZE; i++) {
				this->children[i] = nullptr;
			}
    }

    Trie* getRoot() {
      Trie *root;
      root = this;
      return root;
    }

    int getIndex(char t);

    void insertNode(string &key) {
      Trie *cur = this;
      for (int i = 0; i < key.length(); i++) {
        if (cur->children[key[i]] == nullptr) {
          cur->children[key[i]] = new Trie();
        }
        cur = cur->children[key[i]];
      }
      cur->isEndWord = true;
    }

    bool searchNode(string key) {
      // return false if Trie is empty
			if (this == nullptr) {
				return false;
			}
	 
			Trie *cur = this;
			for (int i = 0; i < key.length(); i++) {
				// next node
				cur = cur->children[key[i]];
				if (cur == nullptr) {
					return false;
				}
			}
			return cur->isEndWord; 
		}

    bool hasNoChildren(Trie *curentNode);
    bool deleteHelper(string key, Trie *curentNode, int length, int level);
    void deleteNode(string key);
};
