#include<iostream>
using namespace std;
/*Problem Statement: Given a linked list where every node in the linked list contains two pointers:
‘next’ which points to the next node in the list.
‘random’ which points to a random node in the list or ‘null’.
Create a ‘deep copy’ of the given linked list and return it.*/
int main()
{
    return 0;
}

  class Node {
   public:
 		int data;
		Node *next;
 		Node *random;
 		Node() : data(0), next(nullptr), random(nullptr){};
 		Node(int x) : data(x), next(nullptr), random(nullptr) {}
 		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
  };
 

void insertCopyInBetween(Node* head)
{
	Node* temp = head;

	while(temp != nullptr)
	{
		//create copy of curr node
		Node* copy = new Node(temp->data);

		//store next elem of original ll
		Node* nextElement = temp->next;

		//point copys next to original next elem
		copy->next = nextElement;

		//point curr nodes next to its copy
		temp->next = copy;

		//move temp to next elem of original ll
		temp = nextElement;
	}
}

void connectRandomPointers(Node* head)
{
	Node* temp = head;

	while(temp != nullptr)
	{
		//access copied node
		Node* copy = temp->next;

		//if random ptr exist point copys random to corresponding copied random node else to null
		if(temp->random)
		{
			copy->random = temp->random->next; //next because if a->c then a'->c' not c
		}
		else
		{
			copy->random = nullptr;
		}

		//move temp to next elem of original ll
		temp = temp->next->next; // a-a'-b-b' temp from a to b
	}
}

Node* getDeepCopyList(Node* head)
{
    Node* dummy = new Node(-1);
    Node* copyTail = dummy;

    Node* temp = head;

    while(temp != nullptr)
    {
        Node* copy = temp->next;

        // restore original list
        temp->next = copy->next;

        // append to copied list
        copyTail->next = copy;
        copyTail = copy;

        // fix copied list's next pointer
        if(copy->next != nullptr)
            copy->next = copy->next->next;

        temp = temp->next;
    }

    return dummy->next;
}

/*
Insert copies: O(N)
Connect random pointers: O(N)
Separate lists: O(N)
Time Complexity: O(3N), where N is the number of nodes in the linked list. 

Space Complexity : O(N), where N is the number of nodes in the linked list as the only extra additional space 
allocated it to create the copied list without creating any other additional data structures.
*/
Node *cloneLL(Node *head){
	if(!head) return nullptr;   
    
    insertCopyInBetween(head); 

    connectRandomPointers(head);  

    return getDeepCopyList(head); 
}