#include<iostream>

int BinarySearch(int a[],
                int n,
			    int value)
{
	int low=0;
	int high=n-1;
	while(low<=high)
	{
	int mid =low +(high-low)/2;
	if(a[mid]==value) return mid;
	else if(value<a[mid])
	{
		high=mid-1;
	}
	else
	{
		low=mid+1;
	}
}
return -1;
}
int main()
{
	int a[]={2,4,7,28,35,98};
	int size= sizeof(a)/sizeof(int);
	int number;
	std::cout<<"Enter the number = ";std::cin>>number;
	int i=BinarySearch(a,size,number);
	if(i!=-1)
	std::cout<<"element found at index "<<i<<std::endl;
	else
	std::cout<<"not found";
	
}
