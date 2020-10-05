#include<iostream>
#define N 10
using namespace std;
int Lprobe(int a[],int key);
int hashFunction(int key);
int hashFunction(int key)
{
	return key%N;
}
int Lprobe(int a[],int key)
{
	int index=hashFunction(key);
	int i=0;
	while(a[(index+i)%N]!=0)
		i++;
	return (index+i)%N;
}
void insertKey(int a[],int key)
{
	int index=hashFunction(key);
	if(a[index]!=0)
		index=Lprobe(a,key);
	a[index]=key;
}
int searchKey(int a[],int key)
{
	int index=hashFunction(key);
	int i=0;
	while(a[(index+i)%N]!=key)
		i++;
	return (index+i)%N;	
}
int main()
{
	int a[N]={0},x;
	insertKey(a,1);
	insertKey(a,3);
	insertKey(a,21);
	insertKey(a,8);
	insertKey(a,18);
	insertKey(a,28);
	for(int i=0;i<N;i++)
	{
		cout<<i<<"-->"<<a[i]<<endl;
	}
	cout<<"found at index "<<searchKey(a,66);
}
