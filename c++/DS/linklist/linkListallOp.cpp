#include <bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;
struct Node 
{
    int data; 
    Node *next; 
};

typedef Node *NodePtr;
int getLenght(NodePtr head)
{
    int count =0; 
    while(head != nullptr)
    {
        count++;
        head = head->next; 
    }
    return count;
}
void allInOneDelete(NodePtr &head, int pos)
{
   if(head == nullptr)
      return;
    
   if(pos == 0)
   {
       NodePtr temp =head; 
       head = head->next; 
       delete temp; 
       return ;
   }
   
  
   NodePtr current = head; 
   for (int i =0 ; i < pos -1 && current != nullptr; i++)
      current=current->next;
      
    if(current == nullptr || current->next == nullptr) return;
    
    NodePtr temp = current->next;
    current->next = temp->next; 
    delete temp; 
}
//insert Node on different postion
void insertFristPos(NodePtr &head,int data)
{

    NodePtr temp = new Node(); 
    temp->data=data; 
    
    temp->next = head; 
    head = temp; 
    
}
void insertLast(NodePtr &head,int data)
{
    NodePtr temp = new Node(); 
    temp->data = data; 
    temp->next = nullptr;
    
    if(head == nullptr)
       return ; 
    
    NodePtr current = head;
    while(current->next != nullptr)
    {
        current=current->next; 
    }
    current->next = temp ; 
    
}

void intsertNPost(NodePtr &head, int data,int pos)
{
    NodePtr temp = new Node();
    temp->data = data;
    int count =0;
    
    if(head == nullptr || pos == 0)
      {
        temp->next=head; 
        head = temp; 
        return;
      }

    NodePtr current = head;
    while(current != nullptr && count < pos -1)
    {
       current=current->next; 
       count++;
    }
    
    if(current == nullptr)
    {
        delete temp;
        temp=nullptr;
        return ; 
    }
    
    temp->next = current->next; 
    current->next = temp;
    
}
//delete node from different pos
void deletFromBeg(NodePtr &head)
{
    if(head == nullptr)
     return; 

    NodePtr temp;
    temp = head;
    head = head->next; 
    delete temp; 
    temp = nullptr;
}
void deletFromlast(NodePtr &head)
{
    NodePtr temp = head;
    NodePtr current=temp;
    if(head == nullptr || head->next == nullptr)
    {
       delete head;
       head = nullptr;
       return;
    }   
    while(current->next != nullptr)
    {
        temp = current; 
        current = current->next;
    }
    temp->next = nullptr;
    delete current;
    current = nullptr;
    
}
void deleteOnGivan(NodePtr &head, int pos)
{
    if (head == nullptr )
    {
        return;
    }
    if(head->next == nullptr)
    {
        delete head; 
        head = nullptr;    
    }
    NodePtr temp = head;
    NodePtr current = head; 
    if (pos == 0)
    {
       head = head->next; 
       delete temp; 
       temp =nullptr;
       return ; 
    }
    int count=0;
    while (current->next != nullptr && count < pos -1 )
    {
        temp =current;
        current = current->next; 
        count++;
    }
    temp->next = current->next; 
    delete current ; 
    current = nullptr;
    
}

void printList(NodePtr head)
{
    NodePtr temp = head; 
    cout<<'\n';

    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp =temp->next;
    }
}

bool searchLinkList(NodePtr head, int item)
{
    if(head == nullptr)
        return false;
    
    while(head != nullptr)
    {
        if(head->data == item)
        {
            return true;
        }
        head = head->next ;
    }
    
    return false;
}

bool searchUsingRecursion(NodePtr head, int item)
{
   if(head == nullptr)
   return false ; 
   
   if(head->data = item) return true ;
   searchUsingRecursion(head->next,item);
    
}
int lenghtLinkListLength(NodePtr head)
{
    if(head == nullptr)
      return 0 ; 
      
    return 1+ lenghtLinkListLength(head->next);
}
int main() {
    // Create 3 nodes
    NodePtr head = new Node(); 
    NodePtr second = new Node();
    NodePtr third = new Node();

    // Assign data
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = nullptr; // end of list
    NodePtr temp = head;

    
    //insertFristPos head and value 20
    
    insertFristPos(head,5);
    insertLast(head,40);
    intsertNPost(head, 0,3);
    printList(head);
    deletFromBeg(head);
    printList(head);
    deletFromlast(head);
    printList(head);
    deleteOnGivan(head, 2);
    printList(head);
    insertFristPos(head,5);
    insertLast(head,40);
    intsertNPost(head, 20,2);
    printList(head);
    //search element on searchLinkList
    
    if(searchLinkList(head,50))
      cout<<"\nElement found !!!!";
    else 
      cout<<"\nNot found !!!";
      
    if(searchUsingRecursion(head,10))
      cout<<"\nElement found !!!!";
    else 
      cout<<"\nNot found !!!";
    printList(head);
    
    cout<<"\nlength:"<<lenghtLinkListLength(head);

    return 0;
}
