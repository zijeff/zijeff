int judge(int *a, int *b, int len_a, int len_b)
{
    for (int i = 0; i < len_a; i++)
    {
        for (int j = 0; j < len_b; j++)
        {
            if (a[i] == b[j])
                return 1;
        }
    }
    return 0;
}
int minimumTeachings(int n, int **languages, int languagesSize, int *languagesColSize, int **friendships, int friendshipsSize, int *friendshipsColSize)
{
    int people_to_teach[languagesSize];
    for (int i = 0; i < languagesSize; i++)
        people_to_teach[i] = 0;
    for (int i = 0; i < friendshipsSize; i++)
    {
        int u = friendships[i][0] - 1;
        int v = friendships[i][1] - 1;
        int flag = judge(languages[u], languages[v], languagesColSize[u], languagesColSize[v]);
        if (flag == 0)
        {
            people_to_teach[u] = 1;
            people_to_teach[v] = 1;
        }
    }
    int max = 0, tmp = 0, all = 0;
    for (int i = 0; i < languagesSize; i++)
    {
        if (people_to_teach[i] == 1)
            all++;
    }
    for (int i = 1; i <= n; i++)
    {
        tmp = 0;
        for (int j = 0; j < languagesSize; j++)
        {
            if (people_to_teach[j] == 1)
            {
                for (int k = 0; k < languagesColSize[j]; k++)
                {
                    if (languages[j][k] == i)
                    {
                        tmp++;
                        break;
                    }
                }
            }
        }
        if (tmp > max)
            max = tmp;
    }
    return all - max;
}
