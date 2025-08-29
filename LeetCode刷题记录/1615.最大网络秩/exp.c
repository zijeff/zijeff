int maximalNetworkRank(int n, int **roads, int roadsSize, int *roadsColSize)
{
    int max = 0;
    int degree[100] = {0};
    int connect[100][100] = {0};
    for (int i = 0; i < roadsSize; i++)
    {
        int a = roads[i][0], b = roads[i][1];
        degree[a]++;
        degree[b]++;
        connect[a][b] = 1;
        connect[b][a] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int tmp = 0;
        for (int j = i + 1; j < n; j++)
        {
            tmp = degree[i] + degree[j];
            if (connect[i][j] == 1)
                tmp--;
            if (tmp > max)
                max = tmp;
        }
    }
    return max;
}
