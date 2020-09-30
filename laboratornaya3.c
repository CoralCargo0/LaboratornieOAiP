#include <stdio.h>
#include<locale.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	int n,error, kol = 0, i20, i10, i, i5;
	printf("Введите число <= 99\n");
	do
	{
		error = scanf_s("%d", &n);
		if (error == 0 || n <= 0 || n>99)
		{
			printf("Ошибка, пожалуйста введите число от 0 до 99\n");
			error = 0;
			rewind(stdin);
		}
	} while (error == 0);
	for (i20 = 0; i20 <= n / 20; i20++)
    for (i10 = 0; i10 <= n / 10; i10++)
    for (i5 = 0; i5 <= n / 5; i5++)
	{
			i = n - i20 * 20 - i10 * 10 - i5 * 5;
			if (i <0)break;
			kol++;
			printf("Решение номер %d Монет номиналом 20 = %d Монет номиналом 10 = %d Монет номиналом 5 = %d Монет номиналом 1 = %d\n",kol,i20, i10, i5, i);

    }printf("Всего решений = %d\n ", kol);
	return(0);
} 