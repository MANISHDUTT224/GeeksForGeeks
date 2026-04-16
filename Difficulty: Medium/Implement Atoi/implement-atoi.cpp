class Solution {
  public:
    int myAtoi(string &s) {
        // code here
          int index= 0;
       ////removing trailing white spaces
        while(s[index] == ' ')
        index++;
         
        
        //identifying the sign of the number
        bool isPositive = true;
        if(s[index] == '-')
        isPositive = false;
        
        if(s[index] == '+' || s[index] == '-')
        index++;
        
        //iterating through the digits
        long long maxL = INT_MAX;//to ensure within 32 bit
        int ans = 0;
         long long temp = 0LL;
        bool limit = false;//to check if withing range
        while(index<s.size())
        {
            if(!isdigit(s[index]))
            break;
           
            temp = temp*10 + (s[index] - '0');
            index++;
            if(temp>maxL)
            {limit = true;break; }
            ans = temp;
            
        }
        if(!isPositive)
        ans = -1 * ans;
        if(limit)
        if(!isPositive)
        return INT_MIN;
        else return INT_MAX;
        return ans;
        
    }
};
