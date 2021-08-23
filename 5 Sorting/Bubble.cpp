#include<iostream>

void Bubble(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{	int flag=0;
		for(int j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0) break;
	}
}


int main()
{
	int a[]={3,8,1,6,0};
	int size=sizeof(a)/sizeof(int);
	Bubble(a,size);
	int i;
	for(i=0;i<size;i++)
	std::cout<<a[i]<<" ";
}
