typedef struct linknode{
    char data;
    struct linknode *next;
}LinkStack;
void PushStack(LinkStack *st, char s){
    LinkStack *p = (LinkStack *)malloc(sizeof(LinkStack));
    p->data = s;
    p->next = st->next;
    st->next = p;
}
void PopStack(LinkStack *st){
    LinkStack *p = st->next;
    st->next = p->next;
    free(p);
}
void InitStack(LinkStack *st){
    st->next = NULL; 
}
int TypeJudge(char a, char b){
    int res = 0;
    if(a == '('&&b == ')') {res = 1;}
    if(a == '['&&b == ']') {res = 1;}
    if(a == '{'&&b == '}') {res = 1;}
    return res;
}
bool isValid(char* s) {
    int i = 0;
    LinkStack *st = (LinkStack *)malloc(sizeof(LinkStack));
    InitStack(st);
    while(s[i] != '\0'){
        if(s[i] == '('||s[i] == '['||s[i] == '{')
        {PushStack(st, s[i]);}
        else{
            if(st->next == NULL) {return false;}
            else{
                LinkStack *p = st->next;
                if(TypeJudge(p->data, s[i]) == 0) {return false;}
                else{PopStack(st);}
            }
        }
        i++;
    }
    if(st->next != NULL) {return false;}
    else {return true;}
}
