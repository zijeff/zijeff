int canBeTypedWords(char* text, char* brokenLetters) {
    int broken[26] = {0};
    for (int i = 0; brokenLetters[i]; i++) {
        broken[brokenLetters[i] - 'a'] = 1;
    }
    int res = 0, flag = 1;
    for (int i = 0; text[i]; i++) {
        if (text[i] == ' ') {
            if (flag == 1) {
                res++;
            }
            flag = 1;
        } else if (broken[text[i] - 'a'] == 1) {
            flag = 0;
        }
    }
    if (flag == 1) {
        res++;
    }
    return res;
}
