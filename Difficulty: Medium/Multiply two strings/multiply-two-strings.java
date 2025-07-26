class Solution {
    public boolean isZero(String s){
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!='0'){
                return false;
            }
        }
        return true;
    }
    public String multiplyStrings(String s1, String s2) {
        // code here
        boolean negative=false;
        if(s1.charAt(0)=='-' && s2.charAt(0)!='-'){
            s1=s1.substring(1);
            negative=true;
        }
        else if(s2.charAt(0)=='-' && s1.charAt(0)!='-'){
            s2=s2.substring(1);
            negative=true;
        }
        else if(s1.charAt(0)=='-' && s2.charAt(0)=='-'){
            s1=s1.substring(1);
            s2=s2.substring(1);
        }
        int n=s1.length(),m=s2.length();
       if(isZero(s1)||isZero(s2)){
           return "0";
       }
        int res[]=new int[n+m];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int mul=(s1.charAt(i)-'0')*(s2.charAt(j)-'0');
                int sum=mul+res[i+j+1];
                res[i+j+1]=sum%10;
                res[i+j]+=sum/10;
            }
        }
       
        int i=0;
        StringBuilder sb=new StringBuilder();
        while(i<res.length && res[i]==0){
            i++;
        }
        for(;i<res.length;i++){
            sb.append(res[i]);
        }
        if(negative){
            sb.insert(0,'-');
        }
        return sb.toString();
        
        
        
        
    }
}