#include<limits>
#include<iostream>
#include<conio>
int second = INT_MIN;
int third = INT_MIN;

void third_greatest(int n, int ar[])
{
	int first=ar[0], i;
   for(i=0;i<n;i++)
   {
   	if(ar[i]>first)
      {
         third=second;
         second=first;
         first=ar[i];
      }
      else if(ar[i]>second)
      {
         third=second;
      	second=ar[i];

      }
      else if(ar[i]>third)
      {
      	third=ar[i];
      }
   }
   cout<<"\nThe third largest element is :"<<third;
   return ;
}
int main(void)
{
	int n, ar[10],i;
   cout<<"Enter number of elements\n";
   cin>>n;
   cout<<"\nEnter the elements\n";
   for(i=0;i<n;i++)
   {
   	cin>>ar[i];
   }
   third_greatest(n,ar);
   getch();
}

