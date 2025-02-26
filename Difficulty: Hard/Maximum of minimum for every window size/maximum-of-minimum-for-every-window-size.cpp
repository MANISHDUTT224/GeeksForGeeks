//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        vector<int>left(n+1,0);
        vector<int>right(n+1,0);
        vector<int>ans(n+1,0);
        for(int i=0;i<n;i++){
            left[i]=-1;
            right[i]=n;
        }
        stack<int>st,st1;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            st.push(i);
        }
        for(int i=0;i<=n;i++){
            ans[i]=0;
        }
        for(int i=0;i<n;i++){
            int len=right[i]-left[i]-1;
            ans[len]=max(ans[len],arr[i]);
        }
        for(int i=n-1;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
        }
        ans.erase(ans.begin());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends