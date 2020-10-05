#include<iostream>
#include<conio.h>
using namespace std;
void ShellSort(int [],int);
main(){
    int a[]={8,10,22,3,1,5,9,44,11,6,2},n=11;
    ShellSort(a,n);
    for(int i=0;i<n;i++)
    {
       cout<<a[i]<<"\t";
    }
   getch();
}
void ShellSort(int a[],int n)
{
     int i,j,gap,temp;
     for(gap=n/2;gap>=1;gap/=2)
     {
         for(j=gap;j<n;j++)
         {
           for(i=j-gap;i>=0;i=i-gap)              //iterate only one time
           {
              if(a[i]<a[i+gap])
              {
                break;
              }
              else
              {
                  temp=a[i];
                a[i]=a[i+gap];
                a[i+gap]=temp;
              }
           }
         }
     }
}
