class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int el1=INT_MIN,el2=INT_MIN;
        int n=arr.size();
        int cnt1=0,cnt2=0;
        for(int i=0;i<arr.size();i++){
            if(cnt1==0 && arr[i]!=el2){
                cnt1=1;
                el1=arr[i];
            }
            else if(cnt2==0 && arr[i]!=el1){
                cnt2=1;
                el2=arr[i];
            }
            else if(arr[i]==el1){
                cnt1++;
            }
            else if(arr[i]==el2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==el1){
                cnt1++;
            }
            else if(arr[i]==el2){
                cnt2++;
            }
        }
        
        vector<int>result;
        int mini=int(n/3)+1;
        
        if(cnt1>=mini){
            result.push_back(el1);
        }
        if(cnt2>=mini){
            result.push_back(el2);
        }
        sort(result.begin(),result.end());
        return result;
    }
};