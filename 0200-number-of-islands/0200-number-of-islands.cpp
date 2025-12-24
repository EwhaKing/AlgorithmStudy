#include <vector>
using namespace std;
class Solution {
private:  //dfs가 public일 필요X
    //DFS: 1의 상하좌우를 0으로 바꿈
    //DFS는 반환값이 필요없음(void), grid 수정하고 끝
    //overflow 주의, 범위 벗어나는 경계 체크
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0')
        return;
        grid[i][j]='0'; 
        dfs(grid, i-1, j); //상
        dfs(grid, i+1, j); //하
        dfs(grid, i, j-1); //좌
        dfs(grid, i, j+1); //우
        }
public:
    int numIslands(vector<vector<char>>& grid) {
        int num=0;
        //row: i, grid.size()
        //column: j, grid[0].size() -- grid[i].size()도 값이 같지만 안전하게 grid[0].size()을 씀
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    num++;
                    dfs(grid, i, j);
                }
            }
        }
        return num;
    }
    
};