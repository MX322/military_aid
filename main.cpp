#define _CRT_SECURE_NO_WARNINGS // для использования не безопасных функций
#include <iostream>
#include "menu.h"
using namespace std;


int main()
{
	int SIZE = 3;

	armament* company = new armament[SIZE]; // создание динамического массива структур


	// заполнение массива -------------------------------------------

	// 1 рота ----------------------------------
	
	// экипировка
	company[0].count_of_body_armor = 200;
	company[0].count_of_helmets = 250;
	company[0].count_of_thermal_imagers = 250;
	company[0].count_of_aid = 400;

	// танки
	strcpy_s(company[0].type_of_tank, "Medium tank");
	strcpy_s(company[0].name_of_tank, "M 60 modernized");
	company[0].count_of_tanks = 60;
	company[0].caliber_of_tanks = 45;

	// атрилерия
	strcpy_s(company[0].type_of_artillery, "Rocket artillery");
	strcpy_s(company[0].name_of_artillery, "M142 HIMARS");
	company[0].count_of_artillery = 40;
	company[0].caliber_of_artillery = 227;


	// 2 рота ----------------------------------

	// экипировка
	company[1].count_of_body_armor = 320;
	company[1].count_of_helmets = 360;
	company[1].count_of_thermal_imagers = 400;
	company[1].count_of_aid = 440;

	// танки
	strcpy_s(company[1].type_of_tank, "Light tank");
	strcpy_s(company[1].name_of_tank, "Griffin II");
	company[1].count_of_tanks = 90;
	company[1].caliber_of_tanks = 120;

	// атрилерия
	strcpy_s(company[1].type_of_artillery, "Rocket artillery");
	strcpy_s(company[1].name_of_artillery, "M142 HIMARS");
	company[1].count_of_artillery = 90;
	company[1].caliber_of_artillery = 227;


	// 3 рота ----------------------------------

	// экипировка
	company[2].count_of_body_armor = 150;
	company[2].count_of_helmets = 290;
	company[2].count_of_thermal_imagers = 200;
	company[2].count_of_aid = 330;

	// танки
	strcpy_s(company[2].type_of_tank, "Heavy tank");
	strcpy_s(company[2].name_of_tank, "Leopard II");
	company[2].count_of_tanks = 50;
	company[2].caliber_of_tanks = 120;

	// атрилерия
	strcpy_s(company[2].type_of_artillery, "Howitzer");
	strcpy_s(company[2].name_of_artillery, "M777");
	company[2].count_of_artillery = 70;
	company[2].caliber_of_artillery = 155;

	// --------------------------------------------------------------

	ShowMenu(company, SIZE); // запуск менюшки
}

