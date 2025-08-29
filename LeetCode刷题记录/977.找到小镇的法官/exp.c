int findJudge(int n, int **trust, int trustSize, int *trustColSize)
{
    int judge = -1;
    int people[1000] = {0};
    for (int i = 0; i < trustSize; i++)
        people[trust[i][0] - 1] = 1;
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        if (people[i] == 0)
        {
            for (int j = 0; j < trustSize; j++)
            {
                if (trust[j][1] == i + 1)
                    num++;
            }
            if (num == n - 1)
            {
                judge = i + 1;
                break;
            }
        }
    }
    return judge;
}
