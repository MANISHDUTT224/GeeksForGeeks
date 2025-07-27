class Solution {
    static ArrayList<Integer> maxOfSubarrays(int[] arr, int k) {
        // code here
        Deque<Integer>dq=new LinkedList<>();
        ArrayList<Integer>ans=new ArrayList<>();
        int n=arr.length;
        for(int i=0;i<n;i++){
            if(!dq.isEmpty() && dq.peekFirst()==i-k){
                dq.pollFirst();
            }
            while(!dq.isEmpty() && arr[dq.peekLast()]<=arr[i]){
                dq.pollLast();
            }
            dq.offerLast(i);
            if(i>=k-1){
                ans.add(arr[dq.peekFirst()]);
            }
        }
        return ans;
    }
}