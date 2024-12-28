#include <iostream>
#include <vector>
using namespace std;

int majorityEle(vector<int> &vec)
{ // in this algo we assume that first element is majority element and we compare all with majority if equal to majority we increase the count if not dec the count if count is equal to zero then then change the candidate
    int candidate = vec[0];
    int count = 1;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] == candidate)
        {
            count++; //*if match
        }
        else
        {

            count--; //*if not match 
            if (count == 0) //*means occ of that element is lesser then anyone else so the candidate should change
            {
                candidate = vec[i];
                count = 1;
            }
        }
    }

    return candidate;
}

int main()
{
    vector<int> vec = {3,2,3};

    cout << majorityEle(vec) << endl;

    return 0;
}