#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class dyqueue
{
	public:
	int capacity;
	int front,rear;
	int *array;
};
class queue{
public:
	dyqueue *q=new dyqueue;
	queue()
	{
		q->front=q->rear=-1;
		q->capacity=1;
		q->array=new int[q->capacity];
	}
	void enqueue(int x)
	{
		
		if(isfull(q))
		{
			resizequeue(q);
		}
		q->rear=(q->rear+1)%q->capacity;
		q->array[q->rear]=x;
		cout<<"inserted"<<x;
		if(q->front==-1)
		{
			q->front=q->rear;
		}
	}
	void resizequeue(dyqueue *q)
	{
		int size=q->capacity;
		q->capacity=q->capacity*2;
		q->array=(int*) realloc(q->array,q->capacity * sizeof(int));
		if(q->front>q->rear)
		{
			for(int i=0;i<q->front;i++)								//when the size of array is full so we insert all the previos elemrnt from front to the new block after the rear
			{
				q->array[i+size]=q->array[i];
			}
			q->rear=q->rear+size;
		}
		
	}
	void peek()
	{
		cout<<q->array[q->front];
	}
	void capacity()
	{
		cout<<q->capacity;
	}
	void dequeue()
	{
		int x;
		if(isempty(q))
		{
			cout<<"queue is empty";
		}
		else if(q->rear==q->front)
		{
			q->front=q->rear=-1;
		}
		else
		{
		x=q->array[q->front];
		q->front=(q->front+1)%q->capacity;
		}
	}		
	int isfull(dyqueue *q)
	{
		return (q->rear+1)%q->capacity==q->front;
	}
	int isempty(dyqueue *q)
	{
		return q->front==-1;
	}
	void display()
	{
		if(isempty(q))
		{
			cout<<"queue is empty";
			return;
		}
		if(q->rear>=q->front)
		{
			for(int i=q->front;i<=q->rear;i++)
			{
				cout<<q->array[i]<<" ";
			}
		}
		else
		{
			int i;
			for(i=q->front;i<q->capacity;i++)
			{
				cout<<q->array[i];
			}
			for(i=0;i<=q->rear;i++)
			{
				cout<<q->array[i];
			}
		}
		
	}
};
int main()
{
     int ch;
     queue st;
     while(1)
        {
             cout <<"\n1.enqueue  2.dequeue  3.display 4.peek or top 5.exit 6.show capacity\nEnter ur choice";
             cin >> ch;
             switch(ch)
              {
               case 1:  cout <<"enter the element";
                        cin >> ch;
                        st.enqueue(ch);
                        break;
               case 2:  st.dequeue();  break;
               case 3:  st.display();break;
               case 4: st.peek(); break;
               case 5:  exit(0);
               case 6: st.capacity(); break;
               }
         }
}
