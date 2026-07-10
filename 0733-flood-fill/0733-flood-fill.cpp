class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org=image[sr][sc];
        int R=image.size(),C=image[0].size();
        if(org==color) return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int diff[5]={0,1,0,-1,0};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            image[row][col]=color;
            for(int i=0;i<4;i++){
                int adjr=row+diff[i];
                int adjc=col+diff[i+1];
                if(adjr>=0 && adjr<R && adjc>=0 && adjc<C && image[adjr][adjc]==org){
                    q.push({adjr,adjc});
                }
            }
        }
        return image;
    }
};