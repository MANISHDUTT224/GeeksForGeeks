class Solution {
    
    public boolean isOperator(String str){
        return str.equals("+")||str.equals("-")||str.equals("*")||str.equals("/");
    }
    public int evaluate(String[] arr) {
        // code here
        Stack<Integer>st=new Stack<>();
        for(String str:arr){
            if(isOperator(str)){
                int op1=st.pop();
                int op2=st.pop();
                switch(str){
                    case "+":
                        st.push(op1+op2);
                        break;
                    case "-":
                        st.push(op2-op1);
                        break;
                    case "*":
                        st.push(op1*op2);
                        break;
                    case "/":
                        st.push(op2/op1);
                        
                }
                
            }
            else{
                st.push(Integer.parseInt(str));
            }
        }
        return st.peek();
    }
}