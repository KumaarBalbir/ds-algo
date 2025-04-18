#include "util.h"
#include <iostream>
#include <vector>

int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int lcm(int a, int b)
{
  return (a * b) / gcd(a, b);
}
std::string decimalToBinary(int n)
{
  std::string binary = "";
  while (n > 0)
  {
    binary += std::to_string(n % 2);
    n >>= 1;
  }
  return std::string(binary.rbegin(), binary.rend());
}