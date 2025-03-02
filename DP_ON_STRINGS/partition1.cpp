class Solution {
    private:
    void solve(int i,string& s,vector<string>& currPartition,vector<vector<bool>>& t,vector<vector<string>>& result){
        if(i==s.length()){
            result.push_back(currPartition);
            return;
        }
        for(int j=i;j<s.length();j++){
            if(t[i][j]){
                currPartition.push_back(s.substr(i,j-i+1));
                solve(j+1,s,currPartition,t,result);
                currPartition.pop_back();
            }
        }
    }
    public:
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<bool>> t(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            t[i][i]=true;
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(l==2 && s[i]==s[j]){
                    t[i][j]=true;
                }else{
                    t[i][j]=(s[i]==s[j] && t[i+1][j-1]);
                }
            }
        }
        vector<vector<string>> result;
        vector<string> currPartition;
        solve(0,s,currPartition,t,result);
        return result;
    }
};
