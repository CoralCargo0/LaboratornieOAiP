#include <stdio.h>
#include<locale.h>
#define n 15

int main()
{
	setlocale(LC_ALL, "Russian");
	int f=1,i=1,m=0;
	int ms[n];
	printf_s("Введите числa \n");
	for (i=0 ; i < n; i++) 
	{
		scanf_s("%d", &ms[i]);
		if (ms[i] < 0)
		{
			ms[i] = 0;
			m+=1;
		}
	}
	printf_s("m = %d \n", m);
	i = m;
	while (i > 0)
	{
		f *= i;
		i -= 1;
	}
	printf_s("Числа нового массива  ");
	for (i = 0; i < n; i++)
	{
		printf_s(" %d ", ms[i]);
	}
     printf_s("\nФакториал = %d", f);

}