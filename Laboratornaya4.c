#include <stdio.h>
#include<locale.h>
#define n 15

int main()
{
	setlocale(LC_ALL, "Russian");//Русификация вывода
	int f=1,i=1,m=0,ms[n]; 
	printf_s("Введите числa \n");
	for (i=0 ; i < n; i++) // Ввод массива
	{
		scanf_s("%d", &ms[i]);
		if (ms[i] < 0)
		{
			ms[i] = 0;//Замена отрицательных чисел нулями
			m+=1;     //Подсчет числа m
		}
	}
	printf_s("m = %d \n", m);//Вывод числа m
	i = m;
	while (i > 0)//Вычисление факториала
	{
		f *= i;
		i -= 1;
	}
	printf_s("Числа нового массива  ");
	for (i = 0; i < n; i++)//Вывод массива с замененными элементами
	{
		printf_s(" %d ", ms[i]);
	}
     printf_s("\nФакториал = %d", f);

}
