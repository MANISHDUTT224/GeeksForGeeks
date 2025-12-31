/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        vector<int>ans;
        while(head){
            ans.push_back(head->data);
            head=head->next;
        }
        vector<int>res=ans;
        reverse(res.begin(),res.end());
        return ans==res;
    }
};