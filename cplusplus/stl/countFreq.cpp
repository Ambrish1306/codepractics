#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

void printMap(unordered_map<string,int> frq)
{
    for (const auto &it : frq)
    {
        cout << "key->" << it.first << "->" << it.second << endl;
    }
}
void duplicatOnSS(string str)
{
    stringstream ss(str);
    unordered_map<string,int> duplicatOnSS; 
    string word;
    while (ss >> word)
    {
       duplicatOnSS[word]++;
    }
    for(const auto &it:duplicatOnSS)
    {
        if(it.second > 1)
        {
            cout<<"key->"<<it.first<<"->"<<it.second<<endl;
        }
    }
    
}
void countEven(const vector<int>&arr)
{
    int countEvn; 
    for(auto it =arr.begin();it != arr.end(); ++it)
    {
        if(*it % 2 == 0){
            countEvn++;
        }

    }
    cout<<endl<<"Even NUmber:"<<countEvn;
    auto it =arr.begin();
    while(it != arr.end())
    {
        if(*it % 2 == 0)
        {
            cout<<endl<<"Deleting value:"<<*it;
            it = arr.erase(it);
            //*it =0;
        }else{ 
        ++it;
        }

    }
    for(auto it = arr.begin(); it != arr.end(); ++it)
       cout<<endl<<"Vector having element:"<<*it;
}
int main()
{
    string temp = "this is is my string";
    unordered_map<string, int> frq;///
    stringstream ss(temp);///pass string into the stringstream ss
    string word;
    while (ss >> word)//string stream is same like cin and cout...ss>>"name">>name >>"age" >>age;
    {
        frq[word]++;
    }
   // printMap(frq);
    duplicatOnSS(temp);
    vector<int> arr= {1,2,3,4,5,6};
    countEven(arr);
    return 0;
}