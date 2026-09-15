#include <iostream>
#include<vector>
using namespace std;
//minimumJump to reach end 
int minimumJump(vector<int> &arr)
{
    int maxReach=arr[0];
    int jumps =1,steps=arr[0]; 

    if (arr[0] <= 0) return 1; 
    for(int i =1 ; i < arr.size(); i++)
    {

        if(i == arr.size() - 1)
          return jumps ; 

        maxReach = max(maxReach, i + arr[i]);

        steps--; 

        if (steps == 0)
        {

            jumps++; 

            if(i >= maxReach) return -1;


            steps = maxReach - i;

        }

    }
  return jumps ;

}

int main()
{
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int k = 3;
    cout<<minimumJump(arr)<<endl;
    return 0;
}
