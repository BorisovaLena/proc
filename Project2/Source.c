#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <math.h>

int main(int n, float mas[])
{
	system("chcp 1251>nul");

	if (n < 3)
	{
		FILE* rez = fopen("rez.txt", "w");
		fprintf(rez, "введено меньше 3 чисел!!!");
		fclose(rez);
		printf("введено меньше 3 чисел!!!");
	}
	else if (n > 3)
	{
		FILE* rez = fopen("rez.txt", "w");
		fprintf(rez, "введено больше 3 чисел!!!");
		fclose(rez);
		printf("введено больше 3 чисел!!!");
	}
	else
	{
		float a = mas[0];
		float b = mas[1];
		float c = mas[2];
		if (a == 0)
		{
			FILE* rez = fopen("rez.txt", "w");
			fprintf(rez, "Коэффицент a не может быть равен нулю!!!");
			fclose(rez);
			printf("Коэффицент a не может быть равен нулю!!!");
		}
		else
		{
			resh(a, b, c);
			printf("Ничего не сломалось! Это успех!");
		}
	}
	return 10;
}
float resh(float a, float b, float c)
{
	FILE* rez = fopen("rez.txt", "w");
	if (diskr(a, b, c) < 0)
	{
		fprintf(rez, "Действительных корней нет");
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
		float x1 = (-b + sqrt(diskr(a, b, c))) / (2 * a);
		float x2 = (-b - sqrt(diskr(a, b, c))) / (2 * a);
		fprintf(rez, "D = %-5.2f. x1 = %-5.2f, x2 = %-5.2f", diskr(a, b, c), x1, x2);
		fclose(rez);
	}
}

float diskr(float a, float b, float c)
{
	return b * b - 4 * a * c;
}
