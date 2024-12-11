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

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int startRow = 0;
    int endCol = matrix[0].size() - 1;
    int endRow = matrix.size() - 1;
    int startCol = 0;
    int count = 0;
    vector<int> res;

    while (count <= (matrix.size() * matrix[0].size()))
    {
        for (int i = startRow; i <= endCol; i++)
        {
            res.push_back(matrix[startRow][i]);
            display(res);
            count++;
        }
        startRow++;
        if (count == (matrix.size() * matrix[0].size()))
        {
            return res;
        }
        for (int i = startRow; i <= endRow; i++)
        {
            res.push_back(matrix[i][endCol]);
            display(res);

            count++;
        }
        endCol--;
        if (count == (matrix.size() * matrix[0].size()))
        {
            return res;
        }
        for (int j = endCol; j >= startCol; j--)
        {
            res.push_back(matrix[endRow][j]);
            display(res);

            count++;
        }
        endRow--;
        if (count == (matrix.size() * matrix[0].size()))
        {
            return res;
        }

        for (int k = endRow; k >= startRow; k--)
        {
            res.push_back(matrix[k][startCol]);
            display(res);

            count++;
        }
        startCol++;
        if (count == (matrix.size() * matrix[0].size()))
        {
            return res;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> vec = {
      {1,2,3},
      {4,5,6},
      {7,8,9}
    };

    spiralOrder(vec);
}