class Solution {
private:
    void dfs(string endWord,string beginWord,vector<string>& opt,vector<vector<string>>& ans,unordered_map<string,int>& mpp){
        if(endWord==beginWord){
            reverse(opt.begin(),opt.end());
            ans.push_back(opt);
            reverse(opt.begin(),opt.end());
            return ;
        }
        int steps=mpp[endWord];
        for(int i=0;i<endWord.size();i++){
            char org=endWord[i];
            for(int j=0;j<26;j++){
                endWord[i]=j+'a';
                if(mpp.count(endWord) && mpp[endWord]+1==steps){
                    opt.push_back(endWord);
                    dfs(endWord,beginWord,opt,ans,mpp);
                    opt.pop_back();
                }
            }
            endWord[i]=org;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>myset(wordList.begin(),wordList.end());
        if(myset.find(endWord)==myset.end()) return {};
        unordered_map<string,int>mpp;
        vector<vector<string>>ans;
        queue<string>q;
        mpp[beginWord]=1;
        q.push(beginWord);
        myset.erase(beginWord);
        while(!q.empty()){
            string s=q.front();
            q.pop();
            int steps=mpp[s];
            for(int i=0;i<s.size();i++){
                char org=s[i];
                for(int j=0;j<26;j++){
                    s[i]=j+'a';
                    if(myset.count(s)){
                        q.push(s);
                        myset.erase(s);
                        mpp[s]=steps+1;
                    }
                }
                s[i]=org;
            }
        }
        if(mpp.count(endWord)){
            vector<string>opt;
            opt.push_back(endWord);
            dfs(endWord,beginWord,opt,ans,mpp);
        }
        return ans;
    }
};