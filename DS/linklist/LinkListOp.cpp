//practies LL basic operation 
#include<iostream>
using namespace std;
struct Node
{
    int data; 
    Node *next; 
    Node(int data)
    {
        this->data=data; //this key word use 
        this->next=nullptr;
    }
};
typedef Node* NodePtr;
void printLL(NodePtr head)
{
    NodePtr temp = head; 
    while(temp != nullptr)
    {
        cout<<"Node=>"<<temp->data<<endl;
        temp = temp->next;
    }
}
NodePtr insetNodeHead(NodePtr head)
{
    NodePtr newNode = new Node(5);
    newNode->next = head;
    head= newNode;
    return head;
}
NodePtr insetLastNodeHead(NodePtr head)
{
        NodePtr newNode = new Node(70);
        NodePtr temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;

    return head;
}
NodePtr insetBetNodeHead(NodePtr head,NodePtr newNode)
{
    NodePtr temp = head;
    NodePtr curr = temp;
      while (temp != nullptr)
      {
        if(temp->data <= newNode->data)
        {  curr = temp;
           temp = temp->next;
        }else break;
      }
    newNode->next = temp; 
    curr->next = newNode;
  return head;
}
NodePtr deleteEvenNode(NodePtr head)
{
    NodePtr temp = head;
    NodePtr curr = temp; 

    while( temp != nullptr && temp->next != nullptr)
    {   
        curr = temp->next;
        temp->next = curr->next;
        if(curr != nullptr)
        {
          delete curr;
          curr=nullptr;
        }
                temp = temp->next;               // move to next odd node

    }
    return head;
}
int main()
{
   NodePtr head = new Node(10);
   head->next= new Node(20);
   head->next->next = new Node(50);
   head->next->next->next = new Node(60);
   printLL(head);
   head = insetNodeHead(head);
   head = insetLastNodeHead(head);
   NodePtr newNode = new Node(30);
   cout<<"after add"<<endl;
   printLL(head);
   head = insetBetNodeHead(head,newNode);
   printLL(head);
   head = deleteEvenNode(head);
   cout<<"deleteEvenNode"<<endl;
      printLL(head);


   return 0;

}