class Solution {
    private:
    int solve(int i,int j,string &s){
        if(i>=j) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(s[i]==s[j]) return t[i][j]=solve(i+1,j-1,s);
        return t[i][j]=1+min(solve(i+1,j,s),solve(i,j-1,s));
    }
public:
    int t[501][501];
    int minInsertions(string s) {
        memset(t,-1,sizeof(t));
        int n=s.length();
        return solve(0,n-1,s);
    }
};


class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>> t(n,vector<int>(n,0));
        for(int length=2;length<=n;length++){
            for(int i=0;i+length-1<n;i++){
                int j=i+length-1;
                if(s[i]==s[j]){
                    t[i][j]=t[i+1][j-1];
                }else{
                    t[i][j]=1+min(t[i+1][j],t[i][j-1]);
                }
            }
        }
        return t[0][n-1];
    }
};
