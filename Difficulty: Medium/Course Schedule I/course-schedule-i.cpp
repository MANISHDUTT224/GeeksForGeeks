class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        //Step-1: Build graph and indegree array from given edges
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            
            adj[v].push_back(u);// v->u
            indeg[u]++;
        }
        //step-2: push all zero indegree node into queue
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        //step-3: Apply kahn's algorithm
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            for(auto &nbr:adj[node]){
                indeg[nbr]--;
                if(indeg[nbr]==0) q.push(nbr);
            }
        }
        //Step-4: check if cycle is present or not
        for(int i=0;i<n;i++){
            if(indeg[i] !=0) return false;
        }
        return true;
    }
};