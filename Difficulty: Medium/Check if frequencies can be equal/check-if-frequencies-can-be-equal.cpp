class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int>vec(26,0);
        for(int i=0;i<s.size();i++){
            vec[s[i]-'a']++;
        }
        map<int,int>mp;
        for(auto it:vec){
            if(it==0){
                continue;
            }
            mp[it]++;
        }
        if(mp.size()>2){
            return false;
        }
        
        int val=mp.rbegin()->first;
        int val2=mp.rbegin()->second;
        int val3=mp.begin()->first;
        int val4=mp.begin()->second;
        if(val==val2 && val==1){
            return true;
        }
        if(val3==val4 && val3==1){
            return true;
        }
        int value1=val*val2;
        int value2=val3*val4;
        return abs(value1-value2)<=1;
    }
};