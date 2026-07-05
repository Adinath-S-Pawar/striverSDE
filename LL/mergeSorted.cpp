#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* dummy = new Node<int>(-1);
    Node<int>* temp = dummy;

    while(first != NULL && second != NULL)
    {
        if(first->data <= second->data)
        {
            temp->next = first;
            first = first->next;
        }
        else
        {
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }

    if(first != NULL)
    {
        temp->next = first;
    }
    if(second != NULL)
    {
        temp->next = second;
    }

    return dummy->next;
}
