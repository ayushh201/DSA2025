#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool allZero(vector<int> &counter){
        for(int &i:counter){
            if(i!=0) return false;
        }
        return true;
    }
    int search(string &pat, string &txt) {
        int n=txt.length();
        int k=pat.length();
        vector<int> counter(26,0);
        for(int i=0;i<pat.length();i++){
            char ch=pat[i];
            counter[ch-'a']++;
        }
        int i=0,j=0;
        int result=0;
        while(j<n){
            counter[txt[j]-'a']--;
            if(j-i+1==k){
                if(allZero(counter)){
                    result++;
                }
                counter[txt[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
