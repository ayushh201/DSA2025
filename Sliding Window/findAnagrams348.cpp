class Solution {
    private:
    bool allZero(vector<int> &counter){
        for(int &i:counter){
            if(i!=0){
                return false;
            }
        }
        return true;
    }

public:
    vector<int> findAnagrams(string txt, string pat) {
        int n=txt.length();
        int k=pat.length();
        vector<int> counter(26,0);
        for(int i=0;i<k;i++){
            char ch=pat[i];
            counter[ch-'a']++;
        }
        int i=0,j=0;
        vector<int> result;
        while(j<n){
            counter[txt[j]-'a']--;
            if(j-i+1==k){
                if(allZero(counter)){
                    result.push_back(i);
                }
                counter[txt[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};
