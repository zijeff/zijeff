class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        int res = 0;
        while (num1 != 0 && num2 != 0)
        {
            int max = 0;
            res++;
            if (num1 > num2)
            {
                max = num1;
                num1 = max - num2;
            }
            else
            {
                max = num2;
                num2 = max - num1;
            }
        }
        return res;
    }
};
