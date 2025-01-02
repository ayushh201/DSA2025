class Solution {
    private:
    int solve(int l,int r,string &s){
        if(l==r){
            return 1;
        }
        if(l>r){
            return 0;
        }
        if(t[l][r]!=-1) return t[l][r];
        int i=l+1;
        while(i<=r && s[i]==s[l]){
            i++;
        }
        if(i==r+1) return 1;
        int basic=1+solve(i,r,s);
        //second approach
        int ans=INT_MAX;
        for(int j=i;j<=r;j++){
            if(s[j]==s[l]){
                int value=solve(i,j-1,s)+solve(j,r,s);
                ans=min(ans,value);
            }
        }
        return t[l][r]=min(basic,ans);
    }
public:
    int t[101][101];
    int strangePrinter(string s) {
        memset(t,-1,sizeof(t));
        return solve(0,s.length()-1,s);
    }
};
