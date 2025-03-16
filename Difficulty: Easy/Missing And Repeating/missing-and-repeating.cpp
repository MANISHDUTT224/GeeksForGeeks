//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n=arr.size();
        long long s11=(n*(n+1))/2;
        long long s21=(n*(n+1)*(2*n+1))/6;
        long long s1=0,s2=0;
        for(int num:arr){
            s1+=(long long)num;
            s2+=(long long)num*(long long)num;
        }
        long long val1=s11-s1,val2=s21-s2;
        val2/=val1;
        long long x=(val1+val2)/2;
        long long y=x-val1;
        return {(int)y,(int)x};
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
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends