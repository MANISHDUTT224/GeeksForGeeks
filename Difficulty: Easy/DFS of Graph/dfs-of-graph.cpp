//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfsrecur(int vertex,vector<vector<int>>&adj,vector<int>&result,vector<bool>&visited){
        visited[vertex]=true;
        result.push_back(vertex);
        for(int  neighbor:adj[vertex]){
            if(!visited[neighbor]){
            
                dfsrecur(neighbor,adj,result,visited);
            }
        }
       
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>result;
        vector<bool>visited(adj.size(),false);
        dfsrecur(0,adj,result,visited);
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends