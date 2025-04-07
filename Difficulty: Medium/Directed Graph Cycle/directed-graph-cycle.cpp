//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>in(V,0);
        vector<vector<int>>adj(V);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        for(auto vec:adj){
            for(auto val:vec){
                in[val]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        vector<int>vc;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            vc.push_back(curr);
            for(auto val:adj[curr]){
                in[val]--;
                if(in[val]==0){
                    q.push(val);
                }
            }
        }
        return vc.size()<V;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends