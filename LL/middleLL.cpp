#include<iostream>
using namespace std;

int main()
{
    return 0;
}

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

Node *findMiddle(Node *head) {
  
    Node * student = head;
    Node * teacher = head;

    if(head == NULL)
    {
        return NULL;
    }
    while((teacher != NULL) && (teacher -> next != NULL))
    {
        teacher = teacher -> next -> next;
        student = student -> next;
    }

    return (student);
}
