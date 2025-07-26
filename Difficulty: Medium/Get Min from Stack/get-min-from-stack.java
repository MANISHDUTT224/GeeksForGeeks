class Solution {
    int stack[],minstack[];
    int top;
    public Solution() {
        stack=new int[100001];
        minstack=new int[100001];
        top=-1;
    }

    // Add an element to the top of Stack
    public void push(int x) {
        // code here
        stack[++top]=x;
        if(top==0){
            minstack[top]=x;
        }
        else{
            minstack[top]=Math.min(minstack[top-1],x);
        }
    }

    // Remove the top element from the Stack
    public void pop() {
        if(top>=0){
            top--;
        }
        // code here
    }

    // Returns top element of the Stack
        
    public int peek() {
        // code here
        if(top==-1){
            return -1;
        }
        return stack[top];
    }

        
    // Finds minimum element of Stack
    public int getMin() {
        // code here
        
        if(top==-1){
            return -1;
        }
        return minstack[top];
    }
}