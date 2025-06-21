class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        deque<int>thief_q,police_q;
        int cc=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]=='P'){
                while(!thief_q.empty() && thief_q.front()<i-k){
                    thief_q.pop_front();
                }
                if(!thief_q.empty()){
                    thief_q.pop_front();
                    cc++;
                }
                else{
                    police_q.push_back(i);
                }
            }
            else if(arr[i]=='T'){
                while(!police_q.empty() && police_q.front()<i-k){
                    police_q.pop_front();
                }
                if(!police_q.empty()){
                    police_q.pop_front();
                    cc++;
                }
                else{
                    thief_q.push_back(i);
                }
            }
        }
        return cc;
    }
};