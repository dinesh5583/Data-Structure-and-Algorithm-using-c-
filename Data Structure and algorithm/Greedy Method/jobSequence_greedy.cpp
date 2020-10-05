#include<iostream>
#include<algorithm>
using namespace std;
class job{
	public:
	char id;
	int dead;
	int profit;
};
bool cmp(job a,job b)
{
	return a.profit>b.profit;
}
void jobSeq(job arr[],int n)
{
	sort(arr,arr+n,cmp);
	int result[n];
	int slot[n];
	for(int i=0;i<n;i++)
	slot[i]=false;
	
	for(int i=0;i<n;i++)
	{
		for(int j=min(n,arr[i].dead)-1;j>=0;j--)
		{
			if(slot[j]==false)
			{
				result[j]=i;
				slot[j]=true;
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(slot[i])
		cout<<arr[result[i]].id<<"\t";
	}
}
int main()
{
	job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
                   {'d', 1, 25}, {'e', 3, 15}};
	int n=sizeof(arr)/sizeof(arr[0]);
	jobSeq(arr,n);
}
