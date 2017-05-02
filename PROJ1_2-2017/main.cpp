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
void linhasHome();
void escreveFileLinhas();


//////////////////////////////////



void homeMenu()
{
	//Variable used for reading the user input
	char option;
	//Variable used for controlling the while loop
	bool isRunning = true;

	
		//Clears the screen
		system("cls");       
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
		cin >> option;
		do
		{
			if (!cin.fail())
			{
				switch (option)
				{
				case '1':

					system("cls");
					
					//func
					isRunning = false;
					//TO DO CODE 
					break;
				case '2':
					system("cls");
					linhasHome();
					isRunning = false;
					//TO DO CODE
					break;
				case '3':
					isRunning = false;
					//TO DO CODE
					break;
				case '4':
					isRunning = false;
					//TO DO CODE
					break;
					//...
				case '0':
					//Exits the system

					return;
				default:
					cin.clear();
					cin.ignore(1000 , '\n');
					cout << "Input invalido!---> ";
					cin >> option;
					break;
				}
			}
			else
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Input invalido!---> ";
				cin >> option;
			}
		} while (isRunning);
}

//////////////////////////////// LINHAS ////////////////////////////////////////////////
Company object("SEMPRARROLAR", "condutores.txt", "linhas.txt");
vector <Line> vectLines = object.getLines();

void escreveFileLinhas()
{
	ofstream adiciona("linhas.txt"); // apartir daqui é um processo de escrita no ficheiro de texto 
	for (unsigned int i = 0; i < vectLines.size(); i++)
	{
		adiciona << vectLines[i].getId() << " ; ";
		adiciona << vectLines[i].getFreq() << " ; ";
		for (unsigned int u = 0; u < vectLines[i].getBusStops().size(); u++)
		{
			if (u == (vectLines[i].getBusStops().size() - 1))
			{
				adiciona << vectLines[i].getBusStops()[u] << "; ";
			}
			else adiciona << vectLines[i].getBusStops()[u] << ", ";
		}

		for (unsigned int u = 0; u < vectLines[i].getTimings().size(); u++)
		{
			if (u == (vectLines[i].getTimings().size() - 1))
			{
				adiciona << vectLines[i].getTimings()[u];
			}
			else adiciona << vectLines[i].getTimings()[u] << ", ";

		}
		adiciona << endl;
	}
	adiciona.close();
}

void coutLines()
{
	for (unsigned int i = 0; i < vectLines.size(); i++)
	{
		cout << "ID : " << vectLines[i].getId() << endl;
		cout <<"FREQ :" <<vectLines[i].getFreq() << endl;
		cout << "PARAGENS: " << endl;
		for (unsigned int u = 0; u < vectLines[i].getBusStops().size(); u++)
		{
			if (u == vectLines[i].getBusStops().size() - 1)
				cout << vectLines[i].getBusStops()[u] << endl;
			else cout << vectLines[i].getBusStops()[u] << " - ";
		}
		cout << "TEMPOS :" << endl;
		for (unsigned int u = 0; u < vectLines[i].getTimings().size(); u++)
		{
			cout << vectLines[i].getTimings()[u] << " min  ";
		}
		cout << endl << endl;



	}



}

void linhasHome() {     //correspondente a opcao 1 do menu

	

	cout << "ID's das linhas disponiveis : " << endl;
	// utilização do vector do tipo da  sruct LINHA para juntar todas as "linhas" do ficheiro correspondente
	
	coutLines();





	int o;   // utilizado para guardar a opcao. ( 1 ou 2 )
	cout << "[1]Detalhes linha existente" << endl;
	cout << "[2]Criar nova linha" << endl;
	cout << "[0]Voltar ao menu inicial" << endl << endl;
	cout << "Escolha a opcao que pretende : ";
	cin >> o;
	while (o != 1 && o != 2 && o != 0) // ciclo utilizado para forçar o utilizador a escolher uma opcao valida 
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Opcao invalida , tente de novo : ";
		cin >> o;
	}
	switch (o)
	{
	case 1: 
		
		break;
	case 2: 
		break;
	case 0: system("cls"); homeMenu();

	}
}






















//////////////////////// informação //////////////////////


















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

	Company object("SEMPRARROLAR", drivers, lines);
	
	homeMenu();
	

	return 0;
}
