
class Solution {
    
    public void prevsmaller(int ps[],int arr[],int n){
        int index=-1;
        int st[]=new int[n];
        for(int i=0;i<n;i++){
            while(index!=-1 && arr[st[index]]>=arr[i]){
                index--;
            }
            ps[i]=(index==-1)?-1:st[index];
            st[++index]=i;
        }
        
    }
    public void nextsmaller(int ns[],int arr[],int n){
        int index=-1;
        int st[]=new int[n];
        for(int i=n-1;i>=0;i--){
            while(index!=-1 && arr[st[index]]>=arr[i]){
                index--;
            }
            ns[i]=(index==-1)?n:st[index];
            st[++index]=i;
        }
    }
    public ArrayList<Integer> maxOfMins(int[] arr) {
        // Your code here
        int n=arr.length;
        int ps[]=new int[n];
        int ns[]=new int[n];
        prevsmaller(ps,arr,n);
        nextsmaller(ns,arr,n);
        int ans[]=new int[n];
        for(int i=0;i<n;i++){
            int windowsize=ns[i]-ps[i]-1;
           ans[windowsize-1]=(ans[windowsize-1]>arr[i])?ans[windowsize-1]:arr[i];
        }
        for(int i=n-2;i>=0;i--){
            ans[i]=Math.max(ans[i],ans[i+1]);
        }
        ArrayList<Integer>res=new ArrayList<>();
        for(int num:ans){
            res.add(num);
        }
        return res;
        
        
    }
}