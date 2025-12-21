 class Solution
{
public:
 
 int FindLeft(int l, int r, vector<int> &arr, int x)
    {
        int start = l, end = r, idx = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] == x)
                idx = mid, end = mid - 1;
            else if (arr[mid] > x)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return idx;
    }
    int FindRight(int l, int r, vector<int> &arr, int x)
    {
        int start = l, end = r, idx = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] == x)
                idx = mid, start = mid + 1;
            else if (arr[mid] > x)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return idx;
    }
    vector<int> countXInRange(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (auto it : queries)
        {
            int l = it[0], r = it[1], x = it[2];
            int L = FindLeft(l, r, arr, x);
            int R = FindRight(l, r, arr, x);
            if (L == -1 || R == -1)
                ans.push_back(0);
            else
                ans.push_back(R - L + 1);
        }
        return ans;
    }
};