class Solution {
    bool solve(int i,int open,string &s){
        if(i==s.length()){
            return open==0;
        }
        if(t[i][open]!=-1){
            return t[i][open];
        }
        bool isValid=false;
        if(s[i]=='*'){
            isValid |=solve(i+1,open+1,s);
            isValid |=solve(i+1,open,s);
            if(open>0){
                isValid |=solve(i+1,open-1,s);
            }
        }else if(s[i]=='('){
            isValid |=solve(i+1,open+1,s);
        }else if(open>0){
            isValid |=solve(i+1,open-1,s);
        }
        return t[i][open]=isValid;
    }
public:
    int t[101][101];
    bool checkValidString(string s) {
        memset(t,-1,sizeof(t));
        return solve(0,0,s);
    }
};


class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        dp[n][0]=true;
        for(int i=n-1;i>=0;i--){
            for(int open=0;open<=n;open++){
                bool isValid=false;
                if(s[i]=='*'){
                    isValid|=dp[i+1][open];
                    isValid|=dp[i+1][open+1];
                    if(open>0){
                        isValid|=dp[i+1][open-1];
                    }
                }else if(s[i]=='('){
                    isValid|=dp[i+1][open+1];
                }else{
                    if(open>0){
                        isValid|=dp[i+1][open-1];
                    }
                }
                dp[i][open]=isValid;
            }
        }
        return dp[0][0];
    }
};
