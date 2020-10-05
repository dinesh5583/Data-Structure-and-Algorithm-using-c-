#include<stdio>
using namespace std;
int main()
{
	int m,t,n,r=0,p=1,count=0;
   scanf("%d", &m); 
  for(int i=0;i<m;i++)
  {
     scanf("%d", &n); 
    t=n;
	while(t>0)
	{
		
		r=t%10;
		t=t/10;
		count=count+1;
	}
	for(int i=0;i<count;i++)
	{
		n=n+p;
		p=p*10;
	}
	 scanf("%d\n", &n); 
}
}
