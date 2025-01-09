class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        int maxLength=1;
        vector<int> t(n,1);
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    t[i]=max(t[i],t[j]+1);
                    maxLength=max(maxLength,t[i]);
                }
            }
        }
        return maxLength;
    }
};
