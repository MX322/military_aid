#pragma once
using namespace std;

void WritingToLog(char func[50]); // прототип функции записи логов

struct armament // структура
{
	// экипировка
	int count_of_body_armor; // количество бронежилетов
	int count_of_helmets; // количество касок
	int count_of_thermal_imagers; // количество тепловизоров
	int count_of_aid; // количество аптечек

	// танки
	char type_of_tank[50]; // тип танка
	char name_of_tank[30]; // название танка
	int count_of_tanks; // количество танков
	float caliber_of_tanks; // калибр орудия 

	// атрилерия
	char type_of_artillery[50]; // тип артиллерии
	char name_of_artillery[30]; // название артиллерии
	int count_of_artillery; // количество артиллерии
	float caliber_of_artillery; // калибр орудия 

};


void ShowMenu(armament company[], int& SIZE); // прототип функции отображения меню


void ShowCompany(armament company[], int SIZE) // вывод массива
{

	char log[50] = "ShowCompany function used\n";

	for (int i = 0; i < SIZE; i++)
	{
		cout << "company " << i + 1 << endl;

		cout << "\nequipment: " << endl;
		cout << "Count of body armor: " << company[i].count_of_body_armor << endl;
		cout << "Count of helmets: " << company[i].count_of_helmets << endl;
		cout << "Count of thermal imagers: " << company[i].count_of_thermal_imagers << endl;
		cout << "Count of aid: " << company[i].count_of_aid << endl;


		cout << "\ntanks: " << endl;
		cout << "Type of tank: " << company[i].type_of_tank << endl;
		cout << "Name of tank: " << company[i].name_of_tank << endl;
		cout << "Count of tanks: " << company[i].count_of_tanks << endl;
		cout << "Caliber of tanks: " << company[i].caliber_of_tanks << endl;

		cout << "\nartillery: " << endl;
		cout << "Type of artillery: " << company[i].type_of_artillery << endl;
		cout << "Name of artillery: " << company[i].name_of_artillery << endl;
		cout << "Count of artillery: " << company[i].count_of_artillery << endl;
		cout << "Caliber of artillery: " << company[i].caliber_of_artillery << endl;

		cout << "\n==========================================\n";
	}

	WritingToLog(log);

	system("pause");
	system("cls");

	ShowMenu(company, SIZE);
}


void ShowTypeCompany(armament company[], int SIZE) // вывод массива по типу вооружению
{
	char log[50] = "ShowTypeCompany function used\n";

	char type[15];
	cout << "Enter type of company that you want to show (equipment / tanks / artillery): ";
	cin >> type;

	cout << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "company " << i + 1 << endl;

		if (strcmp(type, "equipment") == 0)
		{
			cout << "\nequipment: " << endl;
			cout << "Count of body armor: " << company[i].count_of_body_armor << endl;
			cout << "Count of helmets: " << company[i].count_of_helmets << endl;
			cout << "Count of thermal imagers: " << company[i].count_of_thermal_imagers << endl;
			cout << "Count of aid: " << company[i].count_of_aid << endl;
		}
	
		else if (strcmp(type, "tanks") == 0)
		{
			cout << "\ntanks: " << endl;
			cout << "Type of tank: " << company[i].type_of_tank << endl;
			cout << "Name of tank: " << company[i].name_of_tank << endl;
			cout << "Count of tanks: " << company[i].count_of_tanks << endl;
			cout << "Caliber of tanks: " << company[i].caliber_of_tanks << endl;
		}

		else if (strcmp(type, "artillery") == 0)
		{
			cout << "\nartillery: " << endl;
			cout << "Type of artillery: " << company[i].type_of_artillery << endl;
			cout << "Name of artillery: " << company[i].name_of_artillery << endl;
			cout << "Count of artillery: " << company[i].count_of_artillery << endl;
			cout << "Caliber of artillery: " << company[i].caliber_of_artillery << endl;
		}

		

		cout << "\n==========================================\n";
	}
	WritingToLog(log);

	system("pause");
	system("cls");

	ShowMenu(company, SIZE);
}


void ShowNumCompany(armament company[], int SIZE) // вывод массива по номеру роты
{
	char log[50] = "ShowNumCompany function used\n";

	int element;
	cout << "Enter num of company that you want to show: ";
	cin >> element;

	cout << "company " << element << endl;

	cout << "\nequipment: " << endl;
	cout << "Count of body armor: " << company[element - 1].count_of_body_armor << endl;
	cout << "Count of helmets: " << company[element - 1].count_of_helmets << endl;
	cout << "Count of thermal imagers: " << company[element - 1].count_of_thermal_imagers << endl;
	cout << "Count of aid: " << company[element - 1].count_of_aid << endl;


	cout << "\ntanks: " << endl;
	cout << "Type of tank: " << company[element - 1].type_of_tank << endl;
	cout << "Name of tank: " << company[element - 1].name_of_tank << endl;
	cout << "Count of tanks: " << company[element - 1].count_of_tanks << endl;
	cout << "Caliber of tanks: " << company[element - 1].caliber_of_tanks << endl;

	cout << "\nartillery: " << endl;
	cout << "Type of artillery: " << company[element - 1].type_of_artillery << endl;
	cout << "Name of artillery: " << company[element - 1].name_of_artillery << endl;
	cout << "Count of artillery: " << company[element - 1].count_of_artillery << endl;
	cout << "Caliber of artillery: " << company[element - 1].caliber_of_artillery << endl;

	WritingToLog(log);

	system("pause");
	system("cls");

	ShowMenu(company, SIZE);
}


void AddElement(armament*& company, int& SIZE) // добавление элемента массива
{
	char log[50] = "AddElement function used\n";

	SIZE++;

	armament* newArr = new armament[SIZE]; // выделение памяти
	for (int i = 0; i < SIZE; i++)
	{

		if (i == SIZE - 1)
		{
			// экипировка
			int count_of_body_armor; // количество бронежилетов
			cout << "Enter count of body armor: ";
			cin >> count_of_body_armor;

			int count_of_helmets; // количество касок
			cout << "Enter count of helmets: ";
			cin >> count_of_helmets;

			int count_of_thermal_imagers; // количество тепловизоров
			cout << "Enter count of thermal imagers: ";
			cin >> count_of_thermal_imagers;

			int count_of_aid; // количество аптечек
			cout << "Enter count of aid: ";
			cin >> count_of_aid;

			// танки
			char type_of_tank[50]; // тип танка
			cout << "Enter type of tank: ";
			cin >> type_of_tank;

			char name_of_tank[30]; // название танка
			cout << "Enter name of tank: ";
			cin >> name_of_tank;

			int count_of_tanks; // количество танков
			cout << "Enter count of tanks: ";
			cin >> count_of_tanks;

			float caliber_of_tanks; // калибр орудия 
			cout << "Enter caliber of tanks: ";
			cin >> caliber_of_tanks;

			// атрилерия
			char type_of_artillery[50]; // название артиллерии
			cout << "Enter type of artillery: ";
			cin >> type_of_artillery;

			char name_of_artillery[30]; // тип артиллерии
			cout << "Enter name of artillery: ";
			cin >> name_of_artillery;

			int count_of_artillery; // количество артиллерии
			cout << "Enter count of artillery: ";
			cin >> count_of_artillery;

			float caliber_of_artillery; // калибр орудия 
			cout << "Enter caliber of artillery: ";
			cin >> caliber_of_artillery;


			// экипировка
			newArr[i].count_of_body_armor = count_of_body_armor;
			newArr[i].count_of_helmets = count_of_helmets;
			newArr[i].count_of_thermal_imagers = count_of_thermal_imagers;
			newArr[i].count_of_aid = count_of_aid;

			// танки
			strcpy(newArr[i].type_of_tank, type_of_tank);
			strcpy(newArr[i].name_of_tank, name_of_tank);
			newArr[i].count_of_tanks = count_of_tanks;
			newArr[i].caliber_of_tanks = caliber_of_tanks;

			// атрилерия
			strcpy(newArr[i].type_of_artillery, type_of_artillery);
			strcpy(newArr[i].name_of_artillery, name_of_artillery);
			newArr[i].count_of_artillery = count_of_artillery;
			newArr[i].caliber_of_artillery = caliber_of_artillery;
		}

		else
		{
			newArr[i] = company[i];
		}
	}





	delete[] company; // очистка старого массива

	company = newArr; // перенос данных
	
	WritingToLog(log);

	system("pause");
	system("cls");

	ShowMenu(company, SIZE);
}


void RemoveElement(armament company[], int& SIZE) // удаление элемента массива
{
	char log[50] = "RemoveElement function used\n";

	int element;
	cout << "Enter num of company that you want to remove: ";
	cin >> element;

	for (int i = element - 1; i < SIZE; i++)
	{
		company[i] = company[i + 1];
	}

	SIZE--;
	WritingToLog(log);

	system("pause");
	system("cls");

	ShowMenu(company, SIZE);
}


void MergeSort(int arr[], int start, int end) // сортировка слиянием
{
	if (end - start < 2)
	{
		return;
	}

	if (end - start == 2)
	{
		if (arr[start] > arr[start + 1])
		{
			int tmp = arr[start];
			arr[start] = arr[start + 1];
			arr[start + 1] = tmp;
			return;
		}
	}

	MergeSort(arr, start, start + (end - start) / 2);
	MergeSort(arr, start + (end - start) / 2, end);

	int b[10];
	int b1 = start;
	int el = start + (end - start) / 2;
	int b2 = el;

	int j = 0;

	while (j < end - start)
	{
		if (b1 >= el || (b2 < end && arr[b2] <= arr[b1]))
		{
			b[j] = arr[b2];
			j++;
			b2++;
		}

		else
		{
			b[j] = arr[b1];
			j++;
			b1++;
		}
	}

	for (int i = start; i < end; i++)
	{
		arr[i] = b[i - start];
	}

}


void SortCompanyEquipment(armament company[], int SIZE) // сортировка по экипировке 
{
	char log[50] = "SortCompanyEquipment function used\n";

	int element;
	cout << "Enter num of company for sort: ";
	cin >> element;

	int arrEquipment[4] = { company[element - 1].count_of_body_armor, company[element - 1].count_of_helmets, company[element - 1].count_of_thermal_imagers, company[element - 1].count_of_aid }; // массив экипировок

	MergeSort(arrEquipment, 0, 4); // запуск сортировки

	for (int i = 0; i < 4; i++) // вывод результата
	{
		if (arrEquipment[i] == company[element - 1].count_of_body_armor)
		{
			cout << "Count of body armor: " << company[element - 1].count_of_body_armor << endl;
		}

		else if (arrEquipment[i] == company[element - 1].count_of_helmets)
		{
			cout << "Count of helmets: " << company[element - 1].count_of_helmets << endl;
		}

		else if (arrEquipment[i] == company[element - 1].count_of_thermal_imagers)
		{
			cout << "Count of thermal imagers: " << company[element - 1].count_of_thermal_imagers << endl;
		}

		else if (arrEquipment[i] == company[element - 1].count_of_aid)
		{
			cout << "Count of aid: " << company[element - 1].count_of_aid << endl;
		}
	}

	WritingToLog(log);

	system("pause");
	system("cls");

	ShowMenu(company, SIZE);
}


void SortCompanyHeavyArmament(armament company[], int SIZE) // сортировка по тяжелому вооружению 
{
	char log[50] = "SortCompanyHeavyArmament function used\n";

	int element;
	cout << "Enter num of company for sort: ";
	cin >> element;

	int arrHeavyArmament[2] = { company[element - 1].count_of_tanks, company[element - 1].count_of_artillery }; // массив тяжелого вооружения

	MergeSort(arrHeavyArmament, 0, 2); // запуск сортировки

	for (int i = 0; i < 2; i++) // вывод результата
	{
		if (arrHeavyArmament[i] == company[element - 1].count_of_tanks)
		{
			cout << "Count of tanks: " << company[element - 1].count_of_tanks << endl;
		}

		else if (arrHeavyArmament[i] == company[element - 1].count_of_artillery)
		{
			cout << "Count of artillery: " << company[element - 1].count_of_artillery << endl;
		}
	}
	WritingToLog(log);

	system("pause");
	system("cls");

	ShowMenu(company, SIZE);
}