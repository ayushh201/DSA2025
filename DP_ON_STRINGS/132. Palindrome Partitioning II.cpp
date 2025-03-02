class Solution {
public:
    int n;
    int t[2001][2001];

    int isPalindrome(int i,int j,string &s){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    int solve(int i,int j,string &s){
        if(i>=j) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(isPalindrome(i,j,s)) return t[i][j]=0;
        int cuts=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp=1+solve(i,k,s)+solve(k+1,j,s);
            cuts=min(cuts,temp);
        }
        return t[i][j]=cuts;
    }
    int minCut(string s) {
        n=s.length();
        memset(t,-1,sizeof(t));
        return solve(0,n-1,s);
    }
};
