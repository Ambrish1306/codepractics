#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;    

bool hasSumK(const vector<int>& arr, int target) {
    {
        unordered_map<int,int> map;
        for(int i =0 ; i<arr.size();i++)
        {
            int more = target - arr[i];//more of current element to reach target sum
            if(map.find(more) != map.end())
                return true;//return {map[more],i};//return indices of the two elements that sum to k
            map[arr[i]] = i;
        }
        return false;
    }
}
bool hasSumofK(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == target) {
            return true; // Found a pair
        } else if (currentSum < target) {
            left++; // Move left pointer to the right to increase sum
        } else {
            right--; // Move right pointer to the left to decrease sum
        }
    }
    return false; // No pair found
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 9;
    if(hasSumK(arr, k)) {
        cout << "Found a pair with sum " << k << " using hashmap method" << endl;
    } else {
        cout << "No pair with sum " << k << " found using hashmap method" << endl;
    }

    if(hasSumofK(arr, k)) {
        cout << "Found a pair with sum " << k << " using two-pointer method" << endl;
    } else {
        cout << "No pair with sum " << k << " found using two-pointer method" << endl;
    }
    
    return 0;
}
