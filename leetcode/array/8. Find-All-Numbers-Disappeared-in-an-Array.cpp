#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> findDissappear(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    vector<int> final;
    vector<int>hash(nums.size(), 0) ;

    for(int i =0; i<nums.size(); i++){
        hash.at(nums.at(i)-1)+=1;
    }

    vector<int>final;

    for(auto i =0; i< nums.size();i++){
        if(hash.at(i)==0){
            final.push_back(i+1);
        }
    }
    for(auto i : final){
        cout << i << " ";
    }

    cout << endl;

    // if (nums.size() == 2)
    // {
    //     if (nums.at(0) == nums.at(1))
    //     {
    //         final.push_back(2);
    //         return final;
    //     }
    // }

    //     int i = 0;

    //     while (i < nums.size() - 1)
    //     {
    //         if (nums.at(i + 1) == nums.at(i))
    //         {
    //             i++;
    //             continue;
    //         }
    //         if (nums.at(i+1)==nums.at(i)+1){
    //             i++;
    //         }
    //         else{
    //             nums.at(i+1)= nums.at(i+1);
    //             final.push_back(i);
    //             nums.push_back(i);
    //             i++;
    //             nums.size();
    //         }
    //     }
    
    // if(nums.at(nums.size()-1)!= nums.size());
    // final.push_back(nums.size());

    // for(int i =0; i<final.size() ; i++){
    //     cout << final[i] << " ";  
    // }
    // cout << endl;

    // return final;
}

int main()
{
    vector<int> vec = {4, 3, 2, 7, 8, 2, 3, 1};

    findDissappear(vec);

    return 0;
}