#include <stdio.h>
#include<locale.h>
#include<stdlib.h>


int main()
{
	setlocale(LC_ALL, "Russian");    //Русификация вывода
	int size, Column, i, num = 0, Line, ** matrix, * array, amount;
	printf_s("Введите размерность матрицы \n");
	do
	{
		amount = scanf_s("%d", &size);                            //Ввод и проверка размерности
		if (amount == 0 || size < 0)
		{
			printf("Ошибка, пожалуйста введите число\n");
			rewind(stdin);
		}
	} while (amount == 0 || size < 0);
	printf_s("Введите числa \n");
	if (!(array = (int*)calloc(size * size, sizeof(int))))return 0;//Выделение и проверка памяти под начальный массив
	if (!(matrix = (int**)calloc(size, sizeof(int*))))            //Выделение и проверка памяти для конечной матрицы
	{
		free(array);
		return 0;
	}
	for (Column = 0; Column < size; Column++)
	{
		if (!(matrix[Column] = (int*)calloc(size, sizeof(int))))
		{
			free(array);
			free(matrix);
			return 0;
		}
	}
	for (Column = 0; Column < size * size; Column++)             // Ввод и проверка массива
	{
		do
		{
			amount = scanf_s("%d", &array[Column]);
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
			*(*(matrix + Line + i) + Column + i) = *(array + num);
			num++; Column++;
		}Column--; Line++;
		while (Line + 2 * i < size)                              //Размещение элементов по столбцам вниз
		{
			*(*(matrix + Line + i) + Column + i) = *(array + num);
			num++; Line++;
		}Line--; Column--;
		while (Column > -1)                                    //Размещение элементов по строкам влево
		{
			*(*(matrix + Line + i) + Column + i) = *(array + num);
			num++; Column--;
		}Column++; Line--;
		while (Line > 0)                                       //Размещение элементов по столбцам вверх
		{
			*(*(matrix + Line + i) + Column + i) = *(array + num);
			num++; Line--;
		}
	}
	for (Line = 0; Line < size; Line++)                        //Вывод полученной матрицы 
	{
		for (Column = 0; Column < size; Column++)
		{
			printf("%4d ", *(*(matrix + Line) + Column));
		}
		printf("\n");
	}
	for (Column = 0; Column < size; Column++)
	{
		free(matrix[Column]);
	}free(matrix); free(array);
	return 0;
}