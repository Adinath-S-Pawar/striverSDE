#include<iostream>
using namespace std;

/*
You are given a Singly Linked List of integers and a reference to the node to be deleted. 
Every node of the Linked List has a unique value written on it. Your task is to delete that node from the linked list.
A singly linked list is a linear data structure in which we can traverse only in one direction i.e. 
from Head to Tail. It consists of several nodes where each node contains some data and a reference to the next node.

Note:
• The reference to the head of the linked list is not given.
• The node to be deleted is not a tail node.
• The value of each node in the Linked List is unique.
• It is guaranteed that the node to be deleted is present in the linked list.*/

#include <bits/stdc++.h>

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


void deleteNode(LinkedListNode<int> * node) {
    node->data = node->next->data;
    node->next = node->next->next;
}
int main()
{
    return 0;
}