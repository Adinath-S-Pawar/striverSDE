#include<iostream>
using namespace std;

/*Problem Statement: Given the head of a linked list that may contain a cycle, return the starting point of that cycle. 
If there is no cycle in the linked list return null.
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

Node* detectCycle(Node *head)
{
	//	Write your code here
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return slow;
    }
    return NULL;
   
}
// TC - O(n) SC - O(1)
Node *firstNode(Node *head)
{
   if(head == NULL)
     return NULL;

    Node* node_of_intsersection = detectCycle(head);

    if(node_of_intsersection == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = node_of_intsersection;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// extra - removing loop 
void remove_loop(Node* head)
{
    Node* start_of_loop = firstNode(head);
    Node* temp = start_of_loop;
    while(temp ->next != start_of_loop)
    {
        temp = temp->next;
    }

    temp->next = NULL;

}
int main()
{
    return 0;
}