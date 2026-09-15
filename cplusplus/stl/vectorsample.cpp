#include<iostream>
#include<vector>
using namespace std;
class VectorSample{
      vector<int> vec;
    public:
    VectorSample(int n):vec(n,1){}//initialize vector of size n with all elements as 1
    void display(){
        for(const auto item :vec){
            cout<<item<<" ";    
        }
        cout<<endl;
    }
    ~VectorSample() {
        delete vec;
    }

};
int main(){
    VectorSample vs(5);
    vs.display();
    return 0;               
}