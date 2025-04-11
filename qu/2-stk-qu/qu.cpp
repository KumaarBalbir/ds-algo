#include "qu.h"

void Queue::enqueue(int x)
{
  e_st.push(x);
}

bool Queue::isEmpty()
{
  return e_st.empty() && d_st.empty();
}
int Queue::dequeue()
{
  if (d_st.empty())
  {
    while (!e_st.empty())
    {
      d_st.push(e_st.top());
      e_st.pop();
    }
  }
  if (d_st.empty())
  {
    return -1; // Queue is empty
  }
  int x = d_st.top();
  d_st.pop();
  return x;
}