//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Geeks {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().majorityElement(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    static int majorityElement(int arr[]) {
        // code here
        int ele=Integer.MIN_VALUE,cnt1=0,n=arr.length;
        for(int i=0;i<n;i++){
            if(cnt1==0||ele==Integer.MIN_VALUE){
                ele=arr[i];
                cnt1=1;
            }
            else if(ele==arr[i]){
                cnt1++;
            }
            else{
                cnt1--;
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]==ele){
                cnt++;
            }
        }
        if(cnt>n/2){
            return ele;
        }
        return -1;
    }
}