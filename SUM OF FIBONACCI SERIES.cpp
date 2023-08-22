#include <stdio.h>
int main()
{
	int a=0, b=1, range, c, sum=0;
	printf("enter the range of fibonacci series: ");
	scanf("%d", &range);
	printf("the fibonacci series is: \t");
	while(a<=range)
	{
		printf("%d\t", a);
		sum+=a;
		c = a+b;
		a = b;
		b = c;
	}
	printf("\n their sum is =%d", sum);
	return 0;
	
}
