typedef struct
{
    int data[1000];
    int top;
} MyStack;
MyStack *myStackCreate()
{
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->top = -1;
    return s;
}
void myStackPush(MyStack *obj, int x)
{
    obj->top++;
    obj->data[obj->top] = x;
}
int myStackPop(MyStack *obj)
{
    int e = obj->data[obj->top];
    obj->top--;
    return e;
}
int myStackTop(MyStack *obj)
{
    return obj->data[obj->top];
}
bool myStackEmpty(MyStack *obj)
{
    if (obj->top == -1)
        return true;
    else
        return false;
}
void myStackFree(MyStack *obj)
{
    free(obj);
}
