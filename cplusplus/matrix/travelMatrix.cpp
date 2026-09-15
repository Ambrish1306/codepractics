/*
mat
 ├──> mat[0] = [0, 0, 0, 0]   (stored in one memory block)
 ├──> mat[1] = [0, 0, 0, 0]   (stored elsewhere in memory)
 └──> mat[2] = [0, 0, 0, 0]   (stored elsewhere in memory)
*/
#include<iostream>
#include<vector>
using namespace std; 

void printMatrix(int arr[][3]){
    
   for(int i =0 ; i< 3; i++ )
   {
       for(int j =0 ; j< 3; j++ )
        {
            cout<<arr[i][j]<<" ";
        }
   }

}
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::swap and std::reverse

using namespace std;

// Function to rotate the matrix by 90 degrees clockwise in-place
void rotateMatrixClockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // 1. Transpose the matrix
    // Swap elements across the main diagonal (top-left to bottom-right)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // 2. Reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
///anti-clockwise
     for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n / 2; ++i) {
            std::swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
}

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}



void printMatrixVector(vector<vector<int>> vArr) 
{   
   int row = vArr.size();//row
   int col = vArr[0].size();//col
   ///matrix init
   	vector<vector<int>> result(row, vector<int>(col));
    vector<vector<int>> matrix(row,vector<int>(col));//remember matrix declear like this
    vector<vector <int>> transMatr(col,vector<int>(row,0));///matrix init to zero. 
}

int main() 
{
   int arr[][3]={{1,2,3},
                {2,3,4},
                {5,6,7}}; 
    vector<vector<int>> vArr = {{1,2},{3,4}}
    printMatrixVector(vArr);
   printMatrix(arr);
       // Example 3x3 matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    rotateMatrixClockwise(matrix);

    cout << "\nRotated matrix (90 degrees clockwise):" << endl;
    printMatrix(matrix);

    return 0;
   return 0;
}


