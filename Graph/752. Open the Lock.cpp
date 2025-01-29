class Solution {
    private:
    void fillNeighbours(queue<string> &q,string &curr,unordered_set<string> &st){
        for(int i=0;i<4;i++){
            char ch=curr[i];
            char incr = ch=='9'? '0':ch+1;
            char decr = ch=='0'? '9':ch-1;
            curr[i]=decr;
            if(st.find(curr)==st.end()){
                st.insert(curr);
                q.push(curr);
            }
            curr[i]=incr;
            if(st.find(curr)==st.end()){
                st.insert(curr);
                q.push(curr);
            }
            curr[i]=ch;
        }
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st;
        for(string &deadend : deadends){
            st.insert(deadend);
        }
        string start="0000";
        if(st.find(start)!=st.end()) return -1;
        queue<string> q;
        q.push(start);
        st.insert(start);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==target){
                    return level;
                }
                fillNeighbours(q,curr,st);
            }
            level++;
        }
        return -1;
    }
};
