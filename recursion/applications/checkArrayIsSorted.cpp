#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> &vec)
{
    if (vec.size() == 0 || vec.size() == 1)
    {
        return true;
    }

    else
    {
        if (vec[vec.size() - 2] < vec[vec.size() - 1])
        {
            vec.pop_back();
            return isSorted(vec);
        }
    }
    return false;
}

int main()
{
    vector<int> vec = {1, 5, 7, 9, 11, 13, 15, 19, 21};

    cout << boolalpha;
    cout << isSorted(vec);

    return 0;
}