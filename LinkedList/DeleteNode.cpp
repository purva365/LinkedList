#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtMiddle(Node* &head, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            cout << "Position out of bounds." << endl;
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of bounds." << endl;
        return;
    }

    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node* &head, int pos) {
    // Handle empty list case
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    // Handle deletion of the first node
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;

    // Traverse the list to find the node to delete
    while (cnt < pos) {
        prev = curr;
        curr = curr->next;
        cnt++;

        // Check if position is out of bounds
        if (curr == NULL) {
            cout << "Position out of bounds." << endl;
            return;
        }
    }

    // Perform deletion
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(11);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 13);
    print(head);

    insertAtHead(head, 14);
    print(head);

    insertAtTail(tail, 1);
    print(head);

    insertAtTail(tail, 2);
    print(head);

    insertAtTail(tail, 3);
    print(head);

    deleteNode(head, 1);
    print(head);

    insertAtMiddle(head, 3, 22);
    print(head);

    deleteNode(head, 4);
    print(head);

    return 0;
}
