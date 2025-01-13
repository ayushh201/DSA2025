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
