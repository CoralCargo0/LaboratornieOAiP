#include <stdio.h>
#include<locale.h>
#define n 5

int main()
{
	setlocale(LC_ALL, "Russian");//����������� ������
	int i, d, k, supermas[n][n], ms[2*n],error;
	printf_s("������� ����a \n");
	for (i = 0; i < n; i++) // ���� �������
	{
		do{
		error = scanf_s("%d", &ms[i]);  //�������� ����� 
		if (error == 0)
		{
			printf("������, ���������� ������� �����\n");
			rewind(stdin);
		}
		  } while (error == 0);
	}for (d = 0; d < n; d++)      
	{
		ms[d + n] = ms[d];
	}
	printf("������� ��������� ����:\n");
	for (k= 0; k < n; k++) //������� �������� ������� �������
	{
		for (i = 0; i < n; i++)
		{
			supermas[k][i] = ms[i + k];
			printf("%d ", supermas[k][i]);
		}
		printf("\n");
	}
}