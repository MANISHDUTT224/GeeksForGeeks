class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
         int n= arr.size();
        int l = 0;
        int r = 0;
        unordered_map<int,int> mp;
        int maxi =0;
        while(r<arr.size())
        {
            mp[arr[r]]++;
            if(mp.size() <= 2)
            {
                maxi = max(r-l+1,maxi);
            }

            while(mp.size() > 2)
            {
                mp[arr[l]]--;
                if(mp[arr[l]] == 0 )
                {
                    mp.erase(arr[l]);
                }
                l++;
            }

            r++;
        }
        
        return maxi;
        
    }
};