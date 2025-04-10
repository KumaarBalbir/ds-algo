#include "dqu.cpp"

using namespace std;

int main()
{
  DEQueue dq(5);
  dq.insertFront(1);
  dq.insertFront(2);
  dq.insertRear(3);
  dq.insertRear(4);
  dq.insertRear(5);
  dq.display();
  cout << dq.deleteFront() << endl;
  dq.display();
  cout << dq.deleteRear() << endl;
  dq.display();
  return 0;
}