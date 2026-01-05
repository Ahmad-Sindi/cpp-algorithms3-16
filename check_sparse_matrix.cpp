#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
 * ------------------------------------------------------------
 * Algorithm Challenge – Level 3 | #16 Check Sparse Matrix (3x3)
 *
 * A sparse matrix is a matrix in which the number of zero elements is greater than or equal to half of the total number of elements.
 *
 * This program demonstrates:
 * - Matrix traversal using nested loops
 * - Counting specific values inside a matrix
 * - Applying a mathematical condition to classify the matrix
 * - Understanding integer division behavior in C++
 *
 * Author: Ahmad Sindi
 * Language: C++
 * ------------------------------------------------------------
 */

// Prints a 2D matrix in a formatted layout
void PrintMatrix(int arr[3][3], short Rows, short Colms)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
        {
            cout << setw(2) << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

// Counts how many times a specific number appears in the matrix
short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Colms)
{
    short NumberCount = 0;

    for (short i = 0; i < Rows; i++) // Traverse rows
    {
        for (short j = 0; j < Colms; j++) // Traverse columns
        {
            if (Matrix1[i][j] == Number)
            {
                NumberCount++;
            }
        }
    }

    return NumberCount;
}

// Checks whether the matrix is sparse or not
bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Colms)
{
    short MatrixSize = Rows * Colms; // Total number of elements in the matrix

    // A matrix is considered sparse if:
    // number of zeros >= half of the matrix size
    //
    // Note:
    // Integer division is used here.
    // Example: 9 / 2 = 4 (NOT 4.5)
    return (CountNumberInMatrix(Matrix1, 0, Rows, Colms) >= (MatrixSize / 2));
}

int main()
{
    /*
     * Case explanation:
     * This matrix contains 4 zeros out of 9 elements.
     * 9 / 2 = 4 (integer division).
     * Since 4 >= 4, the matrix is considered sparse.
     */
    int Matrix1[3][3] = {
        {0, 0, 1},
        {5, 4, 6},
        {0, 0, 9}};

    cout << "Matrix:\n";
    PrintMatrix(Matrix1, 3, 3);

    if (IsSparseMatrix(Matrix1, 3, 3))
        cout << "\nYes: it is a sparse matrix.";
    else
        cout << "\nNo: it is NOT a sparse matrix.";

    return 0;
}
