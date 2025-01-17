//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int prd=1;
        int cnt=0;
        for(int i:arr){
            if(i==0){
                cnt++;
                continue;
            }
            prd*=i;
        }
        vector<int>res;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                cnt--;
                if(cnt==0){
                res.push_back(prd);
                }
                else{
                    res.push_back(0);
                }
                cnt++;
            }
            else{
                if(cnt>0){
                    res.push_back(0);
                }
                else{
                    res.push_back(prd/arr[i]);
                }
            }
           
        }
        return res;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends