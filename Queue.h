//Name: Danielle Lewis
//File Name: Queue.h
//Date: 11-11-14
//Program Description:
//The Cop and the Burglar
//experience with queues and templates.

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
using namespace std;

template <class Type>
class Queue
{
private:
    struct Node
    {
    Type data;
    Node* next;
    };
    Node* front, *rear;
    int count;
public:
    Queue();
    ~Queue();
    bool enqueue(Type dataIn);
    bool dequeue(Type& dataOut);
    bool isEmpty();
};




#include "Queue.cpp"
#endif
