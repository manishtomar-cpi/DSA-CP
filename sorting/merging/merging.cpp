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

void merging(vector<int> &vec1, vector<int> &vec2)
{
    vector<int> merged(vec1.size() + vec2.size());

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < vec1.size() && j < vec2.size()) // only run when both less then size if any one exced it will terminated
    //!  if we use || insted of && -> This condition means the loop continues as long as at least one of the conditions is true, The loop terminates only when both conditions are false. While means jab tk chale jab tk (yeah)  ho.
    {
        if (vec1[i] < vec2[j])
        {
            merged[k++] = vec1[i++]; // post increment means first insert i current state and then increment
        }
        else
        {
            merged[k++] = vec2[j++];
        }
    }

    // fill from first if remaining
    while (i < vec1.size())
    {
        merged[k++] = vec1[i++];
    }
    // same for second vector
    while (j < vec2.size())
    {
        merged[k++] = vec2[j++];
    }

    display(merged);
}

void mergingSingleArray(vector<int> &vec)
{
    vector<int> merged(vec.size());
    int low = 0;
    int high = vec.size() - 1;
    int mid = high / 2;
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (vec[i] < vec[j])
        {
            merged[k++] = vec[i++];
        }
        else
        {
            merged[k++] = vec[j++];
        }
    }
    while (i <= mid)
    {
        merged[k++] = vec[i++];
    }
    while (j <= high)
    {
        merged[k++] = vec[j++];
    }

    display(merged);
}
int main()
{
    // vector<int> vec1 = {1, 3, 4, 5, 6, 7, 8, 8};
    // vector<int> vec2 = {2, 4, 5};

    // merging(vec1, vec2);
    vector<int> vec = {1, 2, 5, 7, 8, 3, 6, 9, 10, 11};
    mergingSingleArray(vec);

    return 0;
}
