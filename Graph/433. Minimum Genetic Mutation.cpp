class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(),bank.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==endGene){
                    return level;
                }
                for(char ch:"ACTG"){
                    for(int i=0;i<curr.length();i++){
                        char original=curr[i];
                        curr[i]=ch;
                        if(visited.find(curr)==visited.end() && bankSet.find(curr)!=bankSet.end()){
                            visited.insert(curr);
                            q.push(curr);
                        }
                        curr[i]=original;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
