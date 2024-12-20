#include <iostream>
#include <string>
#include <vector>
using namespace std;

void display(vector<string> &str)
{
    cout << "[ ";
    for (auto &i : str)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}

void printPer(char str[], int i = 0)
{
    if (str[i] == '\0')
    {
        cout << str << endl;
        return;
    }
    for (int j = 0; str[j] != '\0'; j++)
    {
        swap(str[i], str[j]);
        printPer(str, i + 1);
        swap(str[i], str[j]);
    }
}

void printPermutations(string str)
{
    vector<string> per;
    for (int i = 0; i < str.size(); i++)
    {
        string permutation;
        for (int j = 0; j < str.size(); j++)
        {
            if (j == i) //AAB is not the permutation
            {
                continue;
            }
            for (int k = 0; k < str.size(); k++)
            {
                if (k == i || k == j) //because AAA is not permutation 
                {
                    continue;
                }
                permutation = permutation + str[i] + str[j] + str[k];
                per.push_back(permutation);
                permutation = "";
            }
        }
    }
    display(per);
}

int main()
{
    char ar[] = "ABC";
    // printPer(ar);
    string str = "ABC";
    printPermutations(str);
    return 0;
}