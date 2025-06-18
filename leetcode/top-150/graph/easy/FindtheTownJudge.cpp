#include <iostream>
#include <vector>
using namespace std;

void printGraph(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix[0].size(); i++)
    {
        cout << i << ": ";
        for (int j = i; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 1)
            {
                cout << j << ",";
            }
        }
        cout << endl;
    }
}

int findJudge(int n, vector<vector<int>> &trust)
{

    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < trust.size(); i++)
    {
        cout << trust[0][0] << endl;
        matrix[trust[i][0]][trust[i][1]] = 1;
    }
    int zeroCount = 0;
    int zeroIndex = -1;
    for (int i = 1; i <= n; i++)
    {
        bool isZero = true;
        for (int j = 1; j <= n; j++)
        {
            if (matrix[i][j] == 1)
            {
                isZero = false;
            }
        }
        if (isZero)
        {
            zeroIndex = i;
            zeroCount++;
        }
    }
    if (zeroCount == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (matrix[i][zeroIndex] != 1 && i != zeroIndex)
            {
                return -1;
            }
        }
    }
    return zeroCount == 1 ? zeroIndex : -1;

    printGraph(matrix);
}

int main()
{
    vector<vector<int>> matrix = {{1, 3}, {2, 3}, {3,1}};
    cout << findJudge(3, matrix);

    return 0;
}