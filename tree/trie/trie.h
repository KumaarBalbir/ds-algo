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

  void searchAllWithPrefixHelper(trieNode *node, std::string prefix, std::vector<std::string> &result);
  std::string searchHighestPriorityHelper(trieNode *node, std::string prefix);

public:
  Trie();
  ~Trie();
  void insert(const std::string &word, int priority);
  bool Contains(const std::string &word);
  bool prefixExists(const std::string &prefix);
  std::vector<std::string> searchAllWithPrefix(const std::string &prefix);
  std::string searchHighestPriority(const std::string &prefix);
};

#endif // TRIE_H