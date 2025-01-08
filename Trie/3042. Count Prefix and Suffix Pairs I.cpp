struct trieNode{
    trieNode* children[26];
    bool isEndOfWord;
};

trieNode* getNode(){
    trieNode* newNode=new  trieNode();
    newNode->isEndOfWord=false;
    for(int i=0;i<26;i++){
        newNode->children[i]=nullptr;
    }
    return newNode;
}

class Trie{
    public:
    trieNode* root;
    Trie(){
        root=getNode();
    }
    void insert(string word){
        trieNode* pCrawl=root;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
            if(pCrawl->children[idx]==nullptr){
                pCrawl->children[idx]=getNode();
            }
            pCrawl=pCrawl->children[idx];
        }
        pCrawl->isEndOfWord=true;
    }
    bool searchPrefix(string prefix){
        trieNode* pCrawl=root;
        for(int i=0;i<prefix.length();i++){
            int idx=prefix[i]-'a';
            if(pCrawl->children[idx]==nullptr){
                return false;
            }
            pCrawl=pCrawl->children[idx];
        }
        return true;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& str) {
        int n=str.size();
        int count=0;
        for(int j=0;j<n;j++){
            Trie prefixTree;
            Trie suffixTree;
            prefixTree.insert(str[j]);
            string reversed=str[j];
            reverse(begin(reversed),end(reversed));
            suffixTree.insert(reversed);
            for(int i=0;i<j;i++){
                string rev=str[i];
                reverse(begin(rev),end(rev));
                if(prefixTree.searchPrefix(str[i])==true && suffixTree.searchPrefix(rev)==true){
                    count++;
                }
            }
        }
        return count;
    }
};
