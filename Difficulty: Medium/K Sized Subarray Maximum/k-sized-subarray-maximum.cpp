//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++){
            pq.push({arr[i],i});
        }
        int i=k;
        int n=arr.size();
        vector<int>ans;
        ans.push_back(pq.top().first);
        while(i<n){
            pq.push({arr[i],i});
            while(!pq.empty() && abs(pq.top().second-i)>=k){
                pq.pop();
            }
            if(!pq.empty()){
                ans.push_back(pq.top().first);
                i++;
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends