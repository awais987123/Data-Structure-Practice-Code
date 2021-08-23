#include<iostream>

void selection(int a[],int n)
{
	
	
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]>=a[min])
			min=j;
		}
	int	temp=a[i];
	a[i]=a[min];
	a[min]=temp;
	
	}
}


int main()
{
	int a[]={3,8,1,6,0};
	int size=sizeof(a)/sizeof(int);
	selection(a,size);
	int i;
	for(i=0;i<size;i++)
	std::cout<<a[i]<<" ";
}
