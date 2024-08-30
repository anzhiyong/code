#define _CRT_SECURE_NO_WARNINGS
//´òÓ¡1~100µÄ9
#include<stdio.h>
int main()
{
	int i = 0;
	int g, s;
	int n=0;
	for (i = 9; i <= 99; i+=10)
	{
		
		g = i % 10;
		s = i / 10;
		if (g == 9)
		{
			n++;
			if (s == 9)
			{
				n++;
			}
		}
		
	}
	printf("%d ", n);
}