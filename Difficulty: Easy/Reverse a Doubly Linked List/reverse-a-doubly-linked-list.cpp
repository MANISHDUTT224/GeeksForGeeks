/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node *ptr = head;
        while (ptr) {
            Node *temp = ptr -> next;
            ptr->next = ptr->prev;
            ptr->prev = temp;
            head = ptr;
            ptr = ptr->prev;
        }
        return head;
    }
};