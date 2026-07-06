#include<iostream>
using namespace std;

int main()
{
    return 0;
}

/*
Problem Statement: Given the head of a singly linked list representing a positive integer number. 
Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of 
the number and so on. Check whether the linked list values form a palindrome or not. Return true if it forms a palindrome,
otherwise, return false. .
*/

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

Node* getmid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
    
}

Node* reverse_sll(Node* &head) // iterative approach
{
    if(head == NULL || head->next ==NULL)
    {
        return head;
    }

    Node* forward = NULL;
    Node* pre = NULL;
    Node* curr = head;

    while(curr != NULL)
    {
        forward = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forward;

    }
    head = pre;
    return pre;//head changed to last node

}

/*
Time Complexity: O(N), we traverse the list twice, once to reverse half of it and once to compare, 
each taking O(N/2), which simplifies to O(N).
Space Complexity: O(1), no extra space is used apart from a few pointers; operations are done in-place.
*/
bool isPalindrome(Node *head)
{
    //true for single node
    if(head->next == NULL) return true;

    //get mid and reverse second half
    Node* mid = getmid(head);
    
    Node* temp = mid->next;
    mid->next = reverse_sll(temp);

    Node* head1 = head;
    Node* head2 = temp;

    //compare halves
    while(head2 != NULL)
    {
        if(head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    //bring ll back to original
    temp = mid->next;
    mid->next = reverse_sll(temp);

    //return 
    return true;
}