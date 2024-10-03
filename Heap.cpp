#include "Heap.h"
#include "PrintJob.h"


/*Initializes an empty heap.*/
Heap::Heap() { this->numItems = 0; } // Done

/*Inserts a PrintJob to the heap without
violating max-heap properties.*/
void Heap::enqueue(PrintJob* node)
{
    if(numItems < MAX_HEAP_SIZE && numItems >= 0)
    {
        arr[numItems] = node;
        trickleUp(numItems);
        numItems = numItems + 1;
    }
}

/*Removes the node with highest priority from the heap.
Follow the algorithm on priority-queue slides. */
void Heap::dequeue()
{
    if(numItems >= 0)
    {
        if(numItems > 1)
        {
            std::swap(arr[0], arr[numItems - 1]);
            delete arr[numItems - 1];
            numItems = numItems - 1;
            trickleDown(0);
        }
        else if(numItems == 1)
        {
            delete arr[0];
            numItems = numItems - 1;
        }
    }
}

/*Returns the node with highest priority.*/
PrintJob* Heap::highest()
{
    if(numItems > 0) { return arr[0]; }
    else return nullptr;
}

/*Prints the PrintJob with highest priority in the following format:
Priority: priority, Job Number: jobNum, Number of Pages: numPages
(Add a new line at the end.)*/
void Heap::print() 
{
    if(numItems > 0)
    {
        for(int i = 0; i < 1; i = i+1)
        {
            cout << "Priority: " << arr[i] -> getPriority() << ", Job Number: " << arr[i] -> getJobNumber() << ", Number of Pages: " << arr[i] -> getPages() << endl;
        }
    }
}

/*This function is called by dequeue function
to move the new root down the heap to the
appropriare location.*/
void Heap::trickleDown(int curIndex)
{
    int childIndex = 2 * curIndex + 1;
    int value = arr[curIndex]->getPriority();
    while(childIndex < numItems)
    {
        int maxValue = value;
        int maxIndex = -1;
        for(int i = 0; (i < 2) && (i + childIndex < numItems); ++i)
        {
            if(arr[i + childIndex]->getPriority() > maxValue)
            {
                maxValue = arr[i + childIndex]->getPriority();
                maxIndex = i + childIndex;
            }
        }
        if(maxValue == value) { break; }
        else
        {
            if(maxIndex >= 0 && maxIndex < numItems){
                std::swap(arr[curIndex], arr[maxIndex]);
                curIndex = maxIndex;
                childIndex = 2 * curIndex + 1;
            }
        }
    }
}

/*This function is called by the enqueue function to move the new node up to the appropriate location*/
void Heap::trickleUp(int curIndex)
{
    while(curIndex > 0)
    {
        int parentIndex = (curIndex - 1) / 2;
        if(arr[curIndex]->getPriority() <= arr[parentIndex]->getPriority()) { curIndex = 0;}
        else
        {
            PrintJob* node = arr[curIndex];
            arr[curIndex] = arr[parentIndex];
            arr[parentIndex] = node;
            curIndex = parentIndex;
        }
    }
}
