#include<iostream>
using namespace std;


  class Node {
  public:
      int data;
      Node *next;
      Node() : data(0), next(nullptr) {}
     Node(int x) : data(x), next(nullptr) {}
      Node(int x, Node *next) : data(x), next(next) {}
  };
 
// TC - O(n) SC - O(1)
Node *rotate(Node *head, int k) {
     // return head if 0,1 node or k == 0
     if(head == nullptr || head->next == nullptr || k==0) return head;

     //find length and tail
     int n = 1;
     Node* tail = head;
     while(tail->next != nullptr)
     {
          tail = tail->next;
          n++;
     }

     //return head if k%n == 0
     k = k % n;     
     if(k == 0 )
     {
          return head;
     }

     //make ll circular
     tail->next = head;

     //find new tail at n-k-1
     Node* newtail = head;
     int steps = n-k-1;  //make sure k = k%n performed to handle negative val

     while(steps != 0)
     {
          newtail = newtail->next;
          steps--;
     }

     //move head to new head 
     head = newtail->next;

     //break circular
     newtail->next = nullptr;

     return head;
}

int main()
{
    return 0;
}