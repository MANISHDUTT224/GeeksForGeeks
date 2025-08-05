class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
         int i=0, j = s.size()-1;
        while(i < j){
            if(isalnum(s[i])){
                if(isalnum(s[j])){
                    if((isdigit(s[i]) and isdigit(s[j]) and s[i] == s[j]) or 
                        isalpha(s[i]) and isalpha(s[j]) and toupper(s[i]) == toupper(s[j])){
                        i++, j--;
                    } else {
                        return 0;
                    }
                } else {
                    j--;
                }
            } else {
                i++;
            }
        }
        return 1;
    }
};