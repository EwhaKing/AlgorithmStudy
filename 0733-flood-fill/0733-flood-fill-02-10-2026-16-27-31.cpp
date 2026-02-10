class Solution {

private: 
    void dfs(vector<vector<int>>& grid, int i, int j, int orgColor, int newColor){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=orgColor || orgColor==newColor) return;
        grid[i][j]=newColor;
        dfs(grid, i-1, j, orgColor, newColor);
        dfs(grid, i+1, j, orgColor, newColor);
        dfs(grid, i, j-1, orgColor, newColor);
        dfs(grid, i, j+1, orgColor, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};