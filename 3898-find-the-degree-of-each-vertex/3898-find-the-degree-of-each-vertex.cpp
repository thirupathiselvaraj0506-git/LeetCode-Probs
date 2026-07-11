class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>ans(matrix.size(),0);
        for(int row=0;row<matrix.size();row++){
            for(int col=0;col<matrix[0].size();col++){
                if(matrix[row][col]==1){
                    ans[row]++;
                }
            }
        }
        return ans;
    }
};