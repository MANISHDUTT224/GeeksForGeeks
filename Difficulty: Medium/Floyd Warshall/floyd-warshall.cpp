//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
     int n = dist.size();
        const int INF = 1e8; // Use the correct INF based on the actual test cases
    
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (dist[i][k] == INF) continue; // Skip if no path from i to k
                for (int j = 0; j < n; ++j) {
                    if (dist[k][j] == INF) continue; // Skip if no path from k to j
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.floydWarshall(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends