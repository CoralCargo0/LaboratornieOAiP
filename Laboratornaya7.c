#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	system("chcp 1251");
	system("cls");
	char* string;
	int strsize, i = 1 , error ;
	do                                               //Выделение памяти + ввод размера строки + проверка на правильность ввода и достаточность памяти
	{
		do
		{
		  rewind(stdin);
		  printf(" Задайте размер строки: ");
		  error = scanf_s("%d", &strsize);
		  strsize+=2;
	    } while (strsize < 1 || error == 0);
		string = (char*)calloc(strsize, sizeof(char));
		if (string==NULL)
		{
			printf(" Памяти недостаточно\n");
		}
	} while (string == NULL);
	printf(" Задайте строку: ");
	rewind(stdin);
	fgets(string, strsize, stdin);
	while (string[i] != '\n')
	{
		if (string[i] == '.' || string[i]== '?' || string[i]== '!' )
		{
			i++;
			if (string[i] == '\n')break ;
			if (string[i] == ' ')i += 2;
			else i++;
			continue;
			
		}
		if (string[i] == 'Ё')
		{
			*(string + i) = -72;
			i++;
			continue;
		}
		if (string[i]>='A' && string[i]<='Z' || string[i] >= 'А' && string[i] <= 'Я')
		{
			string[i] += 32;
			i++;
		}
		else i++;
	}
	printf(" Новая строка: %s\n", string);
	free(string);
	return 0;
}
