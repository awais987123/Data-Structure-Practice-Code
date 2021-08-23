#include<iostream>

//First occurance
int BinarySearch1(int a[],
                 int n,
				 int value)
{
	int low=0;
	int high=n-1;
	int result =-1;
	while(low<=high)
	{
		int mid=low +(high-low)/2;
		if(a[mid]==value)
		{
			result=mid;
			high=mid-1;
		}
		else if(a[mid]>value)
		high=mid-1;
		else
		low=mid+1;
	}
	return result;
}
//Last occurance
int BinarySearch2(int a[],
                 int low,
                 int high,
				 int value)
{
	int result =-1;
	int mid=low +(high-low)/2;
	if(low<=high)
	{
	
		if(a[mid]==value)
		{
		result=mid;
		 BinarySearch2(a,mid+1,high,value);
		}
		else if(a[mid]>value)
		 BinarySearch2(a,mid+1,high,value);
		else
		 BinarySearch2(a,low,mid-1,value);
	}
	return result;
}
int main()
{
	int a[]={2,6,6,6,7,8,9};
	int size=sizeof(a)/sizeof(int);
	int number;
	std::cout<<"|Enter the number :";std::cin>>number;
	int i=BinarySearch1(a,size-1,number);
	if(i!=-1)
	std::cout<<"Element fount at index = "<<i<<std::endl;
	else
	std::cout<<"Element is not found";
}
