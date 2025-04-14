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

void Trie::insert(const std::string &word, int priority)
{
  trieNode *current = root;
  int idx;
  for (char ch : word)
  {
    idx = ch - 'a';
    if (current->children[idx] == nullptr) // first time, char ch is on this level of tree.
    {
      current->children[idx] = new trieNode();
    }
    current = current->children[idx];
  }
  current->isEndOfWord = true;
  current->setPriority(priority);
}

#endif // TRIE_CPP