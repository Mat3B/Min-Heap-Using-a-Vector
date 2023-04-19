// Name: Mathew Breland
// Assignment: Min Heap Using a Vector
// Date: 4/10/2023
// Class: Algorithms and Data Structures 

#include "minHeap.h"

#include <iostream>
#include <vector>

using namespace std;

void minHeap::siftUp(int pos)
{
    // Keep swapping the node with its parent until it is not less than its parent
    while (pos > 0 && heap[pos] < heap[(pos - 1) / 2]) {

        swap(heap[pos], heap[(pos - 1) / 2]); // swapping the position with the (position - 1) / 2

        pos = (pos - 1) / 2;    // setting pos equal to pos - 1 divided by 2 
    }
}

void minHeap::siftDown(int pos)
{

    // setting n equal to the size of the heap
    int n = heap.size();

    // keep swapping the node with its smallest child until it is not greater than its children
    while (2 * pos + 1 < n) {

        int smallestChild = 2 * pos + 1;    // smallest child variable that is 2 * the position + 1

        if (2 * pos + 2 < n && heap[2 * pos + 2] < heap[smallestChild]) {

            smallestChild = 2 * pos + 2;
        }

        if (heap[pos] > heap[smallestChild]) {

            swap(heap[pos], heap[smallestChild]);

            pos = smallestChild;
        }

        // if nothign meets the requirements then just break 
        else {
            break;
        }
    }
}


minHeap::minHeap(vector<int> data)
{
    heap = data;            // copy data into heap
    int n = heap.size();    // setting intger n to the size of the heap 

    // start at the parent of the last node
    // and sift down each node to maintain the heap property
    for (int i = (n / 2) - 1; i >= 0; i--) {

        siftDown(i);
    }
}


void minHeap::insert(int value)
{
    // add new value to the end of the heap
    heap.push_back(value);

    // sift up the new value to maintain the heap property
    siftUp(heap.size() - 1);

}

int minHeap::removeMin()
{
    if (heap.empty()) {
        throw logic_error("Heap is empty"); // throwin a logic error, idk if we have to do this but it it generally good practice
    }

    // save the minimum value at the root of the heap
    int minimumVal = heap[0];

    // replace the root with the last value in the heap
    heap[0] = heap.back();
    heap.pop_back();

    // sift down the new root to maintain the heap property
    siftDown(0);

    // return the minimal value 
    return minimumVal;
}
