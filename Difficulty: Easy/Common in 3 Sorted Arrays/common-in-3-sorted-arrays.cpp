class Solution {
  public:
     vector<int> common(vector<int> &a, vector<int> &b) {
        int m = a.size(), n = b.size(), i = 0, j = 0;
        vector<int> res;
        while(i < m && j < n) {
            if(a[i] == b[j]) {
                if(res.empty() || res.back() != a[i])
                    res.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i] < b[j]) {
                i++;
            }
            else if(a[i] > b[j]) {
                j++;
            }
        }
        return res;
    }
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        vector<int> temp, res;
        temp = common(a, b);
        if(temp.empty())
            return temp;
            
        res = common(temp, c);
        
        return res;
    }

};