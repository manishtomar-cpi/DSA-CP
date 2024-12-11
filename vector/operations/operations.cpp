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
    cout << "]" <<endl;
}

void InsertElementinVector(vector<int> &vec, int element, int position)
{
    vec.push_back(-1);
    for (int i = vec.size()-1; i >= position; --i)
    {
        if (i != position)
        {
           vec[i]=vec[i-1];
        }
        if (i == position)
        {
            vec[i] = element;
            break;
        }
    }
    display(vec);
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    InsertElementinVector(vec, 6,5);
}
