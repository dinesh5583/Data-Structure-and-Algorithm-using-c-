#include<iostream>
#include<conio.h>
using namespace std;
class node
{
          public:
          int data;
          node *next;
};
class linked_list
{
      public:
      node *head;
      linked_list()
         {
           head=NULL;
         }
      void insert(int x)
           {
              node *tail, *temp;
              temp=new node;
              temp->data=x;
              temp->next=NULL;
              if(head==NULL)
                   {
                        head=temp;
                   }
                 else
                 {
                      tail=head;
                      while(tail->next!=NULL)
                          {
                             tail=tail->next;
                          }
                             tail->next=temp;
                  }
			}
			void atbeg(int x)
			{
				node *temp;
				temp=new node;
				temp->data=x;
				temp->next=NULL;
				if(head==NULL)
				{
					cout<<"list is empty";
				}
				else
				{
					temp->next=head;
					head=temp;
				}
			}
			void atend(int x)
			{
				node *temp,*tail;
				temp=new node;
				temp->data=x;
				temp->next=NULL;
				if(head==NULL)
				{
					cout<<"first create list";
				}
				else
				{	tail=head;
					while(tail->next!=NULL)
					{
						tail=tail->next;
					}
					tail->next=temp;	
				}
			}
			void atany(int x,int position)
			{
				int k=1;
				node *temp,*p,*q;
				temp=new node;
				temp->data=x;
				p=head;
				if(position==1)
				{
				  temp->next=head;
				  head=temp;	
				}
				else
				{
					while(p!=NULL && k<position)
					{
						k++;
						q=p;
						p=p->next;
					}
					q->next=temp;
					temp->next=p;
				}
				
			}
			void deleteatany(int position)
			{
				node *temp,*p,*q;
				int k=1;
				if(head==NULL)
				{
					cout<<"list empty";
					return;
				}
				else
				p=head;
				if(position==1)
				{
					head=head->next;
					delete p;
				}
				else
				{
					while(p!=NULL && k<position)
					{
						k++;
						q=p;
						p=p->next;
					}
					if(p==NULL)
					{
						cout<<"element does not exist";				//if position is out of index
						return;
					}
					else{
					    q->next=p->next;
					    delete p;
					}
				}
				if(p->next==NULL)
				{
					q->next=NULL;
					delete p;
				}
			}
		void display()
      {
           node *tail;
           tail=head;
           if(head==NULL)
           {
               cout<<"list is empty";
           }
           while(tail!=NULL)
           {
           cout<<tail->data<<" ";
           tail=tail->next;
           }
      }
};
 main()
 {
    int ch,k;
    linked_list a;
    while(1)
    {
        cout<<"\n1.create list\n2.insert at beg\n3.at end\n4.insert at any\n5.display\n6delete at any\n7.exit\n";
        cout<<"enter your choice";
        cin>>ch;
        switch(ch)
             {
             case 1: cout<<"enter the element";
                     cin>>ch;     
                     a.insert(ch);
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
    }      
}    
