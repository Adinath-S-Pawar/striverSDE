#include<iostream>
using namespace std;

/*
Problem statement
Design and implement a data structure for Least Recently Used (LRU) cache to support the following operations:
1. get(key) - Return the value of the key if the key exists in the cache, otherwise return -1.
2. put(key, value), Insert the value in the cache if the key is not already present or update the value of the 
given key if the key is already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
You will be given ‘Q’ queries. Each query will belong to one of these two types:
Type 0: for get(key) operation.
Type 1: for put(key, value) operation.
Note :
1. The cache is initialized with a capacity (the maximum number of unique keys it can hold at a time).
2. Access to an item or key is defined as a get or a put operation on the key. The least recently used key is 
the one with the oldest access time.
*/

/*
Time Complexity: O(1) for both get() and put()
Space Complexity: O(capacity)
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, value;
    Node *prev, *next;

    Node(int k, int v)
    {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};

class LRUCache
{
    int cap;
    unordered_map<int, Node*> mp;   //key-int, value - node(key,val)
    //the key of map and key of node are same
    Node *head, *tail;

public:

    void removeNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node)
    {   //head is on dummy which points to first node, we are keeping dummy node
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    LRUCache(int capacity)
    {
        cap = capacity;

        head = new Node(-1, -1);    //dummy
        tail = new Node(-1, -1);    //dummy

        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        ////recently used so put it first
        removeNode(node);
        insertFront(node);  

        return node->value;
    }

    void put(int key, int value)
    {
        // update value if key exist
        if(mp.find(key) != mp.end())
        {
            Node* node = mp[key];
            node->value = value;

            //recently used
            removeNode(node);
            insertFront(node);
            return;
        }

        //is map is full remove last node(least recently used)
        if(mp.size() == cap)
        {
            Node* lru = tail->prev;

            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        //new element
        Node* newNode = new Node(key, value);
        insertFront(newNode);
        mp[key] = newNode;
    }
};


int main()
{
    return 0;
}