#include<iostream>
#include<vector>
using namespace std; 
//n2 next gerater element 
vector<int> nextGreaterElement(vector<int> &arr)
{ 
  int n = arr.size();
  vector<int> temp(n,-1); 
  for(int i =0 ; i< n ; i++)
  {
    for (int j=i+1; j< n ; j++){
      if (arr[i] < arr[j])
      {
        temp[i] = arr[j];
        break ;
      }
    }
  }
  for(const auto it:temp)
  {
    cout<<it<<" ";
  }

return temp;
}
//need to write same function using stack
vector<int> nextGreaterElementStack(vector<int> &arr)
{

}

int main()
{
    vector<int> arr = {1,3,2,4};
    vector<int>res = nextGreaterElement(arr);
    cout<<endl<<"main";
      for(const auto it:res)
      {
            cout<<it<<" ";
       }
    vector<int> result =nextGreaterElementStack(arr);
    return 0; 
}