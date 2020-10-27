#include <stdio.h>
#include<locale.h>
#include<stdlib.h>


int main()
{
	setlocale(LC_ALL, "Russian");    //Русификация вывода
	int size, Column, i, num = 0, Line, ** array, * ms0, amount;
	printf_s("Введите размерность матрицы \n");
	do
	{
		amount = scanf_s("%d", &size);                            //Ввод и проверка размерности
		if (amount == 0)
		{
			printf("Ошибка, пожалуйста введите число\n");
			rewind(stdin);
		}
	} while (amount == 0);
	printf_s("Введите числa \n");
	if (!(ms0 = (int*)calloc(size * size, sizeof(int))))return 0;//Выделение и проверка памяти под начальный массив
	if (!(array = (int**)calloc(size, sizeof(int*))))            //Выделение и проверка памяти для конечной матрицы
	{
		free(ms0);
		return 0;
	}
	for (Column = 0; Column < size; Column++)
	{
		if (!(array[Column] = (int*)calloc(size, sizeof(int))))
		{
			free(ms0);
			free(array);
			return 0;
		}
	}
	for (Column = 0; Column < size * size; Column++)             // Ввод и проверка массива
	{
		do
		{
			amount = scanf_s("%d", &ms0[Column]);
			if (amount == 0)
			{
				printf("Ошибка, пожалуйста введите число\n");
				rewind(stdin);
			}
		} while (amount == 0);
	}Line = 0; Column = 0;
	if (size % 2 == 1)amount = size / 2 + 1;                    //Рассчет количества витков
	else amount = size / 2;
	for (i = 0; i < amount; i++)
	{
		while (Column + 2 * i < size)                            //Размещение элементов по строкам вправо
		{
			*(*(array + Line + i) + Column + i) = *(ms0 + num);
			num++; Column++;
		}Column--; Line++;
		while (Line + 2 * i < size)                              //Размещение элементов по столбцам вниз
		{
			*(*(array + Line + i) + Column + i) = *(ms0 + num);
			num++; Line++;
		}Line--; Column--;
		while (Column > -1)                                    //Размещение элементов по строкам влево
		{
			*(*(array + Line + i) + Column + i) = *(ms0 + num);
			num++; Column--;
		}Column++; Line--;
		while (Line > 0)                                       //Размещение элементов по столбцам вверх
		{
			*(*(array + Line + i) + Column + i) = *(ms0 + num);
			num++; Line--;
		}
	}
	for (Line = 0; Line < size; Line++)                        //Вывод полученной матрицы 
	{
		for (Column = 0; Column < size; Column++)
		{
			printf("%4d ", *(*(array + Line) + Column));
		}
		printf("\n");
	}free(array); free(ms0);
	return 0;
}