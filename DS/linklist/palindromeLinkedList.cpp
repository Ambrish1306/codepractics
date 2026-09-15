#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node
{
    int data;
    Node *next; 
    Node(int data):data(data),next(nullptr){}
};
typedef Node* Nodeptr;

bool isPalindrome(Nodeptr head)
{
    if(!head || !head->next) return false;
    stack<int> s; 
    Nodeptr temp = head;
    while (temp != nullptr)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    Nodeptr curr = head; 
    while (curr != nullptr)
    {
        int value=s.top();
        s.pop();
        if(value != curr->data){
            return false;
        }
        curr= curr->next;
    }
    return true;
}
Nodeptr reverse(Nodeptr head)
{ 
  Nodeptr next; 
  Nodeptr curr = head; 
  Nodeptr prv = nullptr;

  while(curr)
  { 
        next = curr->next;
        curr->next=prv;
        prv = curr;
        curr = next;
  }
  return prv; 
}


//two mistak Forgot this on struct 
//unnessusliary use result could have directly return
int main() 
{
   Nodeptr head = new Node(10);
   head->next= new Node(20);
   head->next->next= new Node(30);
   head->next->next->next= new Node(10);
   Nodeptr temp = head;
   while(temp!= nullptr)
   {
     cout<<"->"<<temp->data;
     temp = temp->next;
   }
   if(isPalindrome(head))
      cout<<endl<<"Palindrome"<<endl;
    else 
      cout<<endl<<"Not Palindrome"<<endl;
    Nodeptr temp1 = reverse(head);
    while(temp1 != nullptr)
    {
        cout<<temp1->data<<"->";
        temp1 = temp1->next;
    }
  return 0;
}
