#include<iostream>
#include<conio.h>
using namespace std;
class node
{
    public:
     node *next;
     int data;
};
class circular_linked
{
   int n,x,c,i;
   node *last;
   public:
   int create_list()
   {
     node *last;
     cout<<"how many values you want to enter";
     cin>>n;
     cout<<"enter first data for the list";
     cin>>x;
     last=addtoempty(x);
     for(i=2;i<=n;i++)
     {
       cout<<"enter data for the list";
       cin<<x;
     last=addatend(x);
     }
   }
   void addtoempty(int x)
   {
      node *p;
      p=new node;
      p->data=x;
      last=p;
      last->next=last;
      cout<<"inserted"<<" "<<x;
   }
    void addatend(int x)                     //add at end
       {
         node *p;
         p=new node;
         p->data=x;
         p->next=last->next;
         last->next=p;
         last=p;
         cout<<"inserted"<<" "<<x;
       }
   void addatbeg(int x)        //add at begining
      {
         node *p;
         p=new node;
         p->data=x;
         p=last->next;
         last->next=p;
         cout<<"inserted"<<" "<<x;
      }
    void addafter(int x,int y)
    {  
      node *t;
      t=last->next;
      node *p;
      p=new node;
      p->data=x;
      cout<<"inserted"<<" "<<x;
      do
      {
        if(t->data==y)
        {
          p->next=t->next;
          t->next=p;
          if(t==last)
          {
            last=p;
          }
        }
        t=t->next;
      }
      while(t!=last->next);
    cout<<y<<" "<<"is not in the list";
   }
   void deletion(int y)
   {   
     node *n, *t;
     if(last==NULL)              //when list is empty
     {
        cout<<"list is empty";
     }
     if(last==last->next && last->data==y)   //when one list is availabe
     {
        t=last;
        last=NULL;
        cout<<"deleted"<<t->data;
        free(t);
     }
     if(last->next->data==y)        //delete first list           
      {
         t=last->next;
         last->next=t->next;
         cout<<"deleted"<<t->data;
         free(t);
      }
      n=last->next;
      while(n->next!=last)
      {
         if(n->next->data==y)
         {
           t=n->next;
           n->next=t->next;
           cout<<"deleted"<<t->data;
           free(t);
         }
         n=n->next;
      }
      if(last->data==y)
      {
       t=last;
       n->next=last->next;
       last=n;
       cout<<"deleted"<<" "<<t->data;
       free(t);
      }
      if(t->data!=y)
      cout<<y<<" "<<"is not in list";
   }
   void display()
   {
    node *t;
    if(last==NULL)
    {
      cout<<"list is empty";
    }
    else
    {
      t=last->next;
      do
      {
        cout<<t->data<<" ";
        t=t->next;
      }
      while(t!=last->next);
    }
   }
};
main()
{
  node *start=NULL;
  int ch,y;
  circular_linked c1;
  while(1)
  {
    system("cls");
    cout<<"\n1.create list\n2.add at end\n3.add at begining of list\n4.add between the list\n5.deletion\n6.display\n7.exit\n";
    cout<<"enter your choice"<<" ";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"enter a number for the list";
              cin>>ch;
              c1.create_list(ch);
              break;
      case 2: cout<<"enter a number for the list";
              cin>>ch;
              c1.addatend(ch);
              break;        
      case 3: cout<<"enter a number insert in begining of the list";
              cin>>ch;
              c1.addatbeg(ch);
              break;
      case 4: cout<<"enter a number";
              cin>>ch;
              cout<<"enter value after new value to be inserted";
              cin>>y;
              c1.addafter(ch,y);
              break;
      case 5: cout<<"enter the no. you want to delete it";
              cin>>ch;
              c1.deletion(ch);
              break;
      case 6: c1.display();
              break;
      case 7: exit(0);
              break;
    }
    cout<<"\n \n \n";
  }        
}
              
                             
    
   
        
