#include <iostream>

template <typename T>
class D_Node
{
    public:
        T data;
        D_Node<T> * prev;
        D_Node<T> * next;

        D_Node(T data);
};

template <typename T>
D_Node<T>::D_Node(T data)
    : data(data), prev(NULL), next(NULL) {}

template <typename T>
class DoublyLinkedList
{
    private:
        int m_count;

    public:
        D_Node<T> * head;

        D_Node<T> * tail;

        DoublyLinkedList();

         D_Node<T> * Get(int index);

        // Insert() operation
        void Inserthead(T val);
        void Inserttail(T val);
        void Insert(int index, T val);

        // Search() operation
        int Search(T val);

        // Remove() operation
        void Removehead();
        void Removetail();
        void Remove(int index);

        // Additional operation
        int Count();
        void PrintList();
        void PrintListBackward();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
    : m_count(0), head(NULL), tail(NULL) {}

template <typename T>
D_Node<T> * DoublyLinkedList<T>::Get(int index)
{
    // Check if the index is out of bound
    if(index < 0 || index > m_count)
        return NULL;

    // Start from the head
    D_Node<T> * node = head;

    // Iterate through the linked list elements
    // until it finds the selected index
    for(int i = 0; i < index; ++i)
    {
        node = node->next;
    }

    // Simply return the node result
    return node;
}

template <typename T>
void DoublyLinkedList<T>::Inserthead(T val)
{
    // Create a new Node
    D_Node<T> * node = new D_Node<T>(val);

    // The current head will no longer become a head
    // so the next pointer of the new Node will
    // point to the current head
    node->next = head;

    // If the current head is exist,
    // the prev pointer of the current head
    // should point to the node
    if(head != NULL)
        head->prev = node;

    // The new Node now become the head
    head = node;

    // If the linked list is empty
    // The tail is also the head
    if(m_count == 0)
        tail = head;

    // One element is added
    m_count++;
}

template <typename T>
void DoublyLinkedList<T>::Inserttail(T val)
{
    // If the linked list is empty,
    // just simply invoke Inserthead()
    if(m_count == 0)
    {
        Inserthead(val);
        return;
    }

    // Create a new Node
    D_Node<T> * node = new D_Node<T>(val);

    // The current tail will no longer become a tail
    // so the next pointer of the current tail will
    // point to the new node
    tail->next = node;

    // Also, the prev pointer of the new node
    // should point to the current tail
    node->prev = tail;

    // The new Node now become the tail
    tail = node;

    // One element is added
    m_count++;
}

template <typename T>
void DoublyLinkedList<T>::Insert(int index, T val)
{
    // Check if the index is out of bound
    if(index < 0 || index > m_count)
        return;

    // If inserting a new head
    if(index == 0)
    {
        Inserthead(val);
        return;
    }
    // If inserting a new tail
    else if(index == m_count)
    {
        Inserttail(val);
        return;
    }

    // Start to find prev node
    // from the head
    D_Node<T> * prevNode = head;

    // Traverse the elements until
    // the selected index is found
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->next;
    }

    // Create the next node which is
    // the element after prev node
    D_Node<T> * nextNode = prevNode->next;

    // Create a new node
    D_Node<T> * node = new D_Node<T>(val);

    // Insert this new node between
    // the prev node and the next node
    node->next = nextNode;
    node->prev = prevNode;
    prevNode->next = node;
    nextNode->prev = node;

    // One element is added
    m_count++;
}

template <typename T>
int DoublyLinkedList<T>::Search(T val)
{
    // If LinkedList is empty,
    // just return NOT_FOUND
    if(m_count == 0)
        return -1;

    // Need to count the index
    int index = 0;

    // Traverse from the head node
    D_Node<T> * node = head;

    // Traverse until the selected data
    // is matched with the data
    // of the current position,
    while(node->data != val)
    {
        index++;
        node = node->next;

        // This will happen
        // if the selected data
        // is not found
        if(node == NULL)
        {
            return -1;
        }
    }

    return index;
}

template <typename T>
void DoublyLinkedList<T>::Removehead()
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // Save the current head
    // to a new node
    D_Node<T> * node = head;

    // Point the head Pointer
    // to the element next to the current head
    head = head->next;

    // Now it's safe to remove
    // the first element
    delete node;

    // If there's still any element in the list,
    // the prev pointer of the head
    // should point to NULL
    if(head != NULL)
        head->prev = NULL;

    // One element is removed
    m_count--;
}

template <typename T>
void DoublyLinkedList<T>::Removetail()
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // If List element is only one
    // just simply call Removehead()
    if(m_count == 1)
    {
        Removehead();
        return;
    }

    // Save the current tail
    // to a new node
    D_Node<T> * node = tail;

    // Point the tail Pointer
    // to the element before the current tail
    tail = tail->prev;

    // Set the new next pointer of the new tail
    // to NULL since we are going to delete
    // the last element
    tail->next = NULL;

    // Now it's safe to remove
    // the last element
    delete node;

    // One element is removed
    m_count--;
}

template <typename T>
void DoublyLinkedList<T>::Remove(int index)
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // Do nothing if index is out of bound
    if(index < 0 || index >= m_count)
        return;

    // If removing the current head
    if(index == 0)
    {
        Removehead();
        return;
    }
    // If removing the current tail
    else if(index == m_count - 1)
    {
        Removetail();
        return;
    }

    // Start to traverse the list
    // from the head
    D_Node<T> * prevNode = head;

    // Find the element before
    // the selected index
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->next;
    }

    // The removed element is after
    // the prevNode
    D_Node<T> * node = prevNode->next;

    // The nextNode will be the neighbor of
    // prevNode if the node is removed
    D_Node<T> * nextNode = node->next;

    // Link the prevNode to nextNode
    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    // It's now safe to remove
    // the selected index element
    delete node;

    // One element is removed
    m_count--;
}

template <typename T>
int DoublyLinkedList<T>::Count()
{
    return m_count;
}

template <typename T>
void DoublyLinkedList<T>::PrintList()
{
    D_Node<T> * node = head;

    while(node != NULL)
    {
        std::cout << node->data << " -> ";
        node = node->next;
    }

    std::cout << "NULL" << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::PrintListBackward()
{
    D_Node<T> * node = tail;

    while(node != NULL)
    {
        std::cout << node->data << " -> ";
        node = node->prev;
    }

    std::cout << "NULL" << std::endl;
}
using namespace std;

int main()
{
     DoublyLinkedList<int> linkedList = DoublyLinkedList<int>();

    // it will be printed backwardly
    // 43->NULL
    linkedList.Inserthead(43);

    // 43->76->NULL
    linkedList.Inserthead(76);

    // 15->43->76->NULL
    linkedList.Inserttail(15);

    // 44->15->43->76->NULL
    linkedList.Inserttail(44);

    // Print the list element
    cout << "First Printed:" << endl;
    linkedList.PrintList();
    cout << endl;
cout << "Second Printed:" << endl;
    linkedList.PrintListBackward();
    cout << endl;

    return 0;
}
