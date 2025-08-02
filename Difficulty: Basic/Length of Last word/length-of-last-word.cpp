// User function Template for C++

int findLength(string s) {
    // code
    int i=s.size()-1;
    while(i>=0 && s[i]==' '){
        i--;
    }
    int cnt=0;
    while(i>=0 && s[i]!=' '){
        i--;
        cnt++;
    }
    return cnt;
}