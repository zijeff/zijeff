typedef struct
{
    int data[100000];
    int top;
} Stack;
int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize)
{
    *returnSize = temperaturesSize;
    int *res = (int *)malloc(temperaturesSize * sizeof(int));
    for (int i = 0; i < temperaturesSize; i++)
        res[i] = 0;
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->top++;
    s->data[s->top] = 0;
    for (int i = 1; i < temperaturesSize; i++)
    {
        while (s->top != -1 && temperatures[i] > temperatures[s->data[s->top]])
        {
            int tmp = s->data[s->top];
            res[tmp] = i - tmp;
            s->top--;
        }
        s->top++;
        s->data[s->top] = i;
    }
    return res;
}
