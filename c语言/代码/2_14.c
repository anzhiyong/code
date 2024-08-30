#include <stdio.h>
int main() {
	int x=0, y=0;
	scanf("%d", &x);
	if (x < 1)
	{
		y = x;
        printf("y=x=%d", y);
	}
	else if (x < 10)
	{
		y = 2*x - 1;
        printf("y=2*x-1=%d", y);
	}
	else
	{
		y = 3*x - 11;
       printf("y=3*x-11=%d", y);
	}
	
	return 0;
}
