#include<iostream>
#include<string>
#include<algorithm>
using namespace std;    
void printGroupOfAnagrams(const vector<string>& words) {
    {
        unordered_map<string, vector<string>> anagramGroups;
        for(const auto& word :words){
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            anagramGroups[sortedWord].push_back(word);
        }
        for(const auto& group : anagramGroups){
            cout << "Anagram Group: ";
            for(const auto& word : group.second){
                cout << word << " ";
            }
            cout << endl;
        }
       
    }
}

int main () {
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    printGroupOfAnagrams(words);
    return 0;
}