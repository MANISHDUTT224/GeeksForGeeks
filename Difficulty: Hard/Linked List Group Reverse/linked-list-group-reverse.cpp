//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node* reverse(Node* head){
        Node* cur= head;
        Node* prev= NULL;
        
        while(cur){
            Node* next= cur->next;
            cur->next= prev;
            
            prev= cur;
            cur= next;
        }
        return prev;
    }
    
    int Length(Node* head){
        Node* cur= head;
        int cnt=0;
        
        while(cur){
            cnt++;
            cur= cur->next;
        }
        return cnt;
    }
    
    Node *reverseKGroup(Node *hd, int k) {
        // code here
        if(!hd->next) return hd;
       
        //find the Length of L.L 
        int length= Length(hd); 
        //reverse all the  L.L
        Node* cur= reverse(hd), *head= NULL; //track head
        //divide Kth group
        int group= length%k==0? k: length%k;
        
        while(cur){
            Node* tail= cur;
            //travel in a kth group 
            while(group !=1){
                tail= tail->next;
                group--;
            }
            //change the pointer 
            Node* next= tail->next;
            tail->next= head;
            head= cur;
            
            cur= next;
            group=k;
        }
        return head;
    }
};



//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends