#include "util.h"
#include <iostream>
#include <vector>

int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}