class Solution {

private: 
    void dfs(vector<vector<int>>& grid, int i, int j, int orgColor, int newColor){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=orgColor) return;
        grid[i][j]=newColor;
        dfs(grid, i-1, j, orgColor, newColor);
        dfs(grid, i+1, j, orgColor, newColor);
        dfs(grid, i, j-1, orgColor, newColor);
        dfs(grid, i, j+1, orgColor, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image; 
        // orgColor=newColor면 그대로 return. 
        // 인접한 픽셀의 색이 orgColor가 아니면 그건 인접한 게 아님, 인접한 '같은 색'의 픽셀만 바꿈 
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};