#include<iostream>
#include<stdio.h>
#define maxsize 5;
using namespace std;
class arraystack{
	public:
      int capacity;
      int top;
      int *array;
};
class stack{
      public:
      	arraystack *s;
             stack(){
             			s=new arraystack;
                        s->capacity=maxsize;
                        s->top=-1;
                        s->array=new int[s->capacity];
                    }
             int isempty(arraystack *s)
             {
             
                return s->top==-1;
             }
             int isfull(arraystack *s)
             {
                  return s->top==s->capacity-1;
             }
             void push(int x)
             {
                  if(isfull(s))
                  {
                            cout<<"overflow";
                  }
                  else{
                       s->array[++s->top]=x;
       				 }
             }
             void pop()
             {
                  if(isempty(s))
                  {
                        cout<<"underflow";
                  }
                  else
                  {
                       s->array[s->top--];
                  }
               }
               void peek()
               {
                    if(isempty(s))
                    {
                          cout<<"empty";
                    }
                    else
                    {
                        cout<<"peek item is "<<s->array[s->top];
                        }
               }
               void display()
               {
               	for(int i=s->top;i>=0;i--)
               	{
               		cout<<s->array[i]<<" ";
				   }
               	
			   }
};
main()
{
     int ch;
     stack st;
     while(1)
        {
             cout <<"\n1.push  2.pop  3.display 4.peek or top 5.exit\nEnter ur choice";
             cin >> ch;
             switch(ch)
              {
               case 1:  cout <<"enter the element";
                        cin >> ch;
                        st.push(ch);
                        break;
               case 2:  st.pop();  break;
               case 3:  st.display();break;
               case 4: st.peek(); break;
               case 5:  exit(0);
               }
         }
}
    
                      
                             
                       
