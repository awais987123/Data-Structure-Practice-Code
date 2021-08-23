//Program to implement the Queue using linked list

/* Time Complexity:
  enQueue: O(1)
  DeQueue: O(1)
  isEmpty: O(1)
  deleteQueue: O(n)
Space Complexity: O(n)
**/
//*************HEADER FILES*************
#include<iostream>
#include<stdlib.h>
using namespace std;// 

class Node
{
public:
	int Value;
	Node* Next;
	Node(int v)
	{
		this->Value = v;
		this->Next = NULL;
	}
};
class Queue
{
private:
    int m_count;
    Node* m_front;
    Node* m_back;

public:
    Queue();
    bool IsEmpty();
    int Front();
    void Enqueue(int val);
    void Dequeue();
};

Queue::Queue() : m_count(0), m_front(NULL), m_back(NULL) {}


bool Queue::IsEmpty()
{
    // return TRUE if there's at least one item
    // otherwise, return FALSE
    return m_count <= 0;
}
int Queue::Front()
{
    // Just return the value
    // of m_front node
    return m_front->Value;
}

void Queue::Enqueue(int val)
{
    // Create a new Node
    Node* node = new Node(val);

    if (m_count == 0)
    {
        // If the queue is empty
        // the new node will be
        // m_front and m_back
        node->Next = NULL;
        m_front = node;
        m_back = m_front;
    }
    else
    {
        // If there's at least one element
        // in the queue, the current m_back element
        // won't be the Back element anymore
        // so the Next pointer of the current m_back
        // point to the new node
        m_back->Next = node;

        // The new Node now become the Back position
        m_back = node;
    }

    // One element is added
    m_count++;
}

void Queue::Dequeue()
{
    // Do nothing if list is empty
    if (m_count == 0)
        return;

    // Save the current Front
    // to a new node
    Node* node = m_front;

    // Point the Front pointer
    // to the element next to the current Front
    m_front = m_front->Next;

    // Now it's safe to remove
    // the first element
    delete node;

    // One element is removed
    m_count--;
}

int main()
{
    // NULL
    Queue queueInt = Queue();

    // Enqueue several numbers to the queue
    queueInt.Enqueue(35);
    queueInt.Enqueue(91);
    queueInt.Enqueue(26);
    queueInt.Enqueue(78);
    queueInt.Enqueue(44);
    queueInt.Enqueue(12);

    // list the element of queue
    while (!queueInt.IsEmpty())
    {
        // Get the front element
        cout << queueInt.Front() << " - ";

        // Remove the front element
        queueInt.Dequeue();
        
    }
        cout << "END" << endl;

    return 0;
}
