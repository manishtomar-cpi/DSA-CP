#include <iostream>
#include <vector>
using namespace std;

int findInd(vector<int> &vec, int element)
{
    static int index = 0;

    if (vec.size() == 0 || index == vec.size())
    {
        return -1; // not present
    }
    if (index < vec.size())
    {
        if (vec[index] == element)
        {
            return index;
        }
        index++;
    }
    return findInd(vec, element);
}

int main()
{
    vector<int> vec = {1, 2, 2, 3, 3, 4, 56};

    cout << findInd(vec, 2) << endl;

    return 0;
}