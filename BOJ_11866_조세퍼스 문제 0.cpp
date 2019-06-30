#includestdio.h
int main()
{
	unsigned int n, m, a[1001], front = 0;
	scanf(%u %u, &n, &m);
	for (int i = 0; i  n; i++)
		a[i] = i + 1;
	printf();
	while (1)
	{
		front = (front + m - 1) % n;
		printf(%u, a[front]);
		int b[1001], b_i = 0;
		for (int i = 0; i  front; i++)
			b[b_i++] = a[i];
		for (int i = front + 1; i  n; i++)
			b[b_i++] = a[i];
		for (int i = 0; i  b_i; i++)
			a[i] = b[i];
		n--;
		if (n == 0)
			break;
		printf(, );
	}
	printf(n);
	return 0;
}
