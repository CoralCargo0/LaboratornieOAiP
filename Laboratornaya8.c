//Дан массив строк.
//На месте исходного массива создать новый массив, такой, 
//чтобы в конце была расположена четвертая часть первых по алфавиту строк.
//Последовательность расположения остальных строк в массиве сохранить.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
	system("chcp 1251");
	system("cls");
	char** str;
	char* min_str;
	int i, j, u, max_rows, max_symb;
	printf("Введите количество строк\n");
	scanf_s(" %d", &max_rows);
	printf("Введите количество символов в строке\n");
	scanf_s(" %d", &max_symb);
	str = (char**)calloc(max_rows + 1, sizeof(char*));
	for (i = 0; i < max_rows; i++)
		str[i] = (char*)calloc(max_symb + 1, sizeof(char));
	
	printf("Введите %3d строк длинной не более %3d символов\n", max_rows, max_symb);
	for (i = 0; i < max_rows; i++)
	{
		rewind(stdin);
		fgets(str[i], max_symb, stdin);
	}
	for (int z = 0; z < max_rows / 4; z++)
	{
		min_str = str[0];
		u = 0;
		for (i = 1; i < max_rows - z; i++)
		{
			for (j = 0; str[i][j] != '\0' && min_str[j] != '\0' && str[i][j] == min_str[j]; j++);
			if (str[i][j] - min_str[j] < 0)
			{
				min_str = str[i];
				u = i;
			}
		}
		for (++u; u < max_rows; u++)
		{
			str[u - 1] = str[u];

		}u--;

		str[u] = min_str;
	}
	printf("Новый массив :\n");
	for (i = 0; i < max_rows; i++)
	{
		printf("%s", str[i]);


	}
	for (i = 0; i < max_rows; i++)
	{
		free(str[i]);
	}
	free(str);
}