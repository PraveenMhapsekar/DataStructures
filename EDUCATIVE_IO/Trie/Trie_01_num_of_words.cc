#include "Trie.h"

int
totalWords(Trie *root){
  int result = 0;

  // Base case
  // Leaf denotes end of a word
  // Basically count the number of leaf in recursibe manner
  if (root->isEndWord) {
     result++;
  }

  for (int i = 0; i < CHAR_SIZE; i++) {
    if (root->children[i] != nullptr)
      result += totalWords(root->children[i]);
  }

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

  cout << "total Words " << totalWords(t->getRoot()) << endl;
  return 0;
}
