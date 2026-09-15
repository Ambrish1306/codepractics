#include<iostream>
#include<vector>
using namespace std; 
//Your code for finding the maximum sum subarray of size k
void maxSumSubArray(vector<int> &arr,int k)
{
    int sum = 0 , maxSum = 0; 
    for(int i =0; i < k ;i++)
    {
        sum +=arr[i];
    }
    maxSum = sum;
    for (int i =k; i < arr.size(); i++)
    {
       sum = sum + arr[i] - arr [i - k];
       maxSum = max(maxSum,sum);

    }
    cout <<"MaxSum:"<<maxSum;
}

int main()
{
    vector<int> arr = {1,2,4,2,5,2,48,8,0};
    int k=3;
    maxSumSubArray(arr,k);
    return 0;
}