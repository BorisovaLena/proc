#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <math.h>

float resh(float a, float b, float c);

int main(int arg, char* argv[])
{
	system("chcp 1251>nul");
	float mas[10];
	printf("%d",arg);
	for (int i = 0; i < arg; i++)
	{
		mas[i] = atof(argv[i]);
	}
	if (arg < 3)
	{
		FILE* rez = fopen("rez.txt", "w");
		fprintf(rez, "������� ������ 3 �����!!!");
		fclose(rez);
		printf("������� ������ 3 �����!!!");
	}
	else if (arg > 3)
	{
		FILE* rez = fopen("rez.txt", "w");
		fprintf(rez, "������� ������ 3 �����!!!");
		fclose(rez);
		printf("������� ������ 3 �����!!!");
	}
	else
	{
		float a = mas[0];
		float b = mas[1];
		float c = mas[2];
		if (a == 0)
		{
			FILE* rez = fopen("rez.txt", "w");
			fprintf(rez, "���������� a �� ����� ���� ����� ����!!!");
			fclose(rez);
			printf("���������� a �� ����� ���� ����� ����!!!");
		}
		else
		{
			resh(a, b, c);
			printf("������ �� ���������! ��� �����!");
		}
	}
	return 10;
}

float diskr(float a, float b, float c)
{
	return b * b - 4 * a * c;
}

float resh(float a, float b, float c)
{
	FILE* rez = fopen("rez.txt", "w");
	if (diskr(a, b, c) < 0)
	{
		fprintf(rez, "�������������� ������ ���");
		fclose(rez);
	}
	else if (diskr(a, b, c) == 0)
	{
		float x = (-b) / (2 * a);
		fprintf(rez, "D = %f. x = %f", diskr(a, b, c), x);
		fclose(rez);
	}
	else
	{
		float x1 = (-b + sqrt(diskr(a, b, c))) / (2*a);
		float x2 = (-b - sqrt(diskr(a, b, c))) / (2*a);
		fprintf(rez, "D = %-5.2f. x1 = %-5.2f, x2 = %-5.2f", diskr(a, b, c), x1, x2);
		fclose(rez);
	}
}

