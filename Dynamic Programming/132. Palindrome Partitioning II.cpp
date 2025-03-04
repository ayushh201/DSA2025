class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int length=1;length<=n;length++){
            for(int i=0;i+length-1<n;i++){
                int j=i+length-1;
                if(i==j){ //one length
                    dp[i][j]=true;
                }else if(i+1==j){ //two length
                    dp[i][j]=(s[i]==s[j]);
                }else{ //generic
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
            }
        }
        vector<int> t(n);
        for(int i=0;i<n;i++){
            if(dp[0][i]){
                t[i]=0;
            }else{
                t[i]=INT_MAX;
                for(int k=0;k<i;k++){
                    if(dp[k+1][i] && 1+t[k]<t[i]){
                        t[i]=1+t[k];
                    }
                }
            }
        }
        return t[n-1];
    }
};
