#include <iostream>
#include <vector>
#include<fstream>
#include<string>
#include <chrono>
using namespace std;
using namespace std::chrono;

// function to print a square matrix of size n x n
void print_matrix(vector<vector<int>> matrix, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
// function to read a square matrix of size n x n from a file
void read_matrix(vector<vector<int>> &matrix, int n, string filename)
{
    ifstream file;
    file.open(filename, ios_base::in);
    if (file.is_open())
    {
        for(int i = 0; i < n; i++)
        {
            vector<int> row;
            for(int j = 0; j < n; j++)
            {
                int element;
                file >> element;
                row.push_back(element);
            }
            matrix.push_back(row);
        }
    }
    else
        cout << "Error: file not found" << endl;
    file.close();
}
// function to multiply two square matrices of size n x n
vector<vector<int>> multiply_matrix(vector<vector<int>> matrixA, vector<vector<int>> matrixB)
{
    int m = matrixA.size(), n = matrixB[0].size();
    vector<vector<int>> result( m , vector<int> (n, 0));
    
    if (matrixA[0].size() == matrixB.size())
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < matrixA[0].size(); k++)
                {
                    result[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
        return result;
    }
    cout << "Error: matrixA and matrixB cannot be multiplied" << endl;
    return result;
}
// function to measure the time taken to multiply two square matrices of size n x n
float measure_time(vector<vector<int>> matrixA, vector<vector<int>> matrixB, int n)
{
    auto start = high_resolution_clock::now();
    vector<vector<int>> result = multiply_matrix(matrixA, matrixB);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken to multiply two " << n << " x " << n << " matrices: " << duration.count() << " miliseconds" << endl;
    return duration.count();
}
// function to record the time taken to multiply two square matrices of different sizes
void record_time(int size_matrix[], int n)
{
    ofstream FileOut;
    FileOut.open("Time/c++.txt", ios_base::out);
    for(int i = 0; i < n; i++)
    {
        vector<vector<int>> matrixA, matrixB;
        read_matrix(matrixA, size_matrix[i], "Matrix Folder/matrix_A_" + to_string(size_matrix[i]) + ".txt");
        read_matrix(matrixB, size_matrix[i], "Matrix Folder/matrix_B_" + to_string(size_matrix[i]) + ".txt");
        FileOut << measure_time(matrixA, matrixB, size_matrix[i]) << endl;
    }
}

int main()
{
    vector<vector<int>> matrixA, matrixB;
    int size_matrix[] = {10, 50, 100, 250, 500, 750, 1000};
    int n = sizeof(size_matrix)/sizeof(size_matrix[0]);
    record_time(size_matrix, n);
    return 0;
}
