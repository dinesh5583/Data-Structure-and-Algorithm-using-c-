#include<iostream>
#include<algorithm>
using namespace std;

class Item
{
	public:
	int weight, value;
	Item(int value,int weight):value(value),weight(weight)
	{
		}	
};
bool cmp(Item a,Item b)
{
	double r1,r2;
	r1=(double) a.value/a.weight;
	r2=(double) b.value/b.weight;
	return r1>r2;
}
double knapsack(Item arr[],int n,int w)
{
	sort(arr,arr+n,cmp);
	int cur_weight=0;
	double Init_value=0.0;
	for(int i=0;i<n;i++)
	{
		if(cur_weight+arr[i].weight<=w)
		{
			cur_weight+=arr[i].weight;
			Init_value+=arr[i].value;
		}
		else{
			int remain=w-cur_weight;
			Init_value+=arr[i].value*((double) remain/arr[i].weight);
			break;
		}
	}
		return Init_value;
	
}
int main(){
	Item arr[]={{600,50},{500,20},{400,30}};
	int w=70;
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<knapsack(arr,n,w);
	
}
