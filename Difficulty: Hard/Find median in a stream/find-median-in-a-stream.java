class Solution {
    void addNum(int num,PriorityQueue<Integer>minHeap,PriorityQueue<Integer>maxHeap){
        if(maxHeap.isEmpty()||num<=maxHeap.peek()){
            maxHeap.add(num);
        }
         else{
             minHeap.add(num);
         }
         if(maxHeap.size()>minHeap.size()+1){
             minHeap.add(maxHeap.poll());
         }
         else if(minHeap.size()>maxHeap.size()){
             maxHeap.add(minHeap.poll());
         }
    }
    double findMedian(PriorityQueue<Integer>minHeap,PriorityQueue<Integer>maxHeap){
        if(minHeap.size()==maxHeap.size()){
            return (minHeap.peek()+maxHeap.peek())/2.0;
        }
        return maxHeap.peek();
    }
    public ArrayList<Double> getMedian(int[] arr) {
        // code here
        PriorityQueue<Integer>minHeap=new PriorityQueue<>();
        PriorityQueue<Integer>maxHeap=new PriorityQueue<>((a,b)->b-a);
        ArrayList<Double>res=new ArrayList<>();
        for(int num:arr){
            addNum(num,minHeap,maxHeap);
            res.add(findMedian(minHeap,maxHeap));
        }
        return res;
        
    }
    
}