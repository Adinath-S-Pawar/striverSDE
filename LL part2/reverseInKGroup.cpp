#include<iostream>
using namespace std;
/*
Problem Statement: Given the head of a singly linked list containing integers, reverse the nodes of the list in groups 
of k and return the head of the modified list. If the number of nodes is not a multiple of k, then the remaining nodes 
at the end should be kept as is and not reversed.
Do not change the values of the nodes, only change the links between nodes.*/
  class Node {
  public:
      int data;
      Node *next;
      Node() : data(0), next(nullptr) {}
      Node(int x) : data(x), next(nullptr) {}
     Node(int x, Node *next) : data(x), next(next) {}
  };
 
// TC - O(N) SC - O(N/k)
Node* kReverse(Node* head, int k) {
    if(head == NULL) {
        return NULL;
    }

    // Check if at least k nodes exist
    Node* temp = head;
    int cnt = 0;

    while(temp != NULL && cnt < k) {
        temp = temp->next;
        cnt++;
    }

    // Less than k nodes left => do not reverse
    if(cnt < k) {
        return head;
    }

    // Reverse first k nodes
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    cnt = 0;

    while(curr != NULL && cnt < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
//Connect the tail of the current reversed group to the head returned by the recursive call.
    // Recursively process remaining list
    head->next = kReverse(curr, k);
    //new head of reversed group
    return prev;
}
int main()
{
    return 0;
}