class Solution {
    public:
    int t[1001][1001];
    static bool comparator(string &w1,string &w2){
        return w1.length()<w2.length();
    }
    bool isPredecessor(string &word,string &prev){
        int N=word.length();
        int M=prev.length();
        if(M>=N || N-M!=1){
            return false;
        }
        int i=0,j=0;
        while(i<M && j<N){
            if(prev[i]==word[j]){
                i++;
            }
            j++;
        }
        return i==M;
    }
    int solve(int i,int prev,vector<string>& words){
        if(i==n){
            return 0;
        }
        if(prev!=-1 && t[i][prev]!=-1){
            return t[i][prev];
        }
        int take=0,not_take=0;
        if(prev==-1 || isPredecessor(words[i],words[prev])){
            take=1+solve(i+1,i,words);
        }
        not_take=solve(i+1,prev,words);
        if(prev!=-1){
            t[i][prev]=max(take,not_take);
        }
        return max(take,not_take);
    }
public:
    int n;
    int longestStrChain(vector<string>& words) {
        n=words.size();
        memset(t,-1,sizeof(t));
        sort(begin(words),end(words),comparator);
        return solve(0,-1,words);
    }
};
