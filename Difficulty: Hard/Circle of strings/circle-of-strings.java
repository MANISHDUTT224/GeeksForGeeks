//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine().trim());
        while (t-- > 0) {
            String A[] = in.readLine().trim().split(" ");
            int N = Integer.parseInt(A[0]);
            A = in.readLine().trim().split(" ");

            Solution ob = new Solution();
            System.out.println(ob.isCircle(A));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    private void dfs(int node, boolean[] visited, List<List<Integer>> adj) {
        visited[node] = true;
        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj);
            }
        }
    }
    
    public int isCircle(String arr[]) {
      
        int n = arr.length;
        
        
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            adj.add(new ArrayList<>());
        }
         
        int[] inDegree = new int[26];
        int[] outDegree = new int[26];
        
        
        for (String str : arr) {
            int first = str.charAt(0) - 'a'; 
            int last = str.charAt(str.length() - 1) - 'a'; 
            adj.get(first).add(last); 
            outDegree[first]++; 
            inDegree[last]++; 
        }
        for (int i = 0; i < 26; i++) {
            if (inDegree[i] != outDegree[i]) {
                return 0; 
            }
        }
        
        int start = -1;
        for (int i = 0; i < 26; i++) {
            if (outDegree[i] > 0) {
                start = i;
                break;
            }
        }
        
        if (start == -1) {
            return 1; 
        }
      
        boolean[] visited = new boolean[26];
        dfs(start, visited, adj);
       
        for (int i = 0; i < 26; i++) {
            if (outDegree[i] > 0 && !visited[i]) {
                return 0; 
            }
        }
        return 1; 
    }
    
}