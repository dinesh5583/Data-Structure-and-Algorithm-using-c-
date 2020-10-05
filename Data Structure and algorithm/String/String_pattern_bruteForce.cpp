#include<iostream>
#include<string>
using namespace std;
int main()
{
	string T="elephant";
	string P="eph";
	int n=T.length();
	int m=P.length();
	for(int i=0;i<n-m;i++)
	{
		int j=0;
		while(j<m && P[j]==T[i+j])
		{
			j++;
		}
		if(j==m)
		{
			cout<<"Index is "<<i;
		}
	}
	return 0;
}
