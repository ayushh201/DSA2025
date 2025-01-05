class Solution {
    int solve(int i,int maxEnd,vector<pair<int,int>> &interval){
        if(i>=interval.size()){
            if(maxEnd>=gardenSize){
                return 0;
            }else{
                return 1e9;
            }
        }
        if(mp.find({i,maxEnd})!=mp.end()){
            return mp[{i,maxEnd}];
        }
        if(interval[i].first>maxEnd){
            return 1e9;
        }
        int open=1+solve(i+1,max(maxEnd,interval[i].second),interval);
        int not_open=solve(i+1,maxEnd,interval);
        return mp[{i,maxEnd}]=min(open,not_open);
    }
public:
    map<pair<int,int>,int> mp;
    int gardenSize;
    int minTaps(int n, vector<int>& ranges) {
        gardenSize=n;
        vector<pair<int,int>> interval;
        int i=0;
        for(int range:ranges){
            int start=max(0,i-range);
            int end=min(n,i+range);
            interval.push_back({start,end});
            i++;
        }
        sort(begin(interval),end(interval));
        int result=solve(0,0,interval);
        return result==1e9? -1:result;
    }
};
