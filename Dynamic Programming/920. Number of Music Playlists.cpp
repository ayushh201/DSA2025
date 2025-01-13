class Solution {
    private:
    long solve(int count_song,int count_unique,int n, int goal, int k){
        if(count_song==goal){
            if(count_unique==n){
                return t[count_song][count_unique]=1;
            }else{
                return t[count_song][count_unique]=0;
            }
        }
        if(t[count_song][count_unique]!=-1){
            return t[count_song][count_unique];
        }
        long result=0;
        //unique
        if(count_unique<n){
            result+=(n-count_unique)*solve(count_song+1,count_unique+1,n,goal,k);
        }
        //repeat
        if(count_unique>k){
            result+=(count_unique-k)*solve(count_song+1,count_unique,n,goal,k);
        }
        return t[count_song][count_unique]=result%M;
    }
public:
    long t[101][101];
    const int M=1e9+7;
    int numMusicPlaylists(int n, int goal, int k) {
        memset(t,-1,sizeof(t));
        return solve(0,0,n,goal,k);
    }
};
