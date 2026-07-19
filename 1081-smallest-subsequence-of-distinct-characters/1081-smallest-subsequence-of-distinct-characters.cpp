class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        unordered_set<char>myset;
        unordered_map<char,int>lastocc;
        for(int i=0;i<s.size();i++){
            lastocc[s[i]]=i;
        }
        for(int i=0;i<s.size();i++){
            if(!myset.count(s[i])){
                while(!st.empty() && s[i]<st.top() && i<lastocc[st.top()]){
                    myset.erase(st.top());
                    st.pop();
                }
                myset.insert(s[i]);
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};