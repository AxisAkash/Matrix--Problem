#include <iostream>
using namespace std;

#define MAX 100  // Define the maximum size of the matrix

void inputMatrix(int mat[MAX][MAX], int row, int col)
{
    cout << "Enter elements of the matrix (" << row << "x" << col << "):\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int mat[MAX][MAX], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int row1, int col1, int row2, int col2)
{
    if (col1 != row2)
    {
        cout << "Matrix multiplication not possible!" << endl;
        return;
    }
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < col1; ++k)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[MAX][MAX], int transposed[MAX][MAX], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            transposed[j][i] = mat[i][j];
        }
    }
}
int main()
{
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int row1, col1, row2, col2;

    cout << "Enter rows and columns for first matrix: ";
    cin >> row1 >> col1;
    inputMatrix(mat1, row1, col1);

    cout << "Enter rows and columns for second matrix: ";
    cin >> row2 >> col2;
    inputMatrix(mat2, row2, col2);
    cout<<endl;

    printMatrix(mat1, row1, col1);
    cout,, "print the desire 1st matrix"<<endl;
    printMatrix(mat2, row2, col2);



    // Matrix Addition
    if (row1 == row2 && col1 == col2)
    {
        addMatrices(mat1, mat2, result, row1, col1);
        cout << "Result of Matrix Addition:\n";
        printMatrix(result, row1, col1);
    }
    else
    {
        cout << "Matrix addition not possible due to dimension mismatch.\n";
    }

    // Matrix Subtraction
    if (row1 == row2 && col1 == col2)
    {
        subtractMatrices(mat1, mat2, result, row1, col1);
        cout << "Result of Matrix Subtraction:\n";
        printMatrix(result, row1, col1);
    }
    else
    {
        cout << "Matrix subtraction not possible due to dimension mismatch.\n";
    }

    // Matrix Multiplication
    multiplyMatrices(mat1, mat2, result, row1, col1, row2, col2);
    if (col1 == row2)
    {
        cout << "Result of Matrix Multiplication:\n";
        printMatrix(result, row1, col2);
    }

    // Matrix Transpose
    int transposed[MAX][MAX];
    transposeMatrix(mat1, transposed, row1, col1);
    cout << "Transpose of First Matrix:\n";
    printMatrix(transposed, col1, row1);

    return 0;
}

