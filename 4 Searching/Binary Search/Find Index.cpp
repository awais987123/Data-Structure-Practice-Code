#include<iostream>

 int findCount(int a[],
               int n, 
			   int x,
			   bool searchfirst){

int low = 0;
int high = n-1;
int result = -1;

while (low <= high){

int mid = (low+high)/2;

    if(a[mid] ==x){
     result = mid;

    if(searchfirst){
     high = mid-1;

    }else{
      low = mid+1;

    }


    }

    else if (x < a[mid]) high = mid -1;
    else low = mid +1;
  }

return result;


}
int main()
{

	int a[]={2,6,6,6,7,8,9};
	int size=sizeof(a)/sizeof(int);
	int number;
	std::cout<<"|Enter the number :";std::cin>>number;
	int i=findCount(a,size,number,true);
	if(i!=-1)
	std::cout<<"Element fount at index = "<<i<<std::endl;
	else
	std::cout<<"Element is not found";
}
