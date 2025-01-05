class Solution {
    private:
    bool solve(int currentStoneIndex,int previousJump,vector<int>& stones){
        if(currentStoneIndex==stones.size()-1){
            return true;
        }
        if(t[currentStoneIndex][previousJump]!=-1) return t[currentStoneIndex][previousJump];
        bool result=false;
        for(int nextJump=previousJump-1;nextJump<=previousJump+1;nextJump++){
            if(nextJump>0){
                int nextStone=stones[currentStoneIndex]+nextJump;
                if(mp.find(nextStone)!=mp.end()){
                    result=result||solve(mp[nextStone],nextJump,stones);
                }
            }
        }
        return t[currentStoneIndex][previousJump]=result;
    }
public:
    int t[2001][2001];
    unordered_map<int,int> mp;
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        int n=stones.size();
        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        return solve(0,0,stones);
    }
};
