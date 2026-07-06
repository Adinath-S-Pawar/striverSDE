
 class Node {
  public:
		int data;
		Node *next;
 		Node *child;
		Node() : data(0), next(nullptr), child(nullptr){};
		Node(int x) : data(x), next(nullptr), child(nullptr) {}
		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 };


#include <queue>
using namespace std;

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // min-heap
    }
};

/*
Time: O(N log K) , push,pop -> log(K)
N = total number of nodes across all lists.
K = number of linked lists (number of nodes connected through next).
Space: O(K) (for the priority queue)
*/

Node* flattenLinkedList(Node* head) {
    if (!head) return nullptr;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Push heads of all lists
    Node* temp = head;
    while (temp) {
        pq.push(temp);
        temp = temp->next;
    }

    Node dummy(0);
    Node* tail = &dummy;

    while (!pq.empty()) {
        Node* curr = pq.top();  //pq stores smallest at top
        pq.pop();

        tail->child = curr;
        tail = curr;

        if (curr->child)
            pq.push(curr->child);

        curr->next = nullptr; // remove horizontal links
    }

    tail->child = nullptr;

    return dummy.child;
}