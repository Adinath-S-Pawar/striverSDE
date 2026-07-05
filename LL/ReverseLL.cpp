#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
        
// TC-O(n) SC - O(1)
Node* reverseLinkedList(Node *head)
{
    if(head == NULL || head->next == NULL) return head;

    Node* curr = head;
    Node* forward = NULL;
    Node* prev = NULL;

    while(curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;
    return head;
}


int main()
{
    return 0;
}
