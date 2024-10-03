#ifndef __HEAP_H
#define __HEAP_H

#include "PrintJob.h"

const int MAX_HEAP_SIZE = 10;

class Heap {
private:
  // The array of PrintJob classes with size MAX_HEAP_SIZE
  PrintJob* arr[MAX_HEAP_SIZE];
  
  //current number of items in heap
  int numItems;

public:
  /*Initializes an empty heap.*/
  Heap();
  /*Inserts a PrintJob to the heap without
  violating max-heap properties.*/
  void enqueue(PrintJob* node);

  /*Removes the node with highest priority from the heap. */
  void dequeue();

  // Returns the highest priority node in the Max Heap
  PrintJob* highest();
    
  // Prints the highest priority node
  void print();

private:
  /*This function is called by dequeue function
  to move the new root down the heap to the
  appropriare location.*/
   void trickleDown(int curIndex);
    
  /*This function is called by the enqueue function to move the new node up to the appropriate location*/
   void trickleUp(int curIndex);
};
#endif
