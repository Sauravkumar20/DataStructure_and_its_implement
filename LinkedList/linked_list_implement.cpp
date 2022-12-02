#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node* next;
};

Node* Node(int val){
    this=>val = val;
    this->next = NULL;
}

class LinkedList{
    public:
    Node* head = NULL;
    Node* tail = NULL;

    LinkedList();
    void Insertion(Node* head);
};

