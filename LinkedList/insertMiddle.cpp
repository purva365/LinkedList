//had some errror
void insertAtMiddle(Node* &head, int position, int d) {
  if (position == 1) {
    insertAtHead(head, d);
    return;
  }

  Node* temp = head;
  // Traverse to the node just before the insertion point
  for (int i = 1; i < position - 1; i++) {
    if (temp == NULL) {
      cout << "Position out of bounds" << endl;
      return;
    }
    temp = temp->next;
  }

  if (temp == NULL) {
    cout << "Position out of bounds" << endl;
    return;
  }

  // Create the new node and insert it into the list
  Node* newNode = new Node(d);
  newNode->next = temp->next;
  temp->next = newNode;
}
