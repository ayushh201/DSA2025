class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>> t(n,vector<bool>(n,false));
        int maxLength=0;
        int idx=0;
        for(int i=0;i<n;i++){
            t[i][i]=true;
            maxLength=1;
        }
        for(int length=2;length<=n;length++){
            for(int i=0;i+length-1<n;i++){
                int j=i+length-1;
                if(i+1==j && s[i]==s[j]){
                    t[i][j]=true;
                    maxLength=2;
                    idx=i;
                }else if(s[i]==s[j] && t[i+1][j-1]==true){
                    t[i][j]=true;
                    if(j-i+1>maxLength){
                        maxLength=j-i+1;
                        idx=i;
                    }
                }else{
                    t[i][j]=false;
                }
            }
        }
        return s.substr(idx,maxLength);
    }
};
