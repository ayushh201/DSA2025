class Solution {
public:
// TC -> m * DFS 
    char dfsMin(unordered_map<char,vector<char>> &adj,char currentCharacter,vector<int> &visited){
        visited[currentCharacter-'a'] = 1;
        char minChar = currentCharacter;
        for(char &v : adj[currentCharacter]){
            if(!visited[v-'a']){
                minChar = min(minChar,dfsMin(adj,v,visited));
            }
        }
        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();
        unordered_map<char,vector<char>> adj;
        for(int i=0;i<n;i++){
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string result;
        for(int i=0;i<m;i++){
            char currentCharacter = baseStr[i];
            vector<int> visited(26,0);
            char minChar = dfsMin(adj,currentCharacter,visited);
            result.push_back(minChar);
        }
        return result;
    }
};
