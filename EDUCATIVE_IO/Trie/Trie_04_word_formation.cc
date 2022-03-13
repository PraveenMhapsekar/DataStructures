// find whether a given word can be formed by combining two words from a vector.

#include "Trie.h"
#include <string>
#include <iostream>

using namespace std;

bool 
isFormationPossible(Trie *t, string word) {
	Trie *currentNode = t;
  
  for (int i = 0; i < word.size(); i++) {
    char index = word[i];
    if (currentNode->children[index] == NULL) {
      // If the prefix of word does not exist, word would not either
      return false;
    } else if ((currentNode->children[index]->isEndWord == true) && 
               (t->searchNode(word.substr(i+1)) == true)) {
      // If the substring of the word exists as a word in trie,
      // Check whether rest of the word also exists, if it does return true
      return true;
    }
    currentNode = currentNode->children[index];
  }

  return false;
}

int
main() {
  //string keys[9] = {"the", "a", "there", "answer", "any", "by", "bye", "their","abc"};

  string keys[9] = {"apple", "pear", "pier", "pie"};
  //string keys[9] = {"the", "a", "there", "answer", "any", "by", "bye", "their","abc"};

  Trie *t = new Trie();
  // Construct trie       
  for (int i = 0; i < 9; i++) {
    t->insertNode(keys[i]);
  }

  string word = "applepie";
  string result = " ";
  if (isFormationPossible(t, word) == true) {
    result = "true";
  } else {
    result = "false";
  }

  cout << word << " is possible : " << result << endl;
  return 0;
}
