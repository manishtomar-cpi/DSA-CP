#include <iostream>
#include <vector>
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

void sorting(vector<int> &vec)
{

    //?Selection Sort
    int smallest;
    for (int i = 0; i < vec.size(); i++)
    {
        smallest = i;
        for (int j = i; j < vec.size(); j++)
        {
            if (vec[j] < vec[smallest])
            {
                smallest = j;
            }
        }
        swap(vec[i], vec[smallest]);
    }

    display(vec);
}

int linearSearch(vector<int> &vec, int element)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == element)
        {
            return i; //if found
            break;
        }
    }

    return -1; //not found
}

int main()
{
    vector<int> vec{6, 8, 3, 5, 1, 9, 7};
    // sorting(vec);
    cout << linearSearch(vec, 11) << endl;

    return 0;
}