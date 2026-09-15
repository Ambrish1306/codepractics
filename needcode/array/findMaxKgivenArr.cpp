#include <iostream>
#include <vector>
#include <algorithm>

void printMaxOfSubarrays(const std::vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0 || k > n) return;

    int maxIdx = -1;

    for (int i = 0; i <= n - k; ++i) {
        // If the previous maximum is still inside the current window
        if (maxIdx >= i) {
            // Just check if the brand new element entering the window is larger
            if (arr[i + k - 1] >= arr[maxIdx]) {
                maxIdx = i + k - 1;
            }
        } else {
            // The previous maximum fell out of the window; scan the current window
            maxIdx = i;
            for (int j = i + 1; j < i + k; ++j) {
                if (arr[j] >= arr[maxIdx]) {
                    maxIdx = j;
                }
            }
        }
        std::cout << arr[maxIdx] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {1, 3, 5, 3, 6, 7};
    int k = 3;
    
    // Output: 3 3 5 5 6 7
    printMaxOfSubarrays(arr, k); 
    
    return 0;
}