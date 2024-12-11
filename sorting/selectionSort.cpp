#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void display(vector<int> &vec)
{
    cout << "[ ";
    for (auto &i : vec)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}

void selectionSort(vector<int> &vec)
{
    int smallest;
    for (int i = 0; i < vec.size(); i++)
    {
        smallest = i; //*index of the smallest one, assume first one in the list is smallest
        for (int j = i; j < vec.size(); j++)
        {
            if (vec[j] < vec[smallest])// if want to sort in des order change < to >
            {
                smallest = j; //?update the index of the smallest one
            }
        }
        swap(vec[i], vec[smallest]); //swap current with smallest - //!if no smallest found current swap with current 
        display(vec);
    }
}

int main()
{
    vector<int> vec = {8,5,10,2,3,11,18,9};

    selectionSort(vec);
    return 0;
}