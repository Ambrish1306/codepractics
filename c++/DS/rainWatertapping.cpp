#include<istream>
#include<vector>
#include<iostream>
using namespace std;        
//most number of water store when it rains 
int rainwaterTrapping(vector<int> &arr)
{
    int size = arr.size();
    int left=0 , right=size-1;
    int lMax=0 , rMax=0;
    int waterTrapped=0;
    while(left <= right)
    {
        if(arr[left] <= arr[right] )
        {  
            lMax = max(lMax, arr[left]);
            waterTrapped += lMax - arr[left];
            left++; 

        }else {
             rMax = max(rMax, arr[right]);
            waterTrapped += rMax - arr[right];
            right--; 

        }
    }

    return waterTrapped;
}

int main ()
{
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rainwaterTrapping(arr)<<endl;
    return 0;
}