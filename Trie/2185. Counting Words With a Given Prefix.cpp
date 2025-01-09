class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(string &word:words){ //O(n)
            if(word.find(pref)==0){ //O(m)
                count++;
            }
        }
        //TC->O(m*n)
        return count;
    }
};


struct trieNode{
    trieNode* children[26];
    bool isEndOfWord;
    int count; //to check the count of prefix
};

trieNode* getNode(){
    trieNode* newNode=new trieNode();
    newNode->isEndOfWord=false;
    newNode->count=0;
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
    void insert(string &word){
        trieNode* pCrawl=root;
        for(char &ch:word){
            int idx=ch-'a';
            if(pCrawl->children[idx]==nullptr){
                pCrawl->children[idx]=getNode();
            }
            pCrawl=pCrawl->children[idx];
            pCrawl->count++;
        }
        pCrawl->isEndOfWord=true;
    }
    int searchPrefixCount(string &prefix){
        trieNode* pCrawl=root;
        for(char &ch:prefix){
            int idx=ch-'a';
            if(pCrawl->children[idx]==nullptr){
                return 0;
            }
            pCrawl=pCrawl->children[idx];
        }
        return pCrawl->count;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;
        for(string &word:words){ //0(N)
            trie.insert(word); //TAKING AVG LENGTH OF WORD-> L 0(L)
        }
        return trie.searchPrefixCount(pref); //0(M)
    }
};

//TC->0(N*L+M)
