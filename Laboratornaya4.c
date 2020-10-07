#include <stdio.h>
#include<locale.h>
#define n 8 

int main()
{
	setlocale(LC_ALL, "Russian");
	int f = 1, i, m = 0, ms[n], error;
	printf_s("Введите числa \n");
	for (i = 0; i < n; i++) // Ввод массива
	{
		do                        //Проверка вводимых значений
		{
			error = scanf_s("%d", &ms[i]);
			if (error == 0)
			{
				printf("Ошибка, пожалуйста введите число\n");
				rewind(stdin);
			}
		} while (error == 0);
		if (ms[i] < 0)
		{
			ms[i] = 0;//Замена отрицательных чисел нулями
			m += 1;     //Подсчет числа m
		}
	}
	printf_s("Число замененных элементов m = %d \n", m);
	i = m;
	while (i > 0)                  //Высчитывание факториала
	{
		f *= i;
		i -= 1;
	}
	printf_s("Числа нового массива  ");
	for (i = 0; i < n; i++)                 //Вывод новогомассива
	{
		printf_s(" %d ", ms[i]);
	}
	printf_s("\nФакториал = %d", f);
	return (0);
}
