int squeue[100000] = {0};
int front = -1, rear = -1;
bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize)
{
    int vis[roomsSize];
    int i = 0;
    for (i = 0; i < roomsSize; i++)
    {
        vis[i] = 0;
    }
    rear++;
    vis[0] = 1;
    squeue[rear] = 0;
    while (front < rear)
    {
        front++;
        int now = squeue[front];
        for (i = 0; i < roomsColSize[now]; i++)
        {
            int next = rooms[now][i];
            if (vis[next] != 1)
            {
                rear++;
                vis[next] = 1;
                squeue[rear] = next;
            }
        }
    }
    for (i = 0; i < roomsSize; i++)
    {
        if (vis[i] == 0)
        {
            return false;
        }
    }
    return true;
}
