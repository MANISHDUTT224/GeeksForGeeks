//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
public:
    Node* fun(int l,int r,vector<int>&in,vector<int>&pre,int &pIndex,int &n){
        if(l>r)
            return NULL;
        Node* t=new Node(pre[pIndex++]);
        
        int i;
        for(i=l;i<=r;i++){
            if(t->data == in[i])
                break;
            
        }
        
        t->left=fun(l,i-1,in,pre,pIndex,n);
        t->right=fun(i+1,r,in,pre,pIndex,n);
        return t;
    }
    
    
    
    
    Node* buildTree(vector<int>in,vector<int>pre)
    {
        // Code here
        int pIndex=0;
        int n=in.size();
        return fun(0,n-1,in,pre,pIndex,n);
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends