#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <cctype>
#include <istream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include "Line.h"
#include "Shift.h"
#include "Driver.h"
#include "Company.h"
#include "Bus.h"
#include <windows.h>
#include <conio.h>
using namespace std;

//////////////////////////////////



int homeMenu()
{
	//Variable used for reading the user input
	char option;
	//Variable used for controlling the while loop
	bool isRunning = true;

	while (isRunning == true)
	{
		//Clears the screen
		system("cls");        //For UNIX-based OSes

							  //Clears the keyboard buffer
		fflush(stdin);
		//Outputs the options to console
		cout << "    MENU SEMPRARROLAR" << endl;
		puts("\n[1]Gestao condutores"
			"\n[2]Gestao linhas"
			"\n[3]Informacao"
			"\n[4]Option4"
			"\n.........."
			"\n[0]Exit");
		//Reads the user's option
		option = getchar();
		//Selects the course of action specified by the option
		switch (option)
		{
		case '1':
			//TO DO CODE
			break;
		case '2':
			//TO DO CODE
			break;
		case '3':
			//TO DO CODE
			break;
		case '4':
			//TO DO CODE
			break;
			//...
		case '0':
			//Exits the system
			isRunning = false;
			return 0;
		default:
			//User enters wrong input
			//TO DO CODE
			break;
		}
	}


}



int main() {
	
	
	string lines, drivers;
	ifstream LinesFile;
	ifstream DriversFile;
	cout << "Indique o ficheiro de Linhas :";
	getline(cin, lines);
	LinesFile.open(lines);
	if (LinesFile.fail())
	{
		cerr << "Erro a encontrar ficheiro!" << endl;
		exit(1);

	}
	LinesFile.close();

	cout << "Indique o ficheiro de condutores :";
	getline(cin, drivers);
	DriversFile.open(drivers);
	if (DriversFile.fail())
	{
		cerr << "Erro a encontrar ficheiro!" << endl;
		exit(1);

	}
	DriversFile.close();

	Empresa object("SEMPRARROLAR", drivers, lines);
	
	homeMenu();
	

	return 0;
}
