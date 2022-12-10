#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define PATH "X:\\4 курс\\сист программ\\процессы\\Debug\\Project2.exe"

double mas[10];

int main()
{
	system("chcp 1251>nul");
	FILE* file = fopen("data.txt", "w");
	writeData(file);
	int n = readData(file);
	char* str = calloc(100, sizeof(char));
	str = stroka(n);
	LPSTR str1 = str;
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	si.cb = sizeof(si);
	if(!CreateProcessA(PATH,
		str1,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi)
		)
	{
		printf("Ошибка %d", GetLastError());
		return;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);
	DWORD d;
	GetExitCodeProcess(pi.hProcess, &d);

	return 0;
}

int writeData(FILE* file)
{
	fprintf(file, "0 -2 -3");
	//fprintf(file, "1 12 36");
	fclose(file);
}

int readData(FILE* file)
{
	file = fopen("data.txt", "r");
	char str[10];
	int n = 0;
	while (fscanf(file, "%s", str) != EOF)
	{
		mas[n] = atof(str);
		printf("%f ", mas[n]);
		n++;
	}
	fclose(file);
	return n;
}
int stroka(int n)
{
	char* str = calloc(100, sizeof(char));
	char* s = calloc(100, sizeof(char));
	for (int i = 0; i < n; i++)
	{
		sprintf(s, "%f ", mas[i]);
		strcat(str, s);
	}
	return str;
}

