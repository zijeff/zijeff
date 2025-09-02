typedef struct
{
    int data[1000];
    int front, rear;
} Queue;
bool isBipartite(int **graph, int graphSize, int *graphColSize)
{
    int color[graphSize];
    for (int i = 0; i < graphSize; i++)
        color[i] = 0;
    Queue q;
    for (int start = 0; start < graphSize; start++)
    {
        if (color[start] != 0)
            continue;
        q.front = 0;
        q.rear = 0;
        q.data[q.rear++] = start;
        color[start] = 1;
        while (q.front != q.rear)
        {
            int u = q.data[q.front];
            q.front++;
            int next_color = 0;
            if (color[u] == 1)
                next_color = 2;
            else
                next_color = 1;
            for (int i = 0; i < graphColSize[u]; i++)
            {
                int v = graph[u][i];
                if (color[v] == color[u])
                    return false;
                if (color[v] == 0)
                {
                    color[v] = next_color;
                    q.data[q.rear++] = v;
                }
            }
        }
    }
    return true;
}
