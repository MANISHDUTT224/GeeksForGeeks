//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        priority_queue<pair<int,pair<int,int>>>maxheap;
        vector<vector<int>>res;
        for(int i=0;i<k;i++){
            int x=points[i][0];
            int y=points[i][1];
            int val=x*x+y*y;
            maxheap.push({val,{x,y}});
        }
        for(int i=k;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            int val=x*x+y*y;
            if(maxheap.top().first>val){
                maxheap.pop();
                maxheap.push({val,{x,y}});
            }
            
        }
        while(!maxheap.empty()){
            auto val=maxheap.top();
            maxheap.pop();
            res.push_back({val.second.first,val.second.second});
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends