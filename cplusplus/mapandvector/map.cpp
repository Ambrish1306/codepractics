#include<unordered_map>
#include<iostream> 
#include<map>

using namespace std;
/*{
  { key_char , { {string, int}, {string, int} } },
  { key_char , { {string, int} } }
}*/
/*
for (const auto& [key, value] : mp) {
    cout << key << " " << value << endl;
}
  */

int mapExprimentFunction(){
  map<int,map<string,string>> data; 
  data[1]["city"]="Bilaspur";
  data[1]["Name"]="Ambrish";
  
/*  for(const auto &it:data){
 //   cout<<"Name:"<<it.second.at("Name")<<endl;
 //   cout<<"Name:"<<it.second.at("city");
  }*/
for(auto it = data.begin() ; it != data.end(); it++){
    cout<<"Name:"<<it->second["Name"]<<endl;
    cout<<"City:"<<it->second["city"];

  }
}

 void inputOnMap(){
     int n;
     cin >> n;

    map<int, string> mp;

    for (int i = 0; i < n; i++) {
        int key;
        string value;
        cin >> key >> value;

        mp[key] = value;
    }

    // print map
    for (const auto& [key, value] : mp) {
        cout << key << " " << value << endl;
  }
}
int main()
{
  unordered_map<char,int> un_map={'A',11}; 
  unordered_map<char,unordered_map<string,int>> nextMap={
                                                         {'A',{ {"Ambrish",29},{"Ansh",22},{"ASHU",23} } },
                                                         {'B',{{"Bt",29}} }
                                                        }; 

  //auto it = unordered_map<char,int> un_map;
  int numberEnt; 
  cout<<"Enter Number of Entry you want to add";
  if(!(cin >> numberEnt))
  {
    cerr<<"Invalide entry";
    return 1;
  }
  for (int i =0 ; i < numberEnt ; i++)
  {
      char key; 
      int value;
      cout << "Emter char(key) and value";
      if(!(cin>>key>>value)
      {
        cerr<<"Invalide Entry";
        return 1;
      }
      un_map[key]=value;

  }
  for(auto it = un_map.begin();it != un_map.end(); it++)
  {
     cout<<it->first<<it->second;
  }
  for(const auto &it : un_map)
  { 
    cout<<it.first<<":"<<it.second;
  }
  inputOnMap();
 return;
}

// operation on map<int,map<string,string>>
// number---role-----status
//101       Admin    Active
//102       User     Pending  
//
/*struct UserDetails {
    std::string name;
    std::string role;
    std::string status;
};
*/
// Syntax
//std::map<int, std::map<std::string, UserDetails>> data;

// Usage
//data[101]["profile"] = {"Alice", "Admin", "Active"};

int main() {
    // Declaration
    std::map<int, std::map<std::string, std::string>> data;

    // =========================================================================
    // 1. INSERTION OPERATIONS
    // =========================================================================

    // Method A: Square brackets (Operator[])
    // Automatically creates the inner map and string pairs if they don't exist.
    data[101]["role"] = "Admin";
    data[101]["status"] = "Active";

    // Method B: Using std::make_pair or Initialiser Lists
    // More explicit, constructs and inserts the structures.
    data.insert({102, {{"role", "User"}, {"status", "Pending"}}});


    // =========================================================================
    // 2. UPDATE OPERATIONS
    // =========================================================================

    // Method A: Direct Assignment (Unsafe if you aren't sure key 101 exists, 
    // as it will accidently insert an empty map if missing)
    data[101]["status"] = "Inactive";

    // Method B: Safe Update using .find() (Prevents accidental insertions)
    auto outer_it = data.find(101);
    if (outer_it != data.end()) {
        auto& inner_map = outer_it->second; // Get reference to inner map
        auto inner_it = inner_map.find("role");
        
        if (inner_it != inner_map.end()) {
            inner_it->second = "SuperAdmin"; // Safely update value
        }
    }


    // =========================================================================
    // 3. DELETE OPERATIONS
    // =========================================================================

    // Method A: Delete a specific key-value pair inside an inner map
    auto outer_del_it = data.find(101);
    if (outer_del_it != data.end()) {
        outer_del_it->second.erase("status"); // Removes only "status" from ID 101
    }

    // Method B: Delete an entire outer key (Removes the ID and its whole inner map)
    data.erase(102); // Deletes key 102 and everything inside it

    // Method C: Clear the entire data structure completely
    data.clear(); // Total memory cleanup
}