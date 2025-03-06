#include "stack.cpp"

int main()
{
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
  Stack s;
  for (int i = 0; i < 8; i++)
  {
    s.push(arr[i]);
  }
  std::cout << s.peek() << std::endl;
  return 0;
}