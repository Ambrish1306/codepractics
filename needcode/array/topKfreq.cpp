#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
void topKelement(const vector<int> &arr, int k){
    unordered_map<int,int> feqCount; 
    for(const auto &num:arr)
        feqCount[num]++;
    
    for(const auto &num:feqCount)
        cout<<num.first<<"=>"<<num.second<<endl;
    
    // You can implement logic to find the top K frequent elements here.
    //converting map to vector of pairs to sort by frequency 
    vector<pair<int,int>> freqVec(feqCount.begin(), feqCount.end());
    sort(freqVec.begin(), freqVec.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return b.second < a.second; // Sort in descending order of frequency
    });

    cout << "Top " << k << " frequent elements: ";
    for(int i = 0; i < k && i < freqVec.size(); i++){
        cout << freqVec[i].first << " ";
    }
    cout << endl;
    
}
int main() 
{
    std::vector<int> arr = {1,2,2,3,3,3} ;
    int k=2;
    topKelement(arr,k);
    return 0;
}