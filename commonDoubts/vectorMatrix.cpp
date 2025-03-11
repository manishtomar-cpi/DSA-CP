#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows = 3, cols = 3; // Define matrix size

    // Creating a matrix with 3 rows and 3 columns filled with 0
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    // Printing the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
 Explanation:
We define a vector<vector<int>> (2D vector) with 'rows' number of rows and 'cols' number of columns.
The inner vector (vector<int>(cols, 0)) initializes each row with 'cols' number of elements, all set to 0.
We print the matrix using nested loops

output:
0 0 0
0 0 0
0 0 0

*/