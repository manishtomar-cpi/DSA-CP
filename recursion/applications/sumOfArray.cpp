#include <iostream>
#include <vector>
using namespace std;

int sumOfArray(vector<int> &vec)
{
    static int sum = 0;
    if (vec.size() == 0)
    {
        return 0;
    }
    if (vec.size() == 1)
    {
        return sum += vec[0];
    }
    if (vec.size() > 1)
    {
        sum += vec[vec.size() - 1];
        vec.pop_back(); 
        sumOfArray(vec);
    }
}

int sumOfArray2(int ar[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    return sumOfArray2(ar, size - 1) + ar[size - 1];
}

int main()
{
    vector<int> vec = {1, 6, 3, 7, 2, 8};

    // cout << sumOfArray(vec) << endl;
    int size = 7;
    int ar[size] = {1, 4, 5, 6, 7, 8, 9};
    cout << sumOfArray2(ar, size);
    return 0;
}