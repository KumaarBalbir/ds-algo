#include "trie.cpp"
#include <assert.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  Trie trie;
  trie.insert("apple", 1);
  trie.insert("banana", 2);
  trie.insert("apricot", 3);
  trie.insert("cherry", 3);
  trie.insert("durian", 4);
  trie.insert("kiwi", 9);
  trie.insert("lemon", 10);
  trie.insert("mango", 11);

  // check exact matches
  assert(trie.Contains("apple") == true);
  assert(trie.Contains("app") == false);
  assert(trie.Contains("apricot") == true);
  assert(trie.Contains("banana") == true);
  assert(trie.Contains("cherry") == true);
  assert(trie.Contains("durian") == true);
  assert(trie.Contains("kiwi") == true);
  assert(trie.Contains("lemon") == true);
  assert(trie.Contains("mango") == true);
  assert(trie.Contains("orange") == false);

  // check prefix matches
  assert(trie.prefixExists("app") == true);
  assert(trie.prefixExists("ban") == true);
  assert(trie.prefixExists("lemo") == true);

  // get all words with prefix
  vector<string> result = trie.searchAllWithPrefix("ap");
  puts("Words with prefix 'ap':\n");
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << endl;
  }

  // get highest priority word with prefix
  string highestPriorityWord = trie.searchHighestPriority("ap");
  assert(highestPriorityWord == "apricot");
  cout << highestPriorityWord << endl;
}