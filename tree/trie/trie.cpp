#ifndef TRIE_CPP
#define TRIE_CPP

#include "trie.h"
#include <iostream>

trieNode::trieNode()
{
  for (int i = 0; i < 26; i++)
  {
    children[i] = nullptr;
  }
  isEndOfWord = false;
  priority = -1; // default priority which means word is not complete.
}

#endif // TRIE_CPP