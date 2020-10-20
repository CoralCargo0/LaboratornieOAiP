#include <stdio.h>
#include<locale.h>
#define n 5

int main()
{
	setlocale(LC_ALL, "Russian");//Русификация вывода
	int i, k, supermas[n][n], ms[2*n],error;
	printf_s("Введите числa \n");
	for (i = 0; i < n; i++) // Ввод массива
	{
		do{
		error = scanf_s("%d", &ms[i]);  //Проверка ввода 
		if (error == 0)
		{
			printf("Ошибка, пожалуйста введите число\n");
			rewind(stdin);
		}
		  } while (error == 0);
	}for (i = 0; i < n; i++)      
	{
		ms[i + n] = ms[i];
	}
	printf("Матрица заданного вида:\n");
	for (k= 0; k < n; k++) //Процесс создания искомой матрицы
	{
		for (i = 0; i < n; i++)
		{
			supermas[k][i] = ms[i + k];
			printf("%d ", supermas[k][i]);
		}
		printf("\n");
	}
}
