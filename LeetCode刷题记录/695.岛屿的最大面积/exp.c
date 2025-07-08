int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int x, int y, int **grid, int gridSize, int *gridColSize, int vis[][gridColSize[0]], int *s)
{
    vis[x][y] = 1;
    (*s)++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < gridSize && ny >= 0 && ny < gridColSize[0] && grid[nx][ny] == 1 && vis[nx][ny] != 1)
        {
            dfs(nx, ny, grid, gridSize, gridColSize, vis, s);
        }
    }
}
int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize)
{
    int max = 0;
    int vis[gridSize][gridColSize[0]];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[0]; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                int tmp = 0;
                dfs(i, j, grid, gridSize, gridColSize, vis, &tmp);
                if (tmp > max)
                    max = tmp;
            }
        }
    }
    return max;
}
