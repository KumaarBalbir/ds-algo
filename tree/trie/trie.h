// full class oriented implementation of Trie data structure
// methods supported: 1. insert, 2. search (exact search) returns boolean, 3. search all strings with prefix, returns vector of strings 4. return a single string with prefix and highest priority (on tie, return lexicographically smallest) 5. delete a string
// Author: Balbir
// License: MIT
//
#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>

struct trieNode
{
  struct trieNode *children[26];
  bool isEndOfWord;
  int priority;
  trieNode();
  ~trieNode();
  void setPriority(int p);
  int getPriority();
};
class Trie
{
private:
  trieNode *root;
  void insertHelper(trieNode *root, const std::string &word, int priority);
  bool searchHelper(trieNode *root, const std::string &word);
  std::vector<std::string> searchAllHelper(trieNode *root, const std::string &prefix);
  std::string searchHighestPriorityHelper(trieNode *root, const std::string &prefix);
  void deleteHelper(trieNode *root, const std::string &word);

public:
  Trie();
  ~Trie();
  void insert(const std::string &word, int priority);
  bool search(const std::string &word);
  std::vector<std::string> searchAll(const std::string &prefix);

  std::string searchHighestPriority(const std::string &prefix);
  void deleteWord(const std::string &word);
};

#endif // TRIE_H