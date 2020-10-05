#include<iostream>
#include<conio.h>
using namespace std;
void Makeset(int arr[],int n);
int find(int arr[],int n,int A);
void Union(int arr[],int n,int A,int B);
void display(int arr[],int);
int main()
{
    int arr[100],n;
    cout<<"enter size of sets";
    cin>>n;
    Makeset(arr,n);
    Union(arr,n,2,1);
    Union(arr,n,4,3);
    Union(arr,n,8,4);
    Union(arr,n,9,3);
    Union(arr,n,6,5);
    Union(arr,n,8,9);
    Union(arr,n,5,2);
    display(arr,n);
    getch();
}

void display(int arr[],int n)
{
     for(int i=0;i<n;i++)
     cout<<"parent of "<<i<<" is "<<arr[i]<<endl;
}
void Makeset(int arr[],int n)
{
     for(int i=0;i<n;i++)
     {
             arr[i]=i;
     }
}
int find(int arr[],int n,int A)
{
     if(!(A>=0 && A<n))
     return -1;
     if(arr[A]==A)
     return A;
     else return find(arr,n,arr[A]);
}
void Union(int arr[],int n,int A,int B)
{
     if(find(arr,n,A)==find(arr,n,B))   // element has same parent or belong to same set
     return;
     if(!((A>=0 && A<n) && (B>=0 && B<n)))
     return;
     arr[A]=B;
}

     
     
