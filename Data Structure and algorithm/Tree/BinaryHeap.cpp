#include<iostream>
#include<conio.h>
using namespace std;
class heap{
      public:
      int *arr;
      int capacity;
      int heap_size;
};
class maxheap{
      public:
             heap *createheap(int cap)
             {
                  heap*h;
                  h=new heap;
                  h->heap_size=0;
                  h->capacity=cap;
                  h->arr=new int[cap];
                  return h;
             }
             void insert(heap *h,int x)
             {
                  
                  if(h->heap_size==h->capacity)
                  {
                      cout<<"Overflow"<<endl;
                      return;
                  }
                  h->heap_size++;                 //heap_size=1 for first element;
                  int i=h->heap_size-1;
				  h->arr[i]=x;               //i=0 for first element
                  while(i>=0 && x>h->arr[(i-1)/2])
                  {
                       int temp=h->arr[i];
                       h->arr[i]=h->arr[(i-1)/2];
                       h->arr[(i-1)/2]=temp;
                       i=(i-1)/2;
                  } 
                  cout<<"inserted"<<h->arr[i]<<endl;
               }
               void del(heap *h)
               {
                    int data;
                    if(h->heap_size==0)
                    {
                        cout<<"underflow or empty";
                        return;
                        }
                    if(h->heap_size==1)
                    {
                    	data=h->arr[0];
                    	h->heap_size--;
                    	return;
					}
                    data=h->arr[0];
                    h->arr[0]=h->arr[h->heap_size-1];
                    h->heap_size--;
                    max_heapify(h,0);
               }
               void max_heapify(heap *h,int i)
               {
                    int l,r,largest,temp;
                    l=(2*i)+1;
                    r=(2*i)+2;
                    if(l!=0 && h->arr[l]>h->arr[i] && l<h->heap_size) 
                            largest=l;
                    else largest=i;
                    if(r!=0 && h->arr[largest]<h->arr[r] && r<h->heap_size)
                    {
                       largest=r;
                    }
                    if(largest!=i)
                    {
                       temp=h->arr[i];
                       h->arr[i]=h->arr[largest];
                       h->arr[largest]=temp;
                    	max_heapify(h,largest);
                	}
               }
               void dis(heap *h)
               {
                    if(h->heap_size==0)
                    {
                       cout<<"no element";
                       return;
                    }
                    for(int i=0;i<h->heap_size;i++)
                    {
                            cout<<endl<<h->arr[i];
                    }
               }
      
}; 
  
 main()
 {
       maxheap h;
      heap *p= h.createheap(10);
      h.insert(p,3);
      h.insert(p,2);
      h.insert(p,6);
      h.insert(p,1);
      h.insert(p,17);
	  h.insert(p,11); 
      h.insert(p,0);
      h.dis(p);
      h.del(p);
      h.del(p);
      h.del(p);
      h.del(p);
      h.del(p);
      h.del(p);
	  h.del(p);
      h.dis(p);
}
                      
                    
                    
                    
                    
                    


