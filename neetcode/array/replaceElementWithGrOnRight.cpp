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

vector<int> func(vector<int> &arr)
{

vector<int> res(0,arr.size());

    // BF

        //     for (int i =0; i<arr.size()-1;i++){
    //         int greatest= arr.at(i+1);
    //         for (int j = i+1 ; j<arr.size();j++){
    //             if(arr.at(j)> greatest){
    //                 greatest = arr.at(j);
    //             }
    //         }
    //         res.push_back(greatest);
    //     }
    // res.push_back(-1);
    // display(res);
    //     return res;

//TWO POINTER
if(arr.size()==1){
    res.push_back(-1);
    return res;
}
    int i = 0;
    int j = 1;
    int gr = arr.at(j);
    while (i < arr.size() - 1)
    {
        if (j == arr.size() - 1)
        {
            if (arr.at(j) > gr)
        {
            gr = arr.at(j);
        }
            res.push_back(gr);
            i++;
            if(i==arr.size()-1){
                break;
            }
            j = i + 1;
            gr = arr.at(j);
            continue;
        }
        if (arr.at(j) > gr)
        {
            gr = arr.at(j);
        }

        j++;
    }
    res.push_back(-1);
    display(res);
    return res;

//REVERSE ITRETING

}

int main()
{
    vector<int> vec = {57010,40840,69871,14425,70605};

    func(vec);
}