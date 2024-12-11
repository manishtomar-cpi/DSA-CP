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
    int pos = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        smallest = vec[i];
        pos=0;
        for (int j = i; j < vec.size(); j++)
        {
            if (vec[j] < smallest)// if want to sort in des order change < to >
            {
                smallest = vec[j];
                pos = j;
            }
        }
        if(smallest<vec[i]){
        swap(vec[i], vec[pos]);
        }
        display(vec);
    }
}

int main()
{
    vector<int> vec = {8,5,10,2,3,11,18,9};

    selectionSort(vec);
    return 0;
}