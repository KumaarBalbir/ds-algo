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

bool Trie::Contains(const std::string &word)
{
  trieNode *current = root;
  int idx;
  for (char ch : word)
  {
    idx = ch - 'a';
    if (current->children[idx] == nullptr) // first time, char ch is on this level of tree.
    {
      return false;
    }
    current = current->children[idx];
  }
  return current->isEndOfWord;
}

bool Trie::prefixExists(const std::string &prefix)
{
  trieNode *current = root;
  int idx;
  for (char ch : prefix)
  {
    idx = ch - 'a';
    if (current->children[idx] == nullptr) // first time, char ch is on this level of tree.
    {
      return false;
    }
    current = current->children[idx];
  }
  return true;
}

void Trie::searchAllWithPrefixHelper(trieNode *current, std::string prefix, std::vector<std::string> &result)
{
  if (current->isEndOfWord)
  {
    result.push_back(prefix);
  }
  for (int i = 0; i < 26; i++)
  {
    if (current->children[i] != nullptr)
    {
      std::string newPrefix = prefix + char(i + 'a');
      searchAllWithPrefixHelper(current->children[i], newPrefix, result);
    }
  }
}

std::vector<std::string> Trie::searchAllWithPrefix(const std::string &prefix)
{
  trieNode *current = root;
  int idx;
  for (char ch : prefix)
  {
    idx = ch - 'a';
    if (current->children[idx] == nullptr) // first time, char ch is on this level of tree.
    {
      return {};
    }
    current = current->children[idx];
  }
  std::vector<std::string> result;
  std::string str = prefix;
  searchAllWithPrefixHelper(current, str, result);
}

#endif // TRIE_CPP