void dfs(int **isConnected, int isConnectedSize, int i, int vis[])
{
    vis[i] = 1;
    for (int j = 0; j < isConnectedSize; j++)
    {
        if (isConnected[i][j] == 1 && vis[j] != 1)
        {
            dfs(isConnected, isConnectedSize, j, vis);
        }
    }
}
int findCircleNum(int **isConnected, int isConnectedSize, int *isConnectedColSize)
{
    int provinces = 0;
    int vis[isConnectedSize];
    for (int i = 0; i < isConnectedSize; i++)
    {
        vis[i] = 0;
    }
    for (int i = 0; i < isConnectedSize; i++)
    {
        if (vis[i] != 1)
        {
            dfs(isConnected, isConnectedSize, i, vis);
            provinces++;
        }
    }
    return provinces;
}
