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
void linhasHome(Company &company);
void escreveFileLinhas(Company &company);
void coutLines(Company &company);
void condutoresHome(Company &company);
void coutCondutores(Company &company);
void rem_condutor(Company &company);
void reescreverDriversFile(Company &company);
void infoHome(Company &company);
void horarioLinha(Company &company);
vector<int> linhasMesmaParagem(string s, Company &company);
void linhasComParagem(Company &company);
void condutoresOptions(int id, Company &company);
void alterarHorasTurno(int id, Company &company);
void chooseDriver(Company &company);
void alterarHorasSemana(int id, Company &company);
void alterarTempoDescanso(int id, Company &company);
void adicionarCondutor(Company &company);
int tempoIdaVolta(Line linha);
void autocarrosDisplay(Company &company);
int numeroAutocarrosLinha(int Tempo, Line linha);
string Maximiza(string s);
void HorarioParagem(Company &company);
void percursoDuasParagens(Company &company);
//////////////////////////////////

//////////////////////////////////
void homeMenu(Company &company)
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
		"\n[4]Autocarros"
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
				condutoresHome(company);
				//func
				isRunning = false;
				//TO DO CODE 
				break;
			case '2':
				system("cls");
				linhasHome(company);
				isRunning = false;
				//TO DO CODE
				break;
			case '3':system("cls");
				infoHome(company);
				isRunning = false;
				//TO DO CODE
				break;
			case '4': system("cls");
				 autocarrosDisplay(company);
				isRunning = false;
				//TO DO CODE
				break;
				//...
			case '0':
				//Exits the system

				return;
			default:
				cin.clear();
				cin.ignore(1000, '\n');
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




void coutLines(Company &company)
{
	vector <Line> vectLines = company.getLines();
	for (unsigned int i = 0; i < vectLines.size(); i++)
	{
		cout << "ID : " << vectLines[i].getId() << endl;
		cout << "FREQ :" << vectLines[i].getFreq() << endl;
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

void linhasHome(Company &company) {     //correspondente a opcao 1 do menu



	cout << "ID's das linhas disponiveis : " << endl;
	// utilização do vector do tipo da  sruct LINHA para juntar todas as "linhas" do ficheiro correspondente

	coutLines(company);

	int o;   // utilizado para guardar a opcao. ( 1 ou 2 )
	cout << "[1]Opcao" << endl;
	cout << "[2]opcao" << endl;
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
	case 0: system("cls"); homeMenu(company);

	}
}

void escreveFileLinhas(Company &company)
{
	vector<Line> vectLines = company.getLines();
	ofstream adiciona(company.getFichLinhas()); // apartir daqui é um processo de escrita no ficheiro de texto 
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









//////////////////////////// Condutores ////////////////////////////////////////////////////////

void coutCondutores(Company &company)
{
	vector <Driver> vectDriver = company.getDrivers();
	for (unsigned int i = 0; i < vectDriver.size(); i++)
	{
		cout << "ID : " << vectDriver[i].getId() << endl;
		cout << "Nome :" << vectDriver[i].getName() << endl;
		cout << "Duracao maxima do turno: " << vectDriver[i].getShiftMaxDuration() << endl;
		cout << "Numero maximo de horas por semana :" << vectDriver[i].getMaxWeekWorkingTime() << endl;
		cout << "Numero minimo de horas de descanso : " << vectDriver[i].getMinRestTime() << endl;
		cout << endl << endl;
	}
}
void condutoresHome(Company &company) {

	coutCondutores(company);
	int o;   // utilizado para guardar a opcao. ( 1 ou 2 )
	cout << "[1]Alterar um condutor" << endl;
	cout << "[2]Criar um novo condutor" << endl;
	cout << "[3]Remover um condutor\n";
	cout << "[4]Trabalho condutor" << endl;
	cout << "[0]Voltar ao menu inicial" << endl << endl;
	cout << "Escolha a opcao que pretende : ";
	cin >> o;
	while (o != 1 && o != 2 && o != 0 && o != 3 && o != 4) // ciclo utilizado para forçar o utilizador a escolher uma opcao valida 
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Opcao invalida , tente de novo : ";
		cin >> o;
	}
	switch (o)
	{
	case 1: chooseDriver(company);

		break;
	case 2: adicionarCondutor(company);
		break;
	case 3:
		rem_condutor(company);
		break;
	case 4: system("cls");
		
		break;
	case 0: system("cls"); homeMenu(company);

	}
}

int ver_idc(int &opc, vector<Driver> vector) {
	int i = 0;
	while (i < vector.size()) {
		if (opc == vector[i].getId()) {
			return i;
			break;
		}
		i++;
	}
	return -1;
}


void chooseDriver(Company &company) // funcao que pede ao utilizador o id do condutor que deseja ver , e por sua vez o conjunto de alteracoes que se podem fazer sobre o condutor invocando a funcao condutores options
{
	vector<Driver> vectorDrivers = company.getDrivers();
	int id;
	cout << "Digite o ID do condutor que pretende : ";
	cin >> id;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "ID invalido , tente outra vez :"; cin >> id;
	}
	bool idExiste = false;

	while (!idExiste)
	{
		for (unsigned int i = 0; i < vectorDrivers.size(); i++)
		{
			if (id == vectorDrivers[i].getId())
				idExiste = true;
		}
		if (idExiste)
		{
			system("CLS");
			condutoresOptions(id , company);
		}
		else
		{
			cout << "O id escolhido nao esta disponivel (tente de novo) : ";
			cin >> id;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "ID invalido , tente outra vez :"; cin >> id;
			}
		}
	}


}

void condutoresOptions(int id , Company &company) // funcao que mostra as opcoes disponiveis apos a escolha do condutor
{
	vector<Driver> vectorDrivers = company.getDrivers();
	int index;
	for (unsigned int i = 0; i < vectorDrivers.size(); i++)
	{
		if (vectorDrivers[i].getId() == id)
			index = i;
	}


	int opcao;
	cout << "[1]Para alterar as horas do turno" << endl;
	cout << "[2]Para alterar as horas de trabalho por semana" << endl;
	cout << "[3]Para alterar as horas de descanso entre turnos" << endl;
	cout << "[0]Para voltar atras" << endl;
	cout << "Digite a opcao que pretende : ";
	cin >> opcao;
	while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Opcao :";
		cin >> opcao;
	}

	switch (opcao) // para escolher a funcao correspondente a opcao do utilizador
	{
	case 0: system("cls"); condutoresHome(company);
		break;
	case 1: alterarHorasTurno(id , company);
		break;
	case 2: alterarHorasSemana(id, company);
		break;
	case 3: alterarTempoDescanso(id, company);
		break;
	}

}

void alterarHorasTurno(int id , Company &company) // funcao basicapara alterar as horas de turno do condutor
{
	vector<Driver> vectorDrivers = company.getDrivers();
	int index;
	int horas;
	for (unsigned int u = 0; u < vectorDrivers.size(); u++)
	{
		if (vectorDrivers[u].getId() == id)
			index = u;
	}
	cout << "Digite o novo numero de horas por turno : ";
	cin >> horas;
	vectorDrivers[index].setMaxHours(horas);
	company.setCondutores(vectorDrivers);
	cout << "A alteracao foi feita com sucesso !";
	reescreverDriversFile(company);

	cout << endl << endl << endl << endl;
	condutoresHome(company);

}

void alterarHorasSemana(int id , Company &company) // funcao basica para alterar as horas de trabalho por semana
{
	vector<Driver> vectorDrivers = company.getDrivers();
	int index;
	int horas;
	for (unsigned int u = 0; u < vectorDrivers.size(); u++)
	{
		if (vectorDrivers[u].getId() == id)
			index = u;
	}
	cout << "Digite o novo numero de horas de trabalho por semana : ";
	cin >> horas;
	vectorDrivers[index].setMaxWeekHours(horas);
	company.setCondutores(vectorDrivers);
	cout << "A alteracao foi feita com sucesso !";
	reescreverDriversFile(company);

	cout << endl << endl << endl << endl;
	condutoresHome(company);


}

void alterarTempoDescanso(int id , Company &company) // funcao basica para alterar o tempo de descanso do condutor
{
	vector<Driver> vectorDrivers = company.getDrivers();
	int index;
	int horas;
	for (unsigned int u = 0; u < vectorDrivers.size(); u++)
	{
		if (vectorDrivers[u].getId() == id)
			index = u;
	}
	cout << "Digite o novo numero minimo de horas de descanco : ";
	cin >> horas;
	vectorDrivers[index].setMinHours(horas);
	company.setCondutores(vectorDrivers);
	cout << "A alteracao foi feita com sucesso !";
	reescreverDriversFile(company);

	cout << endl << endl << endl << endl;
	condutoresHome(company);
}





void rem_condutor(Company &company) {
	vector<Driver> vectorDrivers = company.getDrivers();
	int opc;
	int i;
	cout << "\nQue condutor pretende remover (escreva o ID respetivo) : "; cin >> opc;
	while (true) {
		if (!cin.fail()) {
			i = ver_idc(opc, vectorDrivers);
			if (i == -1) {
				cout << "Id nao encontrado tente novamente : "; cin >> opc;
			}
			else {
				break;
			}
		}
		else {
			cout << "Tem que ser um inteiro, tenta novamente : ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> opc;
		}
	}
	vectorDrivers.erase(vectorDrivers.begin() + i);
	company.setCondutores(vectorDrivers);
	reescreverDriversFile(company);
	cout << "O condutor foi removido com sucesso!";
	cout << "\n\n\n\n";
	condutoresHome(company);
}

void reescreverDriversFile(Company &company) {


	ofstream ofFile(company.getFichDrivers());
	int i = 0;
	while (i < company.getDrivers().size()) {
		ofFile << company.getDrivers()[i].getId() << " ; " << company.getDrivers()[i].getName();

		ofFile << " ; " << company.getDrivers()[i].getShiftMaxDuration() << " ; " << company.getDrivers()[i].getMaxWeekWorkingTime() << " ; " << company.getDrivers()[i].getMinRestTime();
		if (i != company.getDrivers().size() - 1) {
			ofFile << endl;
		}
		i++;
	}
	ofFile.close();
}

void adicionarCondutor(Company &company)
{
	vector<Driver> vectorDrivers = company.getDrivers();
	int voltar;
	int id, hT, hS, tR;
	string nome;
	cout << "ID do novo condutor a adiconar : "; cin >> id;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "ID invalido! :"; cin >> id;
	}
	cout << "Horas por turno : "; cin >> hT;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Erro (tente novamente) :"; cin >> hT;
	}
	cout << "Horas de trabalho por semana : ";  cin >> hS;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Erro (tente novamente) :"; cin >> hS;
	}
	cout << "Horas de descanco : "; cin >> tR; 
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Erro (tente novamente) :"; cin >> tR;
	}
	cin.ignore(1000, '\n');
	cout << "Nome do condutor : "; getline(cin, nome);
	Driver object(id, nome, hT, hS, tR);
	vectorDrivers.push_back(object);
	company.setCondutores(vectorDrivers);
	reescreverDriversFile(company);

	
	cout << "O novo condutor foi agora adicionado!" << endl;
	cout << "Prima 0 para voltar para o menu : ";
	cin >> voltar;
	while (voltar != 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Prima 0 para voltar para o menu : ";
		cin >> voltar;
	}
	if (voltar == 0)
	{
		system("cls");
		homeMenu(company);
	}

}










//////////////////////// informação ////////////////////////////////////////////////////////////////////////////////////////////////////

void infoHome(Company &company)    // funcao que serve como base do menu informacao , e tem diversas opcoes a favor do utilizador
{
	int opcao;
	cout << "|  Informacao SEMPRARROLAR  |" << endl;
	cout << "[1]Horario de uma linha" << endl;
	cout << "[2]Horarios de uma paragem" << endl;
	cout << "[3]Quais as linhas que passam por determinada paragem" << endl;
	cout << "[4]Determinar percurso entre duas quaisquer paragens" << endl;
	cout << "[0]Voltar ao menu" << endl << endl;
	cout << "O horario da empresa semprarrolar funciona de segunda a sexta entre as 8h e as 23h." << endl;
	cout << "Para um melhor funcionamento do programa, os dias sao vistos como intervalos de minutos :" << endl;
	cout << "Segunda         Terca         Quarta         Quinta         Sexta" << endl;
	cout << "[480,1379]      [1920,2819]   [3360,4259]    [4800,5699]    [6240,7140]" << endl;
	cout << "Digite a opcao que deseja : ";
	cin >> opcao;
	while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 0)   // loop utilizado para 'obrigar' o utilizador a escolher uma opcao valida
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Opcao invalida , tente de novo :";
		cin >> opcao;
	}
	switch (opcao) // switch para chamar funcoes de acordo com a opcao escolhida..
	{
	case 1:  horarioLinha(company);
		break;
	case 2: HorarioParagem(company);
		break;
	case 3: linhasComParagem(company);
		break;
	case 4: system("cls");
		percursoDuasParagens(company);
		break;
	case 0: system("cls"); homeMenu(company);
		break;
	}



}

void horarioLinha(Company &company) // funcao que permite mostrar ao utilizador o horario da linha que ele escolheu 
{
	int id, valor;
	vector <Line> vectorLines = company.getLines();
	const int horaI = 8;
	int minutos = 0; // variaveis auxiliares
	int minutosaux = 0;
	int ajudahoras, ajudaminutos;
	int ajuda;
	cout << "Indique o id da linha : ";
	cin >> id;
	bool para = false;
	while (true) // para encontrar o indice da linha correspondente ao id escolhido
	{
		for (unsigned int i = 0; i < vectorLines.size(); i++)
		{
			if (vectorLines[i].getId() == id)
			{
				valor = i;
				para = true;
			}
		}
		if (para)
			break;
		cout << "A linha nao existe , tente outro id : ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> id;
	}

	system("cls");


	cout << "----------------------------------------------------" << endl;
	cout << "|                     " << id << "                          |" << endl;
	cout << "----------------------------------------------------" << endl;

	cout << "Sentido :" << endl;
	for (unsigned int i = 0; i < vectorLines[valor].getBusStops().size(); i++) // para escrever o nome das paragens;;
	{
		if (i == vectorLines[valor].getBusStops().size() - 1)
			cout << vectorLines[valor].getBusStops()[i];
		else cout << vectorLines[valor].getBusStops()[i] << "--->";
	}
	cout << endl << endl;
	 
	int horasaux = horaI;
	int horasaux2 = horaI;
	for (unsigned int i = 0; i < vectorLines[valor].getBusStops().size(); i++) // para escrever o nome das paragens;;
	{
		cout << i + 1 << " Paragem     ";
	}
	cout << endl;
	while (horasaux2 <= 22) // para todas as viagens antes das 23 horas , é mostrado em forma de tabela as horas a que passa em cada paragem 
	{
		for (unsigned int i = 0; i < vectorLines[valor].getBusStops().size(); i++)
		{
			if (horasaux == 24)
				horasaux = 0;
			if (i == 0)
				cout << setw(2) << setfill('0') << horasaux2 << ":" << setw(2) << setfill('0') << minutosaux << "         "; //formato das horas e minutos utilizando setw e setfill
			else if (i == vectorLines[valor].getBusStops().size() - 1)
				cout << setw(2) << setfill('0') << horasaux << ":" << setw(2) << setfill('0') << minutos;

			else  cout << setw(2) << setfill('0') << horasaux << ":" << setw(2) << setfill('0') << minutos << "         ";
			ajudahoras = horasaux;
			ajudaminutos = minutos;
			if (i < vectorLines[valor].getBusStops().size() - 1)
			{
				if (minutos + vectorLines[valor].getTimings()[i] >= 60) // quando passa dos 59 min acrescenta 1 hora as horas
				{
					horasaux += (minutos + vectorLines[valor].getTimings()[i]) / 60;
					minutos = (minutos + vectorLines[valor].getTimings()[i]) % 60;
				}
				else minutos += vectorLines[valor].getTimings()[i];
			}
		}
		cout << endl;
		minutosaux += vectorLines[valor].getFreq();

		if (minutosaux >= 60)
		{
			horasaux2 = horasaux2 + (minutosaux / 60);
			minutosaux = minutosaux % 60;
		}
		minutos = minutosaux;
		horasaux = horasaux2;

	}
	
	cout << endl << endl << endl;
	cout << "Sentido :" << endl;
	for (int i = vectorLines[valor].getBusStops().size() - 1; i >= 0; i--) // para escrever o nome das paragens;;
	{
		if (i == 0)
			cout << vectorLines[valor].getBusStops()[i] << endl << endl;
		else cout << vectorLines[valor].getBusStops()[i] << "--->";
	}

	horasaux2 = horaI;
	horasaux = horaI;
	for (unsigned int i = 0; i <= vectorLines[valor].getTimings().size() - 1; i++) {
		minutosaux += vectorLines[valor].getTimings()[i];
		minutos += vectorLines[valor].getTimings()[i];
		if (minutosaux >= 60) {
			horasaux += minutosaux / 60;
			horasaux2 += minutosaux / 60;
			minutosaux = minutosaux % 60;
			minutos = minutosaux % 60;
		}
	}
	for (int i = vectorLines[valor].getBusStops().size() - 1; i >= 0; i--) // para escrever o nome das paragens;;
	{
		cout << vectorLines[valor].getBusStops().size() - i << " Paragem       ";
	}
	cout << endl;
	
	while (true)
	{
		if ((horasaux >= ajudahoras && minutosaux > ajudaminutos)|| (horasaux>ajudahoras))
			break;
		for (int i = vectorLines[valor].getBusStops().size() - 1; i >= 0; i--)
		{
			if (horasaux == 24)
				horasaux = 0;
			if (i == vectorLines[valor].getBusStops().size() - 1)
				cout << setw(2) << setfill('0') << horasaux2 << ":" << setw(2) << setfill('0') << minutosaux << "           "; //formato das horas e minutos utilizando setw e setfill
			else if (i == 0)
				cout << setw(2) << setfill('0') << horasaux << ":" << setw(2) << setfill('0') << minutos;

			else  cout << setw(2) << setfill('0') << horasaux << ":" << setw(2) << setfill('0') << minutos << "           ";
			if (i > 0)
			{
				if (minutos + vectorLines[valor].getTimings()[i - 1] >= 60) // quando passa dos 59 min acrescenta 1 hora as horas
				{
					horasaux += (minutos + vectorLines[valor].getTimings()[i - 1]) / 60;
					minutos = (minutos + vectorLines[valor].getTimings()[i - 1]) % 60;
				}
				else minutos += vectorLines[valor].getTimings()[i - 1];
			}
		}
		cout << endl;
		minutosaux += vectorLines[valor].getFreq();

		if (minutosaux >= 60)
		{
			horasaux2 += minutosaux / 60;
			minutosaux = minutosaux % 60;
		}
		minutos = minutosaux;
		horasaux = horasaux2;

	}

	cout << endl << endl << endl << endl;

	infoHome(company);
}


vector<int> linhasMesmaParagem(string s, Company &company) // esta funcao tem como parametro uma string (nome da paragem ) , e vai retornar um vetor 
{										    // com as linhas que contêm essa paragem;
	s = Maximiza(s);
	string paragens;
	vector <Line> vectorLines = company.getLines();
	vector<int> v;
	for (unsigned int i = 0; i < vectorLines.size(); i++) // loop para percorrer todoas as linhas do vetor allLines
	{
		for (unsigned int u = 0; u < vectorLines[i].getBusStops().size(); u++) {// loop para percorrer as paragens de uma linha e verficar se 
			paragens = Maximiza(vectorLines[i].getBusStops()[u]);
			if (paragens == s) {				   // existe uma correspondencia a paragem associada a s.
				v.push_back(vectorLines[i].getId());
				v.push_back(u);
			}
		}
	}
	return v;
}
string Maximiza(string s) { // Para colocar todas as letras em maiusculas
	int ia = 0, n;
	while (ia < s.size()) {
		if (s[ia] >= 'a' && s[ia] <= 'z') {
			n = s[ia] - 'a';
			s[ia] = n + 'A';
		}
		ia++;
	}
	return s;
}



void HorarioParagem(Company &company) {
	vector<Line> vectorLines = company.getLines();
	int t, min, taux, minaux;
	int i, id, u, ua;
	string paragem;
	vector<int> ids;
	cout << "Digite a paragem que deseja : ";
	cin.ignore(1000, '\n');
	getline(cin, paragem);
	ids = linhasMesmaParagem(paragem, company);
	if (ids.empty()) {
		cout << "Nao ha linhas com essa paragem!\n"
			"Para melhor conhecimento das linhas va a gestao de linhas no menu principal\n\n\n\n";
		infoHome(company);
	}
	system("cls");
	cout << "PARAGEM  --" << Maximiza(paragem) << "--\n\n";
	for (u = 0; u < ids.size(); u++) {
		id = ids[u];
		u++;
		i = ids[u];
		for (ua = 0; ua < vectorLines.size(); ua++) {
			if (id == vectorLines[ua].getId()) {
				break;
			}
		}
		if (i != vectorLines[ua].getBusStops().size() - 1) {
			cout << id << "---->" << vectorLines[ua].getBusStops()[vectorLines[ua].getBusStops().size() - 1] << endl;
			t = 8;
			min = 0;
			for (unsigned int a = 0; a < i; a++) {
				min += vectorLines[ua].getTimings()[a];
			}
			minaux = 0;
			taux = 8;
			while (true) {
				if ((min / 60) != 0) {
					t += min / 60;;
					min = min % 60;
				}
				if ((minaux / 60) != 0) {
					taux += minaux / 60;;
					minaux = minaux % 60;
				}
				if ((taux > 22)) {
					break;
				}
				if (t >= 24) {
					t = 0;
				}
				cout << setw(2) << setfill('0') << t << ":" << setw(2) << setfill('0') << min << "\t";
				min += vectorLines[ua].getFreq();
				minaux += vectorLines[ua].getFreq();

			}
			cout << endl;
		}
		if (i != 0) {
			cout << id << "---->" << vectorLines[ua].getBusStops()[0] << endl;
			t = 8;
			min = 0;
			for (unsigned int a = 0; a < vectorLines[ua].getTimings().size(); a++) {
				min += vectorLines[ua].getTimings()[a];
			}
			for (unsigned int a = vectorLines[ua].getBusStops().size() - 1; a > i; a--) {
				min += vectorLines[ua].getTimings()[a - 1];
			}
			minaux = 0;
			taux = 8;
			while (true) {
				if ((min / 60) != 0) {
					t += min / 60;;
					min = min % 60;
				}
				if ((minaux / 60) != 0) {
					taux += minaux / 60;;
					minaux = minaux % 60;
				}
				if ((taux == 23 && minaux > 0) || (taux > 23)) {
					break;
				}
				if (t >= 24) {
					t = 0;
				}
				cout << setw(2) << setfill('0') << t << ":" << setw(2) << setfill('0') << min << "\t";
				min += vectorLines[ua].getFreq();
				minaux += vectorLines[ua].getFreq();

			}
			cout << endl;
		}
	}
	cout << "\n\n\n";
	infoHome(company);
}

void linhasComParagem(Company &company) // funcao que pede ao utilizador uma paragem e escreve o id de todas as linhas que contêm essa paragem
{
	string paragem;
	cout << "Digite a paragem que deseja : ";
	cin.ignore(1000, '\n');
	getline(cin, paragem);
	vector<int> l = linhasMesmaParagem(paragem, company); // vector que guarda os diferentes ids , usando a funcao linhasMesmaParagem;
	if (l.empty()) {
		cout << "\nNao ha linhas com essa paragem!\n"
			"Va ao menu principal e escolha gestao de linhas para melhor conhecimento.";
		return;
	}
	cout << "IDs de todas as linhas que passam pela paragem selecionada : " << endl;
	for (unsigned int i = 0; i < l.size(); i++) // para fazer cout dos ids contidos no vetor
	{
		cout << l[i] << endl;
		i++;
	}
	cout << endl << endl << endl << endl << endl << endl << endl;
	infoHome(company);


}

void percursoDuasParagens(Company &company) //incompleto
{
	vector<Line> vectorLines = company.getLines();
	string paragem1, paragem2;
	bool existe = false, existe1 = false;
	int index, index2, indexparagem1, indexparagem2;
	cout << "Indique o nome da primeira paragem : ";
	cin.ignore();
	getline(cin, paragem1);
	
	do {
		paragem1 = Maximiza(paragem1);
		for (unsigned int i = 0; i < vectorLines.size(); i++)
		{
			for (unsigned int u = 0; u < vectorLines[i].getBusStops().size(); u++)
				if (Maximiza(vectorLines[i].getBusStops()[u]) == paragem1)
				{
					index = i;
					indexparagem1 = u;
					existe = true;
				}
		}
		if (!existe)
		{
			
			cout << "Erro! Tente uma paragem valida : ";
			getline(cin, paragem1);
		}
	} while (!existe);

	cout << "Indique o nome da segunda paragem : ";
	cin.ignore();
	getline(cin, paragem2);

	do {
		paragem2 = Maximiza(paragem2);
		for (unsigned int i = 0; i < vectorLines.size(); i++)
		{
			for (unsigned int u = 0; u < vectorLines[i].getBusStops().size(); u++)
				if (Maximiza(vectorLines[i].getBusStops()[u]) == paragem2)
				{
					index2 = i;
					indexparagem2 = u;
					existe1 = true;
				}
		}
		if (!existe1)
		{

			cout << "Erro! Tente uma paragem valida : ";
			getline(cin, paragem2);
		}
	} while (!existe1);
	

	//// Caso as duas paragens estejam na mesma linha ////

	
	if (index == index2)
	{
		cout << "O percurso masi rapido \x82 utilizando a mesma linha no sentido :" << endl;
		for (unsigned int i = indexparagem1; i <= indexparagem2; i++)
		{
			if (i == indexparagem2)
				cout << vectorLines[index].getBusStops()[i];
			else cout << vectorLines[index].getBusStops()[i] << "-->";
		}
	}







	
	

}










/////////////////////////////////////////////Autocarros///////////////////////////////////////////////////////////////////

void autocarrosDisplay(Company &company)      //incompleto
{
	vector<Line> vectorLines = company.getLines();
	cout << "--------------- Autocarros SEMPRARROLAR ----------------" << endl;
	for (unsigned int i = 0; i < vectorLines.size(); i++)
	{
		cout << "ID : " <<vectorLines[i].getId() << endl;
		cout << "Tempo ida e volta : " << tempoIdaVolta(vectorLines[i]) << endl;
		cout << "Numero de autocarros : " << numeroAutocarrosLinha(tempoIdaVolta(vectorLines[i]), vectorLines[i]) << endl;


	}




}

int tempoIdaVolta(Line linha)
{
	int total = 0;
	for (unsigned int i = 0; i < linha.getTimings().size(); i++)
	{
		total += linha.getTimings()[i];
	}

	return (total * 2);
}

int numeroAutocarrosLinha(int Tempo , Line linha)
{
	return (int)((double)Tempo / linha.getFreq() + 1.0);

}







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

	homeMenu(object);

	
	return 0;
}
