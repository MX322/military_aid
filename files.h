#pragma once
#include "functions.h"

void WritingToLog(char func[50]); // прототип функции записи логов

void StoreToFile(armament company[], int& SIZE) // запись массива в файл
{
	char log[30] = "StoreToFile function used\n";

	char FileName[80] = "E:\\VStudio\\VS_projects\\CursWork\\file.bin";
	FILE* file = fopen(FileName, "wb");

	fwrite(&SIZE, sizeof(int), 1, file);
	fwrite(company, sizeof(armament), SIZE, file);

	fclose(file);

	WritingToLog(log);
}


void RestoreFromFile(armament company[], int& SIZE) // передача массива с файла
{
	char log[50] = "RestoreFromFile function used\n";

	char FileName[80] = "E:\\VStudio\\VS_projects\\CursWork\\file.bin";
	FILE* file = fopen(FileName, "rb");
	
	int n = 0;
	fread(&n, sizeof(int), n, file);

	armament* newAr = new armament[n];
	fread(newAr, sizeof(armament), n, file);
	fclose(file);

	armament* oldAr = company;
	company = newAr;
	delete[] oldAr;

	SIZE = n;

	//cout << "Array restored from file: " << FileName << endl;

	WritingToLog(log);
}


void WritingToLog(char func[50]) // Логи
{
	char FileName[80] = "E:\\VStudio\\VS_projects\\CursWork\\log.txt";
	FILE* log = fopen(FileName, "a");

	fputs(func, log);

	fclose(log);
}