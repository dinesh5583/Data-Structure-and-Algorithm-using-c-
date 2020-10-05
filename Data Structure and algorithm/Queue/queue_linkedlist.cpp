#include<iostream>
#include<conio.h>
using namespace std;
class node
{
  public:
  node *next;
  int data;
};
class queue_linked
{
   node *front, *rear;
   public:
   queue_linked()
   {
      front=rear=NULL;
   }
   void enqueue(int x)
   {
     node *p;
     p=new node;
     p->data=x;
     p->next=NULL;
     cout<<"inserted"<<" "<<x;
     if(front==NULL)
     {
       front=rear=p;
     }
     else
     {
       while(rear->next!=NULL)
       {
         rear=rear->next;
       }
         rear->next=p;
         rear=p;
     }
   }
   void dequeue()
   {
    if(front==NULL)
    {
      cout<<"queue empty";
    }
    else
    {
       node *temp;
       temp=front;
       front=front->next;
       cout<<"deleted"<<" "<<temp->data;
       delete temp;
    }
   }
   void display()
   {
        if(front==NULL)
        {
          cout<<"queue empty";
        }
         node *temp;
         temp=front;
         while(temp!=NULL)
         {
         cout<<temp->data<<" ";
         temp=temp->next;
         }
   }
   void deletequeue()
   {
   	node *temp=new node;
   	while(front!=NULL)
   	{
   		temp=front;
   		front=front->next;
   		delete temp;
	}
	delete front;
   }
};
main()
{
 int ch;
 queue_linked q1;
 while(1)
 {
    cout<<"\n1.enqueue\n2.dequeue\n3.display\n4.exit\n5. delete queue\n";
    cout<<"enter your choice";
    cin>>ch;
    switch(ch)
    {
        case 1:  cout<<"enter the element";
                 cin>>ch;
                 q1.enqueue(ch);
                 break;
        case 2:  q1.dequeue();
                 break;
        case 3:  q1.display();
                 break;
        case 4:  exit(0);
                 break;
        case 5:  q1.deletequeue();break;
    }
 }
}
                                  
                      
