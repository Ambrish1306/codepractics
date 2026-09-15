//perfisx [1,1,1,1,1] k=3
//find the sub array whoes value is K
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
int perfixSum(vector<int> &arr,int k)
{
    unordered_map<int,int> mp; 
    int cnt=0, sum=0;
    mp[0] = 1;

    for(int i=0; i<arr.size(); i++)
    {
        sum +=arr[i];
        if(mp.count(sum - k))
        {
            cnt += mp[sum - k];//this will get always 0 index value ?
        }
        mp[sum]++;
    }
    return cnt;
}
int countSubbarryWithSumK(vector<int> &arr,int k)
{
   int count=0;
   int sum =0, maxSum=0 ;
   unordered_map<int,int> mp;
   for(int i =0 ; i < k ; i++)
   {
     sum += arr[i];
     
   }   
 
}
int main()
{
    vector<int> arr = {1,1,1,1,1,1,1,1,11,1,11};
    int k = 3;
    cout<<perfixSum(arr,k)<<endl;
    return 0;
}