#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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
vector<int> func(vector<int> &nums, int k)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++;
    }
    vector<int> keys;
    vector<int> values;
    for (auto &i : hash)
    {
        keys.push_back(i.first);
        values.push_back(i.second);
    }
    cout << "keys" << endl;
    display(keys);
    cout << "values" << endl;
    display(values);
    nums.clear();
    // int gr, pos =0;
    // for(int i = 0; i < values.size(); i++){
    //     gr = values.at(i);
    //     pos=i;
    //     for(int j = 0; j< values.size();j++){

    //         if(values.at(j)>gr){
    //             gr = values.at(j);
    //             pos=j;
    //         }
    //     }
    //     nums.push_back(keys.at(pos));
    //     if(nums.size()>=k){
    //         break;
    //     }
    //     values.at(pos)=-100;
    // }

    //! o(N)
    int i =0;
    int j =0;
    int pos =0;
    int gr =values.at(j);
    while(i<values.size()){
        if(j< values.size()){
            if(values.at(j)>gr){
                gr = values.at(j);
                pos = j;
            }

        }
        if(j == values.size()-1){
            nums.push_back(keys.at(pos));
            if(nums.size()>=k){
                break;
            }
            values.at(pos)=-1;
            j=0;
            i++;
            pos=j;
            gr= values.at(pos);
            continue;
        }
        j++;
    }
    cout << "final" << endl;
    display(nums);
}

int main()
{
    vector<int> vec = {1,1,1,2,2,3};
    int k = 2;
    func(vec, k);

    return 0;
}