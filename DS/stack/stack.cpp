#include<iostream>
using namespace std;
#define MAX 10
int stack[MAX];
int top=-1;
int isEmpty()
{
    if(top == -1)
     return 0; 
}
void push(int value){
   
    if(top >= MAX)
      cout<<"stack over flow";
    else {
     stack[++top]=value;//perincrement 
    }
} 
int pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot remove element\n");
        return -1; // Or some error value
    } else {
        return stack[top--];//post increment
    }
}

int main() 
{
   push(1);
   push(2);
   push(3);

   cout<<"currentTOP"<<stack[top]<<endl<<"top->"<<top<<endl<<"value->"<<pop();

   return 0;
}