#include<iostream>
#include<vector>
using namespace std;
#include<unordered_map>
/*if arr contain input num=[1,2,2,3,4] return true
if arr contain input num=[1,2,3,4] return false
*/
bool findDuplicateBrutforce(std::vector<int>& arr)
{
    for(int i = 0; i<arr.size(); i++)
    {
        for(int j=i+1; j<arr.size();j++)
        {
            if(arr[i]==arr[j])
              return true; 
        }
    }
    return false;
}
bool findDuplicateUsingMap(vector<int>& arr)
{
    unordered_map<int,int> mp;
    for(const auto &it:arr){
        if(mp.find(it) == mp.end())
            mp[it]=1;
        else 
            return true;
    }
    return false;
}
bool findDuplicateUsingArray(vector<int>& arr)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[abs(arr[i])]>=0)
            arr[abs(arr[i])]=-arr[abs(arr[i])];
        else 
            return true;
    }
    return false;
}
int main()
{
    vector<int> arr = {1, 3, 4, 2, 2};
    bool duplicate = findDuplicateBrutforce(arr);
    cout << "Duplicate number is: " << (duplicate ? "true" : "false") << endl;
    return 0;
}