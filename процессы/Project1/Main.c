#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <math.h>
#define PATH "X:\\4 курс\\сист программ\\процессы\\процессы\\Debug\\Project2.exe"

double mas[3];

int main()
{
	system("chcp 1251>nul");
	FILE* file = fopen("data.txt", "w");
	writeData(file);
	readData(file);

	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	si.cb = sizeof(si);
	if (!CreateProcessA(PATH,
		NULL,
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

	//printf("Дочерний процесс завершился с кодом %d\n", d);
	return 0;
}

int writeData(FILE* file)
{
	fprintf(file, "1.20 -4.9 1");
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
		//printf("%f ", mas[n]);
		n++;
	}
	fclose(file);
}