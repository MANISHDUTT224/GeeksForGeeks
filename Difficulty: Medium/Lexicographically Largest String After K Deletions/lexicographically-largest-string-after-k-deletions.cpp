class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        stack<char>st;
        int i=0,cnt=0,n=s.size();
        while(i<n){
            while(!st.empty() && cnt<k && st.top()<s[i]){
                st.pop();
                cnt++;
            }
            st.push(s[i]);
            i++;
        }
        while(cnt<k && !st.empty()){
            st.pop();
            cnt++;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
