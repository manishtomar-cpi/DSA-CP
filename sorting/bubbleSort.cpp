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

void bubbleSort(vector<int> &vec)
{ 
    for (int i = 1; i <= vec.size() - 1; i++)//because we seen in worst case we have to do n-1 iterations thats why start from 1 and ends at size-1
    {
        for (int j = 0; j <= vec.size()-2; j++)
        {
            if(vec[j+1]<vec[j]){
                swap(vec[j+1],vec[j]);
                display(vec);
            }
        }
        // display(vec);
    }
}
int main (){
    vector<int> vec ={4,3,2,1,1,1,9,7,-9};
    bubbleSort(vec);

    return 0;
}