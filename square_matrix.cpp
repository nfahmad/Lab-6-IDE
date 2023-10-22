#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;
int console[MAX_SIZE][MAX_SIZE];

const char* filename = "matrix_input.txt";
ifstream file(filename);

int matrixA[MAX_SIZE][MAX_SIZE];
int matrixB[MAX_SIZE][MAX_SIZE];
int size;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& size)
{
    file >> size;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            file >> matrixA[i][j];
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            file >> matrixB[i][j];
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void sumOfMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            console[i][j] = A[i][j] + B[i][j];
        }
    }
}

void productOfMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            console[i][j] = 0;
            for (int k = 0; k < size; k++)
            {
                console[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void differenceOfMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            console[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

int main()
{
    readMatrix(matrixA, size);
    readMatrix(matrixB, size);

    file.close();

    std::cout <<"Nabeel Ahmad\n";
    std::cout <<"Lab #6: Matrix manipulation\n" << endl;

    cout << "Matrix A:" << endl;
    displayMatrix(matrixA, size);

    cout << "\nMatrix B:" << endl;
    displayMatrix(matrixB, size);

    cout << "\nMatrix Sum (A + B):" << endl;
    sumOfMatrices(matrixA, matrixB, size);
    displayMatrix(console, size);

    cout << "\nMatrix Product (A * B):" << endl;
    productOfMatrices(matrixA, matrixB, size);
    displayMatrix(console, size);

    cout << "\nMatrix Difference (A - B):" << endl;
    differenceOfMatrices(matrixA, matrixB, size);
    displayMatrix(console, size);

    return 0;
}
