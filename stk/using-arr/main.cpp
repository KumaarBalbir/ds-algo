#include "stack.cpp"

int main()
{

  Stack s(10);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(8);
  s.push(9);
  s.push(10);
  std::cout << s.peek() << "\n";
  s.pop();
  std::cout << s.peek();
}