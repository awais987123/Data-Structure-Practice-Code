#include<iostream>

using namespace std;
template<typename T>
class Node
{
public:
	T Value;
	Node<T>* Next;
    Node<T>(T d):Value(d),Next(NULL){}
};
template<typename T>
class Stack
{
private:
    int m_count;
    Node<T>* m_top;

public:
    Stack();
    bool IsEmpty();
    T Top();
    void push(T val);
    void pop();
};
template<typename T>

Stack<T>::Stack() : m_count(0), m_top(NULL) {}

template<typename T>

bool Stack<T>::IsEmpty()
{
    // return TRUE if there are no items
    // otherwise, return FALSE
    return m_count <= 0;
}

template<typename T>

T Stack<T>::Top()
{
    // Just return the value
    // of m_top node
    return m_top->Value;
}
template<typename T>

void Stack<T>::push(T val)
{
    // Create a new Node
    Node<T>* node = new Node<T>(val);

    // The Next pointer of this new node
    // will point to current m_top node
    node->Next = m_top;

    // The new Node now becomes the m_top node
    m_top = node;

    // One item is added
    m_count++;
}

template<typename T>

void Stack<T>::pop()
{
    // Do nothing if Stack is empty
    if (IsEmpty())
        return;

    // Prepare the current m_top
    // to remove
    Node<T>* node = m_top;

    // The new m_top node will be
    // the Next pointer of the current m_top node
    m_top = m_top->Next;

    // Now it's safe to remove
    // the first element
    delete node;

    // One item is removed
    m_count--;
}

bool isBalanced(string expr) {
   Stack<char> s;
   char ch;
   for (int i=0; i<expr.length(); i++) {    //for each character in the expression, check conditions
      if (expr[i]=='('||expr[i]=='['||expr[i]=='{') {    //when it is opening bracket, push into     stack
         s.push(expr[i]);
         continue;
      }
      if (s.IsEmpty())    //stack cannot be empty as it is not opening bracket, there must be closing     bracket
         return false;
         switch (expr[i]) {
            case ')':    //for closing parenthesis, pop it and check for braces and square brackets
               ch = s.Top();
               s.pop();
               if (ch=='{' || ch=='[')
                  return false;
                  break;
            case '}': //for closing braces, pop it and check for parenthesis and square brackets
               ch = s.Top();
               s.pop();
               if (ch=='(' || ch=='[')
                  return false;
                  break;
            case ']': //for closing square bracket, pop it and check for braces and parenthesis
               ch = s.Top();
               s.pop();
               if (ch =='(' || ch == '{')
                  return false;
                  break;
         }
      }
      return (s.IsEmpty()); //when stack is empty, return true
}
int main() {
   string expr = "[{}(){()}]";
   if (isBalanced(expr))
      cout << "Balanced";
   else
      cout << "Not Balanced";
}

