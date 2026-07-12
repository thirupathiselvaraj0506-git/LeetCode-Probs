class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>myset;
        int ans=0;
        for(char ch:s){
            if(myset.find(ch)!=myset.end()){
                myset.clear();
                ans++;
                myset.insert(ch);
            }else{
                myset.insert(ch);
            }
        }
        return ans+1;
    }
};