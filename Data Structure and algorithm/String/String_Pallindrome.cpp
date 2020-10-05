/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<string.h>
#include <stdio.h>
int main()
{
    char *str="abccba";
	int l=strlen(str);
  int arr[l],top=-1;;
  for(int i=0;i<l;i++)
  {
    ++top;
    arr[top]=str[i];
	}
	for(int i=0;i<l;i++)
	{
	    if((arr[top--])==arr[i])
	    {
	        printf("YES");
	    }
	    else{
	        printf("NO");
	    }
	}
}

