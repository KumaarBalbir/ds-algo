#include "hep.h"

void max_heapify(int arr[], int idx, int N)
{
  int largest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < N && arr[left] > arr[largest])
    largest = left;

  if (right < N && arr[right] > arr[largest])
    largest = right;

  if (largest != idx)
  {
    std::swap(arr[idx], arr[largest]);
    max_heapify(arr, largest, N);
  }
}
void build_max_heap(int arr[])
{
  int N = sizeof(arr) / sizeof(arr[0]);
  for (int i = N / 2 - 1; i >= 0; i--)
    max_heapify(arr, i, N);
}