typedef struct
{
    int data[10000];
    int top;
    int min[10000];
} MinStack;
MinStack *minStackCreate()
{
    MinStack *s = (MinStack *)malloc(sizeof(MinStack));
    s->top = -1;
    return s;
}
void minStackPush(MinStack *obj, int val)
{
    obj->top++;
    obj->data[obj->top] = val;
    if (obj->top == 0)
    {
        obj->min[0] = val;
        return;
    }
    if (val < obj->min[obj->top - 1])
        obj->min[obj->top] = val;
    else
        obj->min[obj->top] = obj->min[obj->top - 1];
}
void minStackPop(MinStack *obj)
{
    obj->top--;
}
int minStackTop(MinStack *obj)
{
    return obj->data[obj->top];
}
int minStackGetMin(MinStack *obj)
{
    return obj->min[obj->top];
}
void minStackFree(MinStack *obj)
{
    free(obj);
}
