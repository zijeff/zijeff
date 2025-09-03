typedef struct
{
    int x;
    int y;
    int step;
} Block;
int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int shortestPathBinaryMatrix(int **grid, int gridSize, int *gridColSize)
{
    if (grid[0][0] == 1)
        return -1;
    Block q[10000];
    int front = 0, rear = 0;
    int vis[gridSize][gridSize];
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[i]; j++)
        {
            vis[i][j] = 0;
        }
    }
    vis[0][0] = 1;
    q[rear].x = 0;
    q[rear].y = 0;
    q[rear].step = 1;
    rear++;
    while (front != rear)
    {
        Block current = q[front];
        front++;
        if (current.x == gridSize - 1 && current.y == gridSize - 1)
            return current.step;
        for (int i = 0; i < 8; i++)
        {
            int nx = current.x + dir[i][0];
            int ny = current.y + dir[i][1];
            if (nx >= 0 && nx < gridSize && ny >= 0 && ny < gridSize && vis[nx][ny] == 0 && grid[nx][ny] == 0)
            {
                vis[nx][ny] = 1;
                q[rear].x = nx;
                q[rear].y = ny;
                q[rear].step = current.step + 1;
                rear++;
            }
        }
    }
    return -1;
}
