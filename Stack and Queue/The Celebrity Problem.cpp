#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n=mat.size();
        vector<int> iknow(n,0), meknow(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    iknow[i]++;
                    meknow[j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(iknow[i]==0 && meknow[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

//Elimination

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n=mat.size();
        int top=0,down=n-1;
        while(top<down){
            if(mat[top][down]==1){
                top+=1;
            }else if(mat[down][top]==1){
                down-=1;
            }else{
                top++;
                down--;
            }
        }
        if(top>down) return -1;
        for(int i=0;i<n;i++){
            if(i==top) continue;
            if(mat[top][i]==0 && mat[i][top]==1){
                continue;
            }else{
                return -1;
            }
        }
        return top;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}
