#include<iostream>
#include<conio>

int sum(int a,int b)
{
	int s;
   s=a+b;
   cout<<"\nSum is "<<s;
   return 0;
}

int main(void)
{
	int a,b;
   int *aptr,*bptr;
   cout<<"Enter two numbers\n";
   cin>>a>>b;
   aptr=&a,
   bptr=&b;
   sum(*aptr,*bptr);
   getch();
}
