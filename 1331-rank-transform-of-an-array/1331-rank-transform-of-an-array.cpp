class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]].push_back(i);
        }
        int rnk=1;
        for(auto x:mpp){  
            for(int i=0;i<x.second.size();i++){
                arr[x.second[i]]=rnk;
            }
            rnk++;
        }
        return arr;
    }
};