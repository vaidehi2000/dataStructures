#include<iostream>
#include<conio>

void TOH(int n, char frompeg, char topeg, char auxpeg)
{
	if(n==1)
   {
   	cout<<"\nMove disk 1 from "<<frompeg<<" to "<<topeg;
   	return;
   }

   /* Move n-1 disks from A to B using C*/
   TOH(n-1, frompeg, auxpeg, topeg);

   /*Move the remaining disk from A to C*/
   cout<<"\nMove disk "<<n<<" from "<<frompeg<<" to "<<topeg;

   /*Move the remaining disks from B to C using A as auxillary*/
   TOH(n-1, auxpeg, topeg, frompeg);
}



int main(void)
{
	int n;
   cout<<"Enter the number of disks\n";
   cin>>n;
   TOH(n, 'A', 'C', 'B');
	getch();
}

