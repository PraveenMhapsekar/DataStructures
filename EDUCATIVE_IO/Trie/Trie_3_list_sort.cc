#include "Trie.h"
#include <string>
#include <iostream>

using namespace std;

void getWords(Trie *root, vector<string>&result, int level, string &word) 
{
	//Leaf denotes end of a word
	if (root->isEndWord) {
		//current word is stored till the 'level' in the word string
		string temp = "";
		for (int x = 0; x < level; x++) {
			temp += word[x];
		}
		result.push_back(temp);
	}

	for (int i = 0; i < CHAR_SIZE; i++) {
		if (root->children[i] != nullptr) {
			//Non-null child, so add that index to the word string
			word[level] = (char)(i);
			getWords(root->children[i], result, level + 1, word);
		}
	}
}

vector<string> findWords(Trie *root) 
{
	vector<string> result;
	string word = "";
	getWords(root, result, 0, word);
	return result;
}

int
main() {
  string keys[9] = {"the", "a", "there", "answer", "any", "by", "bye", "their","abc"};

  Trie *t = new Trie();
  // Construct trie       
  for (int i = 0; i < 9 ; i++) {
    t->insertNode(keys[i]);
  }

	vector<string> result = findWords(t) ;
  for (int i = 0; i < result.size(); i++) {
     cout << result[i] <<endl; 
  }
  return 0;
}
