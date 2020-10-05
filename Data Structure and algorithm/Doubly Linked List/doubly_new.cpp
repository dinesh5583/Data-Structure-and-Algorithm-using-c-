#include<iostream>
#include<stdio.h>
using namespace std;
class node
{
	public:
	int data;
	node *prev;
	node *next;
};
class ddl
{
	public:
		node *head;
		ddl()
		{
			head=NULL;
		}
		void insert(int x)
		{
			node *temp,*tail;
			temp=new node;
			temp->data=x;
			temp->next=NULL;
			if(head==NULL)
			{
				temp->prev=NULL;
				head=temp;
				cout<<"inserted "<<x;
			}
			else
			{
				tail=head;
				while(tail->next!=NULL)
				{
					tail=tail->next;
				}
				tail->next=temp;
				temp->prev=tail;
				cout<<"inserted "<<x;
			}
		}
		void atbeg(int x)
		{
			if(head==NULL)
			{
				cout<<"list is empty";
				return;
			}
			node *temp;
			temp=new node;
			temp->data=x;
			temp->prev=NULL;
			temp->next=head;
			head->prev=temp;
			head=temp;
			cout<<"inserted"<<x;
		}
		void atend(int x)
		{
			node *temp,*tail;
			temp=new node;
			temp->data=x;
			temp->next=NULL;
			if(head==NULL)
			{
				cout<<"List is empty";
			}
			tail=head;
			while(tail->next!=NULL)
			{
				tail=tail->next;
			}
			tail->next=temp;
			temp->prev=tail;
		}
		void atany(int x,int position)
		{
			node *temp,*tail;
			int k=1;
			if(head==NULL)
			{
				cout<<"list is empty";
				return;
			}
			temp=new node;
			temp->data=x;
			if(position==1)
			{
				temp->next=head;
				temp->prev=NULL;
				head->prev=temp;
				head=temp;
				return;
			}
			   tail=head;
			   while(tail->next!=NULL && (k<position-1))
			     {
				   k++;
				   tail=tail->next;
			     }
			     if(k+1!=position)
			     {
			     	cout<<"position is invalid";
			     	return;
				 }
			     tail->next->prev=temp;
			     temp->next=tail->next;
			     tail->next=temp;
			     temp->prev=tail;
		}
		void deleteatany(int position)
		{
			node *tail;
			int k=1;
			if(head==NULL)
			{
				cout<<"list is empty";
				return;
			}
			tail=head;
			if(position==1)
			{
				head=head->next;
				head->prev=NULL;
				delete tail;
				return;
			}
			while(tail->next!=NULL && k<position)
			{
				tail=tail->next;
				k++;
			}
				if(k==position && tail->next==NULL)
			{
				tail->prev->next=NULL;
				delete tail;
				return;
			}
		/*	if(k!=position)
			{
				cout<<"invalid position";
				return;
			}*/
			tail->prev->next=tail->next;
			tail->next->prev=tail->prev;
			delete tail;
			
		}
		void display()
		{
			node *tail;
			tail=head;
			while(tail!=NULL)
			{
				cout<<tail->data<<"\n";
				tail=tail->next;
			}
		}
};
 main()
 {
    int ch,k,i;
    ddl a;
    while(1)
    {
        cout<<"\n1.create list\n2.insert at beg\n3.at end\n4.insert at any\n5.display\n6delete at any\n7.exit\n";
        cout<<"enter your choice \t";
        cin>>ch;
        switch(ch)
             {
             case 1: cout<<"enter number of elements in list";
             		  cin>>k;
             		  for(i=0;i<k;i++)
             		  {
			 		 cout<<"\n enter the element";
                     cin>>ch;     
                     a.insert(ch);
                 	  }	
                     break;
            case 2: cout<<"enter the element";
                     cin>>ch;     
                     a.atbeg(ch);
                     break;
            case 3: cout<<"enter the elemnt";
            		cin>>ch;
            		a.atend(ch);
            		break;
             case 4: cout<<"enter the element";
            		cin>>ch;
            		cout<<"enter the position where element will store";
            		cin>>k;
            		a.atany(ch,k);
            		break;           
             case 5: a.display();
                     break;
            case 6: cout<<"enter the position you want to delete in list";
             		 cin>>ch;
             		 a.deleteatany(ch);
             		 break;			
			 case 7: exit(0);        
                             
             }
             cout<<"\n";
    }      
}    
