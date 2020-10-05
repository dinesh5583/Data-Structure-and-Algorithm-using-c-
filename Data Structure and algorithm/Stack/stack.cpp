#include<iostream>
#include<conio.h>
#define maxsize 5
using namespace std;
class stack
{
             int stk[maxsize];
             int top;
      public:
             stack()
              {
                top=-1;
               }
             void push(int x)
              {
                 if(top == maxsize-1)
                       {
                           cout <<"stack overflow";
                           return;
                       }
                 top++;     
                 stk[top]=x;
                 cout <<"inserted" <<x;
               }
             void pop()
               {
               	int temp;
                  if(top==-1)
                   {
                         cout <<"stack underflow";
                         return;
                    }                    
                    temp=stk[top];
                    top--;
                    cout <<"deleted" <<temp;
                }
                void peek(){
                	if(top==-1){
                		cout<<"stack is empty";
                		return;
					}
					cout<<stk[top];
				}
            
             void display()
               {
                   if(top==-1)
                    {
                            cout <<" stack is empty";
                            return;
                    }
                    for(int i=top;i>=0;i--)
                    cout <<stk[i] <<" ";
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
