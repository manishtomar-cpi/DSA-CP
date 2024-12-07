#include <iostream>
using namespace std;


void pass2dArrayAsFunction(int ar[][10], int row, int col) {//*giving col when passing the 2d array as a parameter is mandatory
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}

void intro_to_2d_array()
{
    // syntax
    //  data_type array_name [row_size] [col_size];

    // int arr[5][3]; // the 2d array have 5 rows and 3 column index starting from '0'

    // taking input in the 2d array;
    int row, col;
    cout << "how many rows and columns: ";
    cin >> row;
    cin >> col;
    cout << endl;

    int ar[row][col];

    // taking input row wise
    for (int i = 0; i < row; i++)
    {
        cout << "enter row " << i << "element: " << endl;
        // iterate rows
        for (int j = 0; j < col; j++)
        { // iterate col
            cin >> ar[i][j];
        }
    }

    // printing row wise
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}

void initOf2dArray()
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}}; // so the array have 2 row and 3 column like this

    int ar[][3] = {{1, 2, 4}, {4, 5, 6}}; // means we can init the 2d array without passing the rows //!col is mandatory

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ar[i][j] << "";
        }
        cout << endl;  
    }

    int arrr[10][10] = {{0}}; //init 2d array with all value 0;

    pass2dArrayAsFunction(arrr,10,10);
}

int main()
{
    // intro_to_2d_array();
    initOf2dArray();

    return 0;
}