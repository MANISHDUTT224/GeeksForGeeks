//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int merge(int low, int mid, int high, vector<int>& arr){
      vector<int>temp;
      int i=low,j=mid+1;
     int cnt=0;
      while(i<=mid && j<=high){
          if(arr[i]<=arr[j]){
              temp.push_back(arr[i]);
              i++;
          }
          
          else{
              cnt+=(mid-i+1);
              temp.push_back(arr[j]);
              j++;
          }
      }
      while(i<=mid){
          temp.push_back(arr[i]);
          i++;
      }
      while(j<=high){
          temp.push_back(arr[j++]);
      }
      for(int i=low;i<=high;i++){
          arr[i]=temp[i-low];
      }
      return cnt;
    }
    
    int divide(int low, int high, vector<int>& arr){
         int cnt=0;
        if(low >= high) return cnt;
       
        int mid = (low + high) / 2;
        cnt+=divide(low, mid, arr);
        cnt+=divide(mid + 1, high, arr);
        cnt+=merge(low, mid, high, arr);
        return cnt;
    }
    
    int inversionCount(vector<int>& arr) {
        // Your Code Here
        int n = arr.size();
        int cnt=divide(0, n-1, arr);
        return cnt;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends