#include<iostream>
#include<algorithm>
using namespace std;
class Pairs{
	public:
		int north,south;
};  
bool cmp(Pairs a, Pairs b)
{
	if(a.north==b.north)
		return a.south<b.south;
	return a.north<b.north;
	
}
int  maxBridges(Pairs values[],int n)
{
	int lis[n]; 
	lis[0]=1;
	sort(values, values+n, cmp);
	
	for(int i=1;i<n;i++)
	{
		lis[i]=1;
		for(int j=0;j<i;j++)
		{
			if(values[i].south>=values[j].south)
			{
				lis[i]=max(lis[i],lis[j]+1); 
			}
		}	
	}
	int res=lis[0];
	for(int i=1;i<n;i++)
	{
		res=max(res,lis[i]);
	}
	return res;
 } 
int main() 
{ 
    Pairs values[] = {{8,1}, {1,2}, {4,3}, {3,4}, {2,6},{6,7}, {7,8}, {5,5}}; 
    int n = 8; 
    cout << "Maximum number of bridges = " 
             << maxBridges(values, n);      
} 	
