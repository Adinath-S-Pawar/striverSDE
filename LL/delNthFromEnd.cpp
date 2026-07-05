#include<iostream>
using namespace std;
/*
Problem Statement: Given a linked list and an integer N, the task is to delete the Nth node from the
end of the linked list and print the updated linked list.
*/
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

/*
Time Complexity: O(N), since the fast pointer will traverse the entire linked list, where N is the length of the linked list.
Space Complexity: O(1), constant additional space is used to check unique elements.
*/
Node* removeKthNode(Node* head, int K)
{
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* fast = dummy;
    Node* slow = dummy;

    //move fast at nth node
    for(int i = 1; i<= K; i++)
    {
        fast = fast->next;
    }

    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node* nodeToDel = slow->next;
    slow->next = nodeToDel->next;
    delete nodeToDel;

    return dummy->next;

}
