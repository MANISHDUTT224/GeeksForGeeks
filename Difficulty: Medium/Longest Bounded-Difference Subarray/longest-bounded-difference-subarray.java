class Solution {
    public ArrayList<Integer> longestSubarray(int[] arr, int x) {
        // code here
         Deque<Integer>maxDq=new ArrayDeque<>();
        Deque<Integer>minDq=new ArrayDeque<>();
        int start=0,maxlen=0,ansStart=0;
        for(int end=0;end<arr.length;end++){
            while(!maxDq.isEmpty() && arr[maxDq.peekLast()]<=arr[end]){
                maxDq.pollLast();
            }
            maxDq.addLast(end);
            while(!minDq.isEmpty() && arr[minDq.peekLast()]>=arr[end]){
                minDq.pollLast();
            }
            minDq.addLast(end);
            while(arr[maxDq.peekFirst()]-arr[minDq.peekFirst()]>x){
                start++;
            
            if(maxDq.peekFirst()<start){
                maxDq.pollFirst();
            }
            if(minDq.peekFirst()<start){
                minDq.pollFirst();
            }
            }
            if(end-start+1>maxlen){
                maxlen=end-start+1;
                ansStart=start;
            }
        }
        ArrayList<Integer>res=new ArrayList<>();
        for(int i=ansStart;i<ansStart+maxlen;i++){
            res.add(arr[i]);
        }
        return res;
    }
}