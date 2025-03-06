#include <iostream>
#include <vector>
using namespace std;

// According to min heap -> MIN PQ
class PriorityQueue
{
private:
    vector<int> pq; // so we will use vector as heap beause we studid the relations  of node and parents so directly without making any heap or tree we can use all functions from array

public:
    bool isEmpty()
    {
        return pq.size() == 0 ? true : false; // totally depemds upon the size of array/heap
    }
    int getSize()
    { // total size of the pq
        return pq.size() == 0 ? -1 : pq.size();
    }
    int minElement()
    {
        return pq.size() == 0 ? -1 : pq[0]; // because in the min heap the minimum element is on the first index
    }

    void insert(int val)
    {
        // Step 1: Insert the value at the last position
        pq.push_back(val);
        cout << val << " added in heap!" << endl;

        // Step 2: Perform Heapify Up (Bubble Up)
        /*
        storing parent according to furmula (i-1)/2 -> i is the position to add assuem we are addign 3rd element the size is 2 so acc of formula
        2-1/2 means 1/2 means '0' is the parent of that node which we are adding, now we will compare accordingly to do heapiffy.
        */
        int lastAddedAt = pq.size() - 1;
        int parent = (lastAddedAt - 1) / 2;
        while (lastAddedAt > 0 && pq[parent] > pq[lastAddedAt])
        { //?condition->because otherwie we will reach at root or the position we find the balancing according to the min heap

            swap(pq[parent], pq[lastAddedAt]);

            // now calculating new parent and index added at
            lastAddedAt = parent;
            parent = (lastAddedAt - 1) / 2;
        }
    }

    void removeMin()
    {
        if (pq.empty())
        {
            return;
        }
        // Step 1: swapping least and first
        swap(pq[0], pq[pq.size() - 1]);
        // Step 2: removing the last
        int valueGoingOut = pq[pq.size() - 1];
        pq.pop_back();
        cout << valueGoingOut << " removed!" << endl;

        // Step 3: Heapify dowm (Bubble down)
        cout << "Heapify down..." << endl;
        int parent = 0; // starting from first
        while (true)
        {
            int leftChild = (2 * parent) + 1;
            int rightChild = (2 * parent) + 2;
            int smallestIndex = parent; // we are assuming the parent is smallest
            if (leftChild < pq.size() && pq[leftChild] < pq[smallestIndex])
            {
                // here we are checking id the left child exist or not if yes compering the smallest at this step smallest is parent
                smallestIndex = leftChild;
            }
            if (rightChild < pq.size() && pq[rightChild] < pq[smallestIndex])
            {
                // we are doing same as above just difference is now the smalles index is the left one in above if condition is true, and we are checking form the smalles from them
                smallestIndex = rightChild;
            }
            // termination condition
            if (smallestIndex == parent)
            {
                // this is only when the above both if conditions not executed
                break;
            }
            //now swaping
            swap(pq[parent], pq[smallestIndex]);
            //and the parent is now became the new smallest
            parent = smallestIndex;
        }
        /*
        *THIS IS ALSO CALLED HEAP SORT,  //?If we execute remove min till the pq became empty then we will get the removed element in sorted manner
        STEP1: add the elements in the MIN_HEAP
        STEP2: remove the smallest each time 
        TIME: Nlog(N)
        SPACE: N, because we took the extra array to store element in PQ to enhance the sorted logic
        */
    }
    void printHeap()
    {
        cout << "Heap: ";
        for (int num : pq)
            cout << num << " ";
        cout << endl;
    }
};

int main()
{
    PriorityQueue p1;

    p1.insert(100);
    p1.insert(10);
    p1.insert(15);
    p1.insert(4);
    p1.insert(17);
    p1.insert(21);
    p1.insert(67);
    p1.removeMin();
    p1.printHeap();
    return 0;
}