#include<iostream>

int binarySearch(int a[],
                 int low,
                 int high,
				 int value)
{
      if(low<=high)
	  {
			  
	  int mid=low+(high-low)/2;
	  if(a[mid]==value) return mid;
	  else if(value<a[mid])
	  return binarySearch(a,low,mid-1,value);
	  else if(value>a[mid])
	  return binarySearch(a,mid+1,high,value);
   	}
	   	return -1;
}

int main()
{
	int a[]={2,7,89,115,117,225,346,498,537};
	int size=sizeof(a)/sizeof(int);
	int num;
	std::cout<<"Enter the number =";std::cin>>num;
	int i=binarySearch(a,0,size,num);
	if(i!=-1) std::cout<<"element found in position "<<i+1<<std::endl;
	else
	std::cout<<"element not found"; 
}
