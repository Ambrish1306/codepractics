#include<iostream>
#include<vector>
using namespace std;
//Maximum subarray sum
void maxSumSubArry(vector<int> &arr)
{
    int sum=0, n=arr.size();
    int maxSum =0;
    for(int i =0 ; i<n-1 ; i++)
    {
        sum = 0;
        for (int j=i ; j < n- 1; j++)
        {
           sum = sum + arr[j];
           maxSum = max(maxSum,sum);
        }
        
    }
}
int main () 
{
    vector<int> arr = {-2,1,-3,4};
    maxSumSubArry(arr);
    return 0;
}