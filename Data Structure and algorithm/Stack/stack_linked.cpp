#include<iostream>
#include<conio.h>
using namespace std;
class node
{
   public:
   int data;
   node *next;
};
class stack_linked
{
   node *top;
   public:
   stack_linked()
         {
             top=NULL;
         }
   void push(int x)
   {
       node *p;
       p=new node;
       p->data=x;
       p->next=NULL;
       cout<<"inserted"<<p->data;
       p->next=top;
       top=p;
   }
   void pop()
    {
      if(top!=NULL)
        {
          node *temp;
          temp=top;
          top=top->next;
          cout<<"deleted"<<temp->data;
          delete temp;
        }
        else
        {
        cout<<"stack empty";
        }
   }
   void display()
    {
      if(top==NULL)
        {
         cout<<"stack is empty";
         return;
        } 
       node *tail;
       tail=top;
       while(tail!=NULL)
           {
            cout<<tail->data<<" ";
            tail=tail->next;
           }
       
    }
    void peek()
    {
    	if(top==NULL)
    	{
    		cout<<"list is empty";
		}
		else{
			cout<<"peek element is "<<top->data;
		}
	}
};
main()
{
     int ch;
     stack_linked s1;
     while(1)
        {
             cout <<"\n1.push 2.pop 3.display 4.exit\nEnter your choice";
             cin >> ch;
             switch(ch)
              {
               case 1:  cout <<"enter the element";
                        cin >> ch;
                        s1.push(ch);
                        break;
              case 2:  s1.pop(); break;
              case 3:  s1.display();
                       break;
              case 4:  exit(0);
                       break;
              case 5:  s1.peek(); break;
               }
         }
}                   

            
             
   
   
