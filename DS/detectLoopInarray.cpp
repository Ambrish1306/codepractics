#include<iostream>
using namespace std;
//Detect cycle in array (Floyd’s cycle detection) c++
boolean detectLoopInArray(int arr[])
{
   int slow=arr[0];
   int fast=arr[0];
   int n = sizeof(arr) / sizeof(arr[0]);
   for(int i =0; i < n ; i++)
     cout<<"a[i]"<<a[i]<<endl;
   while(true)
   {
     slow = arr[slow];
     fast = arr[arr[fast]];
     if(slow == fast)
      return true;
   }
}
int main()
{
    int arr[] = {1,2,3,4,5,1,2};
    cout<<detectLoopInArray(arr); 
    return 0 ;
}