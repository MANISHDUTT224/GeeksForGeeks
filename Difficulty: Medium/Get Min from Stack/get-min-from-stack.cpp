//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<int>s,p;
  int i=-1,j=-1;
    Solution() {
        // code here
        int MAX_Q=1e5+5;
        s.resize(MAX_Q,0);
        p.resize(MAX_Q,0);
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        s[++i]=x;
        if(j==-1 || s[j]>=x){
            
        
        p[i]=j;
        j=i;
        }
        
        
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(i==-1){
            
            return;
        }
        if(j==i){
            j=p[i];
        }
        i--;
        
        
    }

    // Returns top element of the Stack
    int peek() {
        if(i==-1){
            return i;
        }
        return s[i];
        // code here
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(j==-1){
            return j;
        }
        return s[j];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends