#include <iostream>

using namespace std;
struct Node 
{
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next = nullptr;
    }
};
typedef struct Node* NodePtr;


void printLinkList(NodePtr head)
{
   NodePtr current = head;
   while(current != nullptr){
         cout<<current->data<<" ";
         current=current->next; 
   } 
   current = head;
    while(current->next != nullptr){
         cout<<current->data<<" ";
         current=current->next; 
   }     
   cout<<endl<<current->data<<" ";
}
void middleElement(NodePtr head){
    NodePtr slow = head; 
    NodePtr fast = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next; 
        fast = fast->next->next;
    }
    cout<<"Middle Element is: "<<slow->data<<endl;
}
void removeDuplicate(NodePtr head)
{
    NodePtr curr = head ; 
    NodePtr temp = curr;
    if (head == nullptr)
     return; 
     
    while( curr->next != nullptr)
    {
        if(curr->data == curr->next->data)
        {
            temp = curr->next; 
            curr->next = temp->next; 
            delete temp; 
        }else 
        {
            curr = curr->next; 
        }

    }
}
int main ()
{
  NodePtr head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  head->next->next->next = new Node(30);
  removeDuplicate(head);
  printLinkList(head);
  middleElement(head);
}