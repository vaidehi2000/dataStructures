#include<limits>
#include<iostream>
#include<conio>
int second = INT_MIN;
int third = INT_MIN;

void third_greatest(int n, int arr[])
{
	int first=arr[0], i;
   	for(i=0;i<n;i++)
   	{
   		if(arr[i]>first)
      		{
         		third=second;
         		second=first;
         		first=arr[i];
      		}
      		else if(arr[i]>second)
      		{
         		third=second;
      			second=arr[i];
      		}
      		else if(arr[i]>third)
      		{
      			third=arr[i];
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

