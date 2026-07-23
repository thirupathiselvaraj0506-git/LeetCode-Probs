class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(int i=0;i<intervals.size();i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
                continue;
            }
            if(intervals[i][0]>=ans.back()[0] && intervals[i][0]<=ans.back()[1]){
                if(ans.back()[1]<intervals[i][1]){
                    ans.back()[1]=intervals[i][1];
                }
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};