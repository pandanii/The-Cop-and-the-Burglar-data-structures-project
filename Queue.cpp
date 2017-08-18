//Name: Danielle Lewis
//File Name: Queue.cpp
//Date: 11-11-14
//Program Description:
//The Cop and the Burglar
//experience with queues and templates.


# include <iostream>
# include "Queue.h"
using namespace std;

//======================================
template <class Type>
Queue<Type>::Queue()
{
front = rear = NULL;
count = 0;
}
//======================================
template <class Type>
Queue<Type>::~Queue()
{
Type x;
while(dequeue(x));
}
//======================================
template <class Type>
bool Queue<Type>::enqueue(Type dataIn)
{
Node* pNew = new Node;
pNew-> data = dataIn;
if (pNew == NULL)
    return false;
pNew->next = NULL;
if (front == NULL)
    front = rear = pNew;
else
    {
    rear->next = pNew;
    rear = pNew;
    }
count++;
return true;
}
//======================================
template <class Type>
bool Queue<Type>::dequeue(Type& dataOut)
{
if (count == 0)
    return false;
Node* temp = new Node;
temp = front;
dataOut = temp->data;
front = front->next;
if(front==NULL)
    rear = NULL;
delete temp;
count--;
return true;
}
//======================================
template <class Type>
bool Queue<Type>::isEmpty()
{
return (count == 0);
}
//======================================
