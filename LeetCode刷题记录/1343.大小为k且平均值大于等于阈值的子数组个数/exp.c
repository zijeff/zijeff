int numOfSubarrays(int *arr, int arrSize, int k, int threshold)
{
	int res = 0;
	int sum = 0;
	int a = 0, b = k - 1;
	for (int i = 0; i <= b; i++)
	{
		sum += arr[i];
	}
	if (sum >= k * threshold)
		res++;
	while (b < arrSize - 1)
	{
		b++;
		sum += arr[b];
		sum -= arr[a];
		a++;
		if (sum >= k * threshold)
			res++;
	}
	return res;
}
