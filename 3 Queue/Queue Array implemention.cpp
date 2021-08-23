#include <iostream>//program to take input and print output on console
using namespace std;//using std as a namespace  
//defining a class for Queue
const int MAX=100;//defining a MAX as a 100
class Queue {
	int array[MAX];
	int rear;
	int front;
int count;	
	public:
		
		Queue():rear(-1),front(-1),count(0){}
		void EnQueue(int);
		int DeQueue();
		bool isempty();
		bool isfull();
		int front1();
		void print();
};
int Queue::front1()
{
	return array[front];
}
bool Queue::isempty()
{
	if(rear==-1&&front==-1)
	return true;
	else
	return false;
}
bool Queue::isfull()
{
	if(rear==MAX-1)
	return true;
	else
	return false; 
}
void Queue::EnQueue(int x)
{
	if(isempty())
	front=rear=0;
	else if(isfull())
	{
		cout<<"Que is full\n";
		return;
	}
	else{
		rear++;
	}
	array[rear]=x;
	count++;
}
int Queue::DeQueue()
{
	int x=-999;
	if(isempty())
	return 0;
	else if(rear==front)
	rear=front=-1;
	else
	{
		x=array[front];
		for(int i=front;i<rear;i++)
		array[i]=array[i+1];
	}
	count--;
	
}
void Queue::print()
{
	if(isempty())
	cout<<"Queue is empty!"<<endl;
	else{
		for(int i=0;i<count;i++)
		cout<<array[i]<<endl;
	}
}
//***********************************
//***********MAIN FUNCTION***********
//**********************************
int main() {
    Queue queue;

    queue.EnQueue(10);
    queue.EnQueue(20);
    queue.EnQueue(30);
    queue.EnQueue(50);
    queue.EnQueue(60);
    queue.EnQueue(70);
    cout<<"Queue before deletion \n";
    queue.print();
    queue.DeQueue();
    queue.DeQueue();
    queue.DeQueue();
    cout<<"Queue after deletion \n";
    queue.print();
   
}
