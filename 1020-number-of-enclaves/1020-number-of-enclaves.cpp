class Solution {
int diff[5]={0,1,0,-1,0};
private:
    void dfs(vector<vector<int>>& grid,int row,int col,int R,int C){
        grid[row][col]=0;
        for(int i=0;i<4;i++){
            int adjr=row+diff[i];
            int adjc=col+diff[i+1];
            if(adjr>=0 && adjr<R && adjc>=0 && adjc<C && grid[adjr][adjc]==1){
                dfs(grid,adjr,adjc,R,C);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                if(row==0 || row==R-1 || col==0 || col==C-1){
                    if(grid[row][col]==1){
                        dfs(grid,row,col,R,C);
                    }
                }
            }
        }
        int ans=0;
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                if(grid[row][col]==1) ans++;
            }
        }
        return ans;
    }
};