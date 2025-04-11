#include "qu.h"

void Queue::enqueue(int x)
{
  e_st.push(x);
}

bool Queue::isEmpty()
{
  return e_st.empty() && d_st.empty();
}