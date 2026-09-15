#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void processVector(vector<int>& arr, int value, int newValue, int x)
{
    // 1️⃣ Insert if value not present
    auto it = find(arr.begin(), arr.end(), value);
    if (it == arr.end())
    {
        arr.push_back(value);
        cout << "Inserted value: " << value << endl;
    }
    else
    {
        // 2️⃣ Update if value present
        *it = newValue;
        cout << "Updated value to: " << newValue << endl;
    }

    // 3️⃣ Delete if value == x
    for (auto itr = arr.begin(); itr != arr.end(); )
    {
        if (*itr == x)
        {
            cout << "Deleted value: " << *itr << endl;
            itr = arr.erase(itr);
        }
        else
        {
            ++itr;
        }
    }
}
void processMap(unordered_map<int,int> &arr,int key, int value,int newValue,int x)
{
    auto it = arr.find(key);
    if(it != arr.end())
    {
        arr[key]=value; //insert value 
    }else 
    {
        it->second=newValue; //update value
    }

    if(arr.erase(key))
    {
        cout<<"Element deleted"<<endl;
    }


}

int main()
{
    unordered_map<int, int> mp = {
        {1, 10},
        {2, 20},
        {3, 30}
    };

    processMap(mp, 4, 40, 99, 2);

    cout << "Final map:\n";
    for (const auto& p : mp)
    {
        cout << p.first << " -> " << p.second << endl;
    }
}
