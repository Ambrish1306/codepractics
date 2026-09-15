#include<string>
#include<iostream>
using namespace std;
bool checkAanagarm(const string s1,const string s2)
{
    int arr[26] = {0};
    
    if(s1.length() != s2.length())
        return false; 
    
    for(int i =0 ; i < s1.length();i++)
    {
        arr[s1[i] - 'a']++;
        arr[s2[i] - 'a']--;
    }
    
    for(const auto &it:arr){
        if(it != 0){
          return false; 
        }
    }
    return true;
}
int main() {
std::string s1 = "abc";
    std::string t1 = "abc";
    std::cout << checkAanagarm(s1, t1) << std::endl; // Outputs:
    std::string s2 = "rat";
    std::string t2 = "car";
    cout<< checkAanagarm(s2, t2) << endl; // Outputs
}
