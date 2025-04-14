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

trieNode::~trieNode()
{
  for (int i = 0; i < 26; i++)
  {
    if (children[i] != nullptr)
    {
      delete children[i];
    }
  }
}

void trieNode::setPriority(int p)
{
  priority = p;
}

int trieNode::getPriority()
{
  return priority;
}
Trie::Trie()
{
  root = new trieNode();
}

Trie::~Trie()
{
  delete root;
}

#endif // TRIE_CPP