class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int R=grid.size();
        int C=grid[0].size();
        int N=R*C;
        k=k%N;
        auto shift=[&](int i,int j){
            while(i<j){
                swap(grid[i/C][i%C],grid[j/C][j%C]);
                i++,j--;
            }
        };
        shift(0,N-1);
        shift(0,k-1);
        shift(k,N-1);
        return grid;
    }
};