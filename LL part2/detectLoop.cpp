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

/*
Time Complexity: O(N), we traverse the entire linked list once. The fast pointer either reaches the end of the list or meets the slow pointer in linear time.
Space Complexity: O(1) , constant amount of extra space is used detect a cycle using Floyd's Cycle Detection Algorithm.*/

//hare and tortoise
bool detectCycle(Node *head)
{
	//	Write your code here
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
   
}