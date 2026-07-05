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

/*
Time Complexity: O(N1+N2), where N1 is the number of nodes in the first linked list and N2 is nodes in the second linked list. We traverse both linked lists in a single pass for merging without any additional loops or nested iterations.
Space Complexity: O(1), no additonal space is used to store the elements.*/
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
