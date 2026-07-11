class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int>myset;
        for(auto vec:edges){
            for(auto x:vec){
                if(myset.find(x)!=myset.end()){
                    return x;
                }
                myset.insert(x);
            }
        }
        return 0;
    }
};