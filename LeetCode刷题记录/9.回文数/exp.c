bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int num[20] = {0};
    int len = 0;
    while (x > 0)
    {
        num[len++] = x % 10;
        x = x / 10;
    }
    int i = 0, j = len - 1;
    while (i < j)
    {
        if (num[i] == num[j])
        {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}
