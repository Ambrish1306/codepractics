#include<iostream>
#include<memory>
using namespace std;
class Job 
{
    int mId;
    public:
    Job(int id):mId(id)
    {
        cout<<"Job constructor called for id: "<<mId<<endl; 
    }
    ~Job()
    {
        cout<<"Job destructor called for id: "<<mId<<endl; 
    }
    Job(Job&& other) noexcept : mId(other.mId) {

        cout<<"Job move constructor called for id: "<<mId<<endl; 
        other.mId = 0; // Reset the moved-from object's id to indicate it's been moved
    }
    void display() const
    {
        cout<<"Job id: "<<mId<<endl; 
    }
};
int main()
{
    shared_ptr<Job> dispatcherJob = make_shared<Job>(1); 
    cout<<"Dispatcher Job created"<<endl;
    dispatcherJob->display();

    shared_ptr<Job> jobObj = (std::move(dispatcherJob)); //move semantics used to transfer ownership of dispatcherJob to workerThread
    if(!dispatcherJob)
    {
        cout<<"dispatcherJob is null after move"<<endl; 
    }
    jobObj->display();
    cout<<"Main thread is done"<<endl; 
    return 0; 
}