class Solution {
    private:
    bool find(int i,int j,int idx,string& word,vector<vector<char>>& board){
        if(idx==word.length()) return true;
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]=='$') return false;
        if(board[i][j]!=word[idx]) return false;

        char ch=board[i][j];
        board[i][j]='$';
        for(vector<int> &dir:directions){
            int di=i+dir[0];
            int dj=j+dir[1];
            if(find(di,dj,idx+1,word,board)){
                return true;
            }
        }
        board[i][j]=ch;
        return false;
    }
public:
    int m,n;
    vector<vector<int>> directions={{1,0},{-1,0},{0,-1},{0,1}};
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && find(i,j,0,word,board)){
                    return true;
                }
            }
        }
        return false;
    }
};
