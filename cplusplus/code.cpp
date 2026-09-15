#include <stdio.h>

//mistak ...i did not pass arr size and try to access array 
//in factory we should to take another which does not need

int add(int a, int b)
{
    return a + b;
}
void printArray(int arr[],int size)
{
    for(int i=0;i<size ; i++)
    {
        printf("%d\n",arr[i]);
    }
}
int factorial(int n)
{   
    if (n == 0)
         return 1;
    else 
         return n * factorial(n -1);

}
int Funsum(int n)
{
    if(n == 0)
        return 1;
    else 
        return n + Funsum( n -1 );
}
int main()
{
    int arr[] = {1,2,3,4};
    int (*fun)(int,int);
    fun = &add; 
    int result = fun(10,20);
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,size);
    int fact = factorial(5);
    printf("%d", fact);
    int sum = Funsum(5);
    printf("\n%d", sum);

    return 0;
}