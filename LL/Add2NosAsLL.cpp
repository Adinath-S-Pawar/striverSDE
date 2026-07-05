#include <bits/stdc++.h> 

/*
You have been given two singly Linked Lists, where each of them represents a positive number without any leading zeros.
Your task is to add these two numbers and print the summation in the form of a linked list.
Example:
If the first linked list is 1 -> 2 -> 3 -> 4 -> 5 -> NULL and the second linked list is 4 -> 5 -> NULL.
The two numbers represented by these two lists are 12345 and 45, respectively. So, adding these two numbers gives 12390. 
*/
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }
    };

Node<int>* reverse(Node<int>* head)
{
    Node<int>* prev = NULL;
    Node<int>* curr = head;

    while(curr)
    {
        Node<int>* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

//Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.
//Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.


Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {

    //reverse both input ll
    first  = reverse(first);
    second = reverse(second);

    int carry = 0;
    //create dummy node for result
    Node<int>* dummy = new Node<int>(-1);
    Node<int>*tail = dummy;
    
    while(first != NULL || second != NULL || carry !=0)
    {
        //calculate sum
        int sum = carry;
        if(first != NULL)
        {
            sum += first->data;
            first = first->next;
        }
        if(second != NULL)
        {
            sum += second->data;
            second = second->next;
        }

        //calcuate carry
        carry = sum / 10;

        //create new node for last digit of sum and add to ans
        tail->next = new Node<int>(sum % 10);
        tail = tail->next;

    }

    //reverse ans
    return(reverse(dummy->next));
}