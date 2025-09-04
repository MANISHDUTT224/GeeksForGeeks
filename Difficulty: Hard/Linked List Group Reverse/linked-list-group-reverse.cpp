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
     Node* rev(Node* h){
        Node* p=NULL;
        Node* c=h;
        Node* n=h;
        
        while(n){
            n = n->next;
            c->next = p;
            p=c;
            c=n;
        }
        return p;
    }
  
  
    Node *reverseKGroup(Node *head, int k) {
        // code here
        vector<Node*> group;
        group.push_back(head);
        int t = k;
        
        while(head){
            k--;
            if(k==0){
                if(head->next)
                  group.push_back(head->next);
                k=t;
            }
            head = head->next;  
        }
        
        
        int n = group.size();
        for(int i=0;i<n-1;i++){
            Node* temp = group[i];
            while(temp->next != group[i+1]){
                temp = temp->next;
            }
            temp->next = NULL;
        }
        
        
        head = rev(group[0]);
        for(int i=1;i<n;i++){
            group[i-1]->next = rev(group[i]);
        }
        return head;
    }
};