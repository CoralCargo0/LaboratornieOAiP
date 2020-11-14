#include <stdio.h>
#include<locale.h>
#include<stdlib.h>

int main()
{
	setlocale(LC_ALL, "Russian");    //Русификация вывода
	int size, column, i, num = 0, row, ** matrix, amount, error;
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
	if (!(matrix = (int**)calloc(size, sizeof(int*))))            //Выделение и проверка памяти для матрицы
	{
		return 0;
	}
	for (column = 0; column < size; column++)
	{
		if (!(matrix[column] = (int*)calloc(size, sizeof(int))))
		{
			free(matrix);
			return 0;
		}
	}
	row = 0; column = 0;
	if (size % 2 == 1)amount = size / 2 + 1;                    //Рассчет количества витков
	else amount = size / 2;
	for (i = 0; i < amount; i++)
	{
		while (column + 2 * i < size)                            //Размещение элементов по строкам вправо
		{
			do
			{
				error=scanf_s("%d", &*(*(matrix + row + i) + column + i));
				if (error == 0)
				{
					printf("Ошибка, пожалуйста введите число\n");
					rewind(stdin);
				}
			} while (error == 0);
			num++; column++;
		}column--; row++;
		while (row + 2 * i < size)                              //Размещение элементов по столбцам вниз
		{
			do
			{
				error = scanf_s("%d", &*(*(matrix + row + i) + column + i));
				if (error == 0)
				{
					printf("Ошибка, пожалуйста введите число\n");
					rewind(stdin);
				}
			} while (error == 0);
			num++; row++;
		}row--; column--;
		while (column > -1)                                    //Размещение элементов по строкам влево
		{
			do
			{
				error = scanf_s("%d", &*(*(matrix + row + i) + column + i));
				if (error == 0)
				{
					printf("Ошибка, пожалуйста введите число\n");
					rewind(stdin);
				}
			} while (error == 0);
			num++; column--;
		}column++; row--;
		while (row > 0)                                       //Размещение элементов по столбцам вверх
		{
			do
			{
				error = scanf_s("%d", &*(*(matrix + row + i) + column + i));
				if (error == 0)
				{
					printf("Ошибка, пожалуйста введите число\n");
					rewind(stdin);
				}
			} while (error == 0);
			num++; row--;
		}
	}
	for (row = 0; row < size; row++)                        //Вывод матрицы 
	{
		for (column = 0; column < size; column++)
		{
			printf("%3d ", *(*(matrix + row) + column));
		}
		printf("\n");
	}
	for (column = 0; column < size; column++)              //Чистка памяти
	{
		free(matrix[column]);
	}
	free(matrix);
	return 0;
}
