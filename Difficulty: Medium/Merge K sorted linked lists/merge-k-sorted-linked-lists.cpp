/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& a) {
        // code here
        vector<int>arr;
        for(Node* head:a){
            Node* curr=head;
            while(curr){
                arr.push_back(curr->data);
                curr=curr->next;
            }
        }
        sort(arr.begin(),arr.end());
        Node *tail=new Node(0);
        Node *dummy=tail;
        for(int num:arr){
            tail->next=new Node(num);
            tail=tail->next;
        }
        return dummy->next;
    }
};