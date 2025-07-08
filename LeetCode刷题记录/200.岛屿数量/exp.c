int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int x, int y, char **grid, int gridSize, int *gridColSize, int vis[][gridColSize[0]])
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < gridSize && ny >= 0 && ny < gridColSize[0] && grid[nx][ny] == '1' && vis[nx][ny] != 1)
        {
            dfs(nx, ny, grid, gridSize, gridColSize, vis);
        }
    }
}
int numIslands(char **grid, int gridSize, int *gridColSize)
{
    int res = 0;
    int vis[gridSize][gridColSize[0]];
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[0]; j++)
        {
            vis[i][j] = 0;
        }
    }
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[0]; j++)
        {
            if (grid[i][j] == '1'&&vis[i][j]!=1)
            {
                res++;
                dfs(i, j, grid, gridSize, gridColSize, vis);
            }
        }
    }
    return res;
}
