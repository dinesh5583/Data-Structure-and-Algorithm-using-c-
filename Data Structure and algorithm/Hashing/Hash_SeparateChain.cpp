#include<iostream>
#include<list>
using namespace std;
class Hash
{
	int tsize;
	list<int> *table;
	public:
	Hash(int n)
	{
		this->tsize=n;
		table=new list<int>[tsize];
	}
	int HashFunction(int x)
	{
		return x%tsize;
	}
	void insertKey(int key)
	{
		int index=HashFunction(key);
		table[index].push_back(key);
	}
	void displayHash()
	{
		for(int i=0;i<tsize;i++)
		{
			cout<<i;
			list<int>::iterator it;
			for(it=table[i].begin();it!=table[i].end();++it)
			{
				cout<<"------>"<<*it;
			}
			cout<<endl;
		}
	}
	void deleteItem(int key) 
	{ 
  		int index = HashFunction(key);  
	    list <int> :: iterator i; 
        for (i = table[index].begin();i != table[index].end(); i++) { 
         if (*i == key) 
          break; 
    }  
  		if (i != table[index].end()) 
    	table[index].erase(i); 
	}	 
  
};
int main()
{
	int n;
	cin>>n;
	Hash h(n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		h.insertKey(a[i]);
	}
	h.displayHash();
	int key;
	cout<<"delete item";
	cin>>key;
	h.deleteItem(key);
	h.displayHash();
}
