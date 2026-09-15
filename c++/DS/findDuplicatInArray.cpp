#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 
void duplicate(int arr[])
{
    unordered_map<int,int>freq(0,100); 
    int n = sizeof(arr)/ sizeof(int);
    int index=0;
    while(index < n)
    {
        freq[arr[i]]++;
     }
}


int main ()
{
   int arr[] = {1,2,3,4,4,5,1};
   duplicate(arr);

}