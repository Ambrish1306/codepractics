#include <iostream>
#include <vector>
using namespace std;
//leader eleement the element where right side all the value is less then 
//brute force idea 
void leaderElement(vector<int> &arr)
{
    int n = arr.size();
   for(int i=0 ; i < n -1  ;i++)
   {
     bool leader = true; 
    for (int j= i + 1 ; j < n -1 ;j++)
    { 
        if(arr[i] < arr[j] )
        {  
            leader = false;
            break ;
        }
        
    }
     if(leader)
            cout <<arr[i]<<endl ;
   }
}
//O(n) code  
void leaderElement1(vector<int> &arr)
{
    int maxSofar=arr[arr.size() -1];
    for(int i = arr.size() -2 ; i > 0 ; i--)
    {
        if (maxSofar < arr[i])
        {
           maxSofar = arr[i];
           cout << maxSofar<<endl;
        }
    }
}

int main () 
{
    vector<int> arr = {16,17,4,3,5,2,1};
    leaderElement1(arr);
    return 0;
}