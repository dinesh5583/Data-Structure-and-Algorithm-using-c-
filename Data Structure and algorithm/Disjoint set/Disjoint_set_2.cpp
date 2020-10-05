#include<iostream>
#include<conio.h>
using namespace std;
void Makeset(int Arr[],int n);
int root(int Arr[ ],int i);
int Union(int Arr[ ] ,int A ,int B);
bool find(int A,int B,int []);
void display(int Arr[],int n);
int main()
{
    int Arr[100],n;
    cout<<"enter size of sets";
    cin>>n;
    Makeset(Arr,n);
    Union(Arr,1,0);
   Union(Arr,0,2);
    Union(Arr,3,4);
    Union(Arr,1,4);
    display(Arr,n);
    find(0,4,Arr);
    getch();
}
void Makeset(int Arr[],int n)
{
     for(int i=0;i<n;i++)
     {
             Arr[i]=i;
     }
}
int root(int Arr[ ],int i)
{
    while(Arr[ i ] != i)           //chase parent of current element until it reaches root.
    {
     i = Arr[ i ];
    }
    return i;
}
int Union(int Arr[ ] ,int A ,int B)
{
    int root_A = root(Arr, A);       
    int root_B = root(Arr, B);  
    Arr[ root_A ] = root_B ;       //setting parent of root(A) as root(B).
}
bool find(int A,int B,int Arr[])
{
    if( root(Arr,A)==root(Arr,B) ){
	cout<<"they areconncted";      //if A and B have same root,means they are connected.
    return true;
}
    else
    return false;
}
void display(int Arr[],int n)
{
     for(int i=0;i<n;i++)
     cout<<"parent of "<<i<<" is "<<Arr[i]<<endl;
}
