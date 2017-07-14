#include<iostream>
#include<conio>

int main(void)
{
	int n,i,j,temp,count=0;
   int ar[10];
   cout<<"Enter the number of elements\n";
   cin>>n;
   cout<<"\nEnter the elements\n";
   for(i=0;i<n;i++)
	{
   	cin>>ar[i];
   }

   /*sorting the array using bubblesort*/
   for(i=0;i<n;i++)
   {
   	for(j=0;j<n-i-1;j++)
      {
      	if(ar[j]>ar[j+1])
         {
         	temp=ar[j];
            ar[j]=ar[j+1];
            ar[j+1]=temp;
         }
      }
   }

   cout<<endl;

   for(i=0;i<n;i++)
   {
   	cout<<ar[i]<<" ";
   }

   for(i=0;i<n;i++)
   {
   	if(ar[i]==ar[i+1])
      {
      	count++;
      }
   }

   cout<<"\nThe number of similar occurences are "<<count;
   getch();
}

