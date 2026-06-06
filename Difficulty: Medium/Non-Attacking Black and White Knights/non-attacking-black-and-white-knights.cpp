class Solution {
  public:
     int numOfWays(int n, int m) {
        vector<vector<int>>mat(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=0;
                if(i-2>=0 && i-2<n && j-1>=0 && j-1<m)
                {
                    x++;
                }
                if(i-2>=0 && i-2<n && j+1>=0 && j+1<m)
                {
                    x++;
                }
                if(i+2>=0 && i+2<n && j-1>=0 && j-1<m)
                {
                    x++;
                }
                if(i+2>=0 && i+2<n && j+1>=0 && j+1<m)
                {
                    x++;
                }
                if(j-2>=0 && j-2<m && i-1>=0 && i-1<n)
                {
                    x++;
                }
                if(j-2>=0 && j-2<m && i+1>=0 && i+1<n)
                {
                    x++;
                }
                if(j+2>=0 && j+2<m && i-1>=0 && i-1<n)
                {
                    x++;
                }
                if(j+2>=0 && j+2<m && i+1>=0 && i+1<n)
                {
                    x++;
                }
                cnt=cnt+((n*m)-x);
            }
        }
        return cnt-(n*m);
        
    }
};