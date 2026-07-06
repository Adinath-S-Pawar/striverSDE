#include<iostream>
using namespace std;

/*
Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the 
two lists intersect. If the two linked lists have no intersection at all, return null.
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

/*
Time Complexity: O(2 × max(len of list1, len of list2)) + O(abs(len of list1 − len of list2)) + O(min(len of list1, len of list2)), 
Finding the length of both lists takes O(max) time since it's done simultaneously, 
then moving one pointer by the difference in lengths, and finally searching for the intersection.
Space Complexity: O(1), No extra space is used.
        */
int getDifference(Node* head1, Node* head2)
{
    int len1 = 0;
    int len2 = 0;

    while(head1 != NULL || head2 != NULL)
    {
        if(head1 != NULL)
        {
            len1++;
            head1 = head1->next;
        }
        if(head2 != NULL)
        {
            len2++;
            head2 = head2->next;
        }
    }

    return len1 - len2;
}


Node* findIntersection(Node *firstHead, Node *secondHead)
{
    // get difference
    int diff = getDifference(firstHead,secondHead);

    //move head of larger ll by differencelen 
    if(diff < 0)    // 2nd ll is larger
    {
        while(diff != 0)
        {
            secondHead = secondHead->next;
            diff++;
        }
    }
    else
    {
        // first ll is larger
        while(diff != 0)
        {
            firstHead = firstHead->next;
            diff--;
        }
    }

    //traverse both list from their head and compare nodes   
    while(firstHead != NULL)
    {
        if(firstHead == secondHead)
        {
            return firstHead;
        }
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }

    //no intersection
    return firstHead; //null

    //return head
}


int main()
{
    return 0;
}