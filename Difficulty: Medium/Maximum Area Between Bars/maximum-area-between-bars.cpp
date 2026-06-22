class Cmp {
public:
    bool operator()(vector<int>& v1, vector<int>& v2) { return v1[0] < v2[0]; }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        priority_queue<vector<int>, vector<vector<int>>, Cmp> pq;

        for (int i = 0; i < n; i++)
            pq.push({height[i], i});

        int res = 0;
        int mini = -1, maxi = -1;

        while (!pq.empty()) {
            int idx = pq.top()[1];

            if (mini == -1 || idx > mini)
                mini = idx;
            if (maxi == -1 || maxi > idx)
                maxi = idx;

            res = max(res,
                      min(height[mini], height[maxi]) * (abs(maxi - mini) - 1));

            pq.pop();
        }

        return res;
    }
};