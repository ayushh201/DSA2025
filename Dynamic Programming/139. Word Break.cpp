class Solution {
    private:
    bool solve(int i,string &s){
        if(i==n){
            return true;
        }
        if(st.find(s)!=st.end()) return true;
        if(t[i]!=-1) return t[i];
        for(int l=1;l<=n;l++){
            string temp=s.substr(i,l);
            if(st.find(temp)!=st.end() && solve(i+l,s)){
                return t[i]=true;
            }
        }
        return t[i]=false;
    }
public:
    int n;
    unordered_set<string> st;
    int t[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        memset(t,-1,sizeof(t));
        for(string &word:wordDict){
            st.insert(word);
        }
        return solve(0,s);
    }
};
