#include<bits/stdc++.h>
using namespace std;
double *compute( int **arr, int rows, int cols )
{
    double *average = new double[rows];
    double sum = 0;
    for( int i = 0; i<rows; i++ )
    {
        sum = 0;
        for( int j = 0; j<cols; ++j )
        {
            sum += arr[i][j];
        }
        average[i] = sum/rows;
    }
    return average;
}

int main()
{
    int cols = 3;
    int rows = 3;
    int **arr = new int*[rows];
    
    for( int i = 0; i<rows; ++i )
    {
        arr[i] = new int[cols];
        for( int j = 0; j<cols; ++j )
        {
            arr[i][j] = i + j;
        }
    }
    
    double *average = compute(arr, rows, cols);
    
    for( int i = 0; i<rows; i++ )
    {
        cout<<"average of row "<<i<<average[i]<<endl;
    }
}
