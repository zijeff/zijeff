int maxFrequencyElements(int *nums, int numsSize)
{
    int Frequency[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
        Frequency[i] = 0;
    }
    int max = 0;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (nums[j] == nums[i])
                Frequency[i]++;
        }
        if (Frequency[i] > max)
            max = Frequency[i];
    }
    int res = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (Frequency[i] == max)
            res += max;
    }
    return res / max;
}
