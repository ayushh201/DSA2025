class Solution {
    private:
    bool solve(string &s,int i,int j){
        if(i>=j) return t[i][j]=true;
        if(t[i][j]!=-1) return t[i][j];
        if(s[i]==s[j]) return solve(s,i+1,j-1);
        return t[i][j]=false;
    }
public:
    int t[1001][1001];
    string longestPalindrome(string s) {
        int n=s.length();
        memset(t,-1,sizeof(t));
        int maxLength=INT_MIN;
        int sp=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)==true){
                    if(j-i+1>maxLength){
                        maxLength=max(maxLength,j-i+1);
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxLength);
    }
};
