//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        if(n==1){
            return arr[0];
        }
        return max(maxRobLinear(arr,0,n-2),maxRobLinear(arr,1,n-1));
    }
    int maxRobLinear(vector<int>&arr,int start,int end){
        
        int prev2=0,prev1=0;
        for(int i=start;i<=end;i++){
            int curr=max(prev1,prev2+arr[i]);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends