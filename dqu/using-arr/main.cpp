#include "dqu.cpp"
using namespace std;
int main()
{
  DEQueue dq(5);
  dq.insertFront(1);
  dq.insertFront(2);
  dq.insertFront(3);
  dq.insertRear(6);
  dq.insertRear(7);
  dq.insertFront(8); // dq is full
  dq.display();
  dq.deleteFront();
  dq.deleteFront();
  dq.deleteRear();
  dq.display();
}