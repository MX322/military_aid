#pragma once
#include <conio.h> // библиотека для работы с визуалом менюшки
#include "windows.h" // библиотека для работы с визуалом менюшки
#include "files.h"
using namespace std;

/*
	Справка:
		1 <conio.h> и "windows.h" библиотеки для визуала менюшки
		2 HANDLE - структура которая хранитт в себе какие-то значения взятые с консоли, для работы с координатами и цветами интерфейса
		3 COORD - структура для принятия координат чего - то 
		4 SetConsoleCursorPosition - перестановка курсора к координатам
		5 SetConsoleTextAttribute - установка цвета текста
		6 _kbhit() - принимает нажатия клавиш клавиатуры
		7 system("cls"); - очистка консоли
*/



HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // хендлер для работы с визуалом менюшки

void ShowText(string TEXT) // отображение красивого(анимированного) текста
{
	COORD cText;
	cText.X = 20;
	cText.Y = 15;

	SetConsoleCursorPosition(h, cText); // перестановка курсора к координатам
	SetConsoleTextAttribute(h, 4); // установка цвета текста

	for (int i = 0; i < TEXT.length(); i++)
	{
		Sleep(25);
		cout << TEXT[i];
	}

	Sleep(1000);
	SetConsoleCursorPosition(h, cText);
	SetConsoleTextAttribute(h, 0);

	for (int i = 0; i < TEXT.length() + 1; i++)
	{
		Sleep(25);
		cout << " ";
	}

}

void ShowInterface(int beginX, int beginY) // интерфейс меню
{

	MoveWindow(GetConsoleWindow(), 220, 80, 1500, 900, true); // размер окна консоли

	
	COORD Interface; // создание координат интерфейса
	Interface.X = beginX + 6;
	Interface.Y = beginY - 2;
	SetConsoleTextAttribute(h, 6);
	SetConsoleCursorPosition(h, Interface);
	cout << "MENU";


	// отрисовка инвенторя -----------------------------------
	for (int i = 0; i < 10; i++)
	{
		// кнопки -----------------------------------
		Interface.Y = beginY + i;
		Interface.X = beginX;
		SetConsoleTextAttribute(h, 8);
		SetConsoleCursorPosition(h, Interface);
		cout << (char)254; // символ квадратика

		//-------------------------------------------

		// текст ------------------------------------
		Interface.X = beginX + 2;
		SetConsoleTextAttribute(h, 15);
		SetConsoleCursorPosition(h, Interface);

		if (i == 0)
		{
			cout << "Show Company";
		}

		else if (i == 1)
		{
			cout << "Add Element";
		}

		else if (i == 2)
		{
			cout << "Remove Element";
		}

		else if (i == 3)
		{
			cout << "Sort Company Heavy Armament";
		}

		else if (i == 4)
		{
			cout << "Sort Company Equipment";
		}

		else if (i == 5)
		{
			cout << "Show Type Company";
		}

		else if (i == 6)
		{
			cout << "Show Num Company"; 
		}

		else if (i == 7)
		{
			cout << "Store To File";
		}

		else if (i == 8)
		{
			cout << "Restore From File";
		}

		else if (i == 9)
		{
			SetConsoleTextAttribute(h, 12);
			cout << "Exit";
		}
		// -------------------------------------------

		
	}

}


void ControlMenu(int beginX, int beginY, armament company[], int& SIZE) // настройка работы менюшки
{
	// скрытие мигающего курсора
	CONSOLE_CURSOR_INFO flash;
	flash.bVisible = false; // спрятать курсор
	flash.dwSize = 1; // 1...100
	SetConsoleCursorInfo(h, &flash);

	//курсор---------------------------------------------
	COORD cursor;
	cursor.X = beginX;
	cursor.Y = beginY;

	SetConsoleCursorPosition(h, cursor); // первый квадратик будет красным
	SetConsoleTextAttribute(h, 4);
	cout << char(254);
	//---------------------------------------------------


	while (true) 
	{
		if (_kbhit()) // нажатие на клавиатуру
		{
			SetConsoleCursorPosition(h, cursor);
			SetConsoleTextAttribute(h, 8);
			cout << char(254);
			int code = _getch();


			if (code == 224)
			{
				code = _getch();
			}


			// up/down -------------------------------------------		
			if (code == 80 && cursor.Y + 1 != beginY + 10)
			{
				cursor.Y++;
			}

			else if (code == 72 && cursor.Y - 1 != beginY - 1)
			{
				cursor.Y--;
			}
			// ---------------------------------------------------

			// работа с кнопками -------------------------------------------------
			else if (code == 13 && cursor.Y == beginY) // ShowCompany
			{
				system("cls"); // очистка консоли
				cursor.X = 0;
				cursor.Y = 0;
				SetConsoleTextAttribute(h, 7);

				ShowCompany(company, SIZE);
			}

			// -------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 1) // AddElement
			{
				system("cls");
				cursor.X = 0;
				cursor.Y = 0;
				SetConsoleTextAttribute(h, 7);

				AddElement(company, SIZE);
			}

			// -------------------------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 2) // RemoveElement
			{
				system("cls");
				cursor.X = 0;
				cursor.Y = 0;
				SetConsoleTextAttribute(h, 7);

				RemoveElement(company, SIZE);
			}

			// -------------------------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 3) // SortCompanyHeavyArmament
			{
				system("cls");
				cursor.X = 0;
				cursor.Y = 0;
				SetConsoleTextAttribute(h, 7);

				SortCompanyHeavyArmament(company, SIZE);
			}

			// -------------------------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 4) // SortCompanyEquipment
			{
				system("cls");
				cursor.X = 0;
				cursor.Y = 0;
				SetConsoleTextAttribute(h, 7);

				SortCompanyEquipment(company, SIZE);
			}

			// -------------------------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 5) // ShowTypeCompany
			{
				system("cls");
				cursor.X = 0;
				cursor.Y = 0;
				SetConsoleTextAttribute(h, 7);

				ShowTypeCompany(company, SIZE);
			}

			// -------------------------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 6) // ShowNumCompany
			{
				system("cls");
				cursor.X = 0;
				cursor.Y = 0;
				SetConsoleTextAttribute(h, 7);

				ShowNumCompany(company, SIZE);
			}

			// -------------------------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 7) // StoreToFile
			{
				StoreToFile(company, SIZE);

				string TEXT = "The company has been stored to file";
				ShowText(TEXT);
			}

			// -------------------------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 8) // RestoreFromFile
			{
				RestoreFromFile(company, SIZE);

				string TEXT = "The company has been restored from file";
				ShowText(TEXT);
			}

			// -------------------------------------------------------------------


			// EXIT --------------------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 9)
			{
				int choice = MessageBoxA(0, "\tAre you sure want to exit?", "The Earth is flat", MB_YESNO);

				if (choice == IDYES)
				{
					system("cls");
					exit(0);
				}
			}

			// -------------------------------------------------------------------

			// красный курсор
			SetConsoleCursorPosition(h, cursor);
			SetConsoleTextAttribute(h, 4);
			cout << char(254);
		}
	}
	// -------------------------------------------------------

	return;
}


void ShowMenu(armament company[], int& SIZE) // отображение меню
{
	int beginY = 4;
	int beginX = 25;

	ShowInterface(beginX, beginY);
	ControlMenu(beginX, beginY, company, SIZE);
}