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
        // Step 1: swapping least and first
        swap(pq[0], pq[pq.size() - 1]);
        // Step 2: removing the last
        int valueGoingOut = pq[pq.size() - 1];
        pq.pop_back();
        cout << valueGoingOut << " removed!" << endl;

        // Step 3: Heapify dowm (Bubble down)
        cout << "Heapify down..." << endl;
        int parent = 0;
        int parentLeft = (2 * parent) + 1;
        int parentRight = (2 * parent) + 2;
        
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

    p1.insert(6);
    p1.insert(5);

    p1.printHeap();
    return 0;
}