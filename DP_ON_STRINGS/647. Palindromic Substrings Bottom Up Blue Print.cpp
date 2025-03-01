class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int countPalindromeSubstring=0;
        vector<vector<bool>> t(n,vector<bool>(n,false));
        for(int length=1;length<=n;length++){
            for(int i=0;i+length-1<n;i++){
                int j=i+length-1;
                if(i==j){ //one length
                    t[i][j]=true;
                }else if(i+1==j){ //two length
                    t[i][j]=(s[i]==s[j]);
                }else{ //generic
                    t[i][j]=(s[i]==s[j] && t[i+1][j-1]);
                }
                if(t[i][j]==true) countPalindromeSubstring++;
            }
        }
        return countPalindromeSubstring;
    }
};
