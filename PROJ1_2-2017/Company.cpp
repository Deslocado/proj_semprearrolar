#include "Company.h"
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

Company::Company(string nome, string fichCondutores, string fichLinhas){
  
	this->fichCondutores = fichCondutores;
	this->fichLinhas = fichLinhas;

	ifstream LinesFile;
	LinesFile.open(fichLinhas);

	string textline;
		while (getline(LinesFile, textline)){
			Line line(textline);
				linhas.push_back(line); 
		}

		LinesFile.close();

	ifstream DriversFile;
	DriversFile.open(fichCondutores);
	while (getline(DriversFile, textline)) {
		Driver condutor(textline);
		condutores.push_back(condutor);

	}
	DriversFile.close();

}

////////////////////////////////
// metodos get

string Company::getFichDrivers()
{
	return fichCondutores;
}
string Company::getFichLinhas()
{
	return fichLinhas;
}
vector<Line> Company::getLines() const
{

	return linhas;


}
vector<Driver> Company::getDrivers() const
{
	return condutores;
}
///////////////////////////////
string Company::getNome() const{
  return nome;
}

//////////////////////////////
// metodos set
/////////////////////////////


////////////////////////////
// outros metodos
///////////////////////////
void Company::distribuiServico(){
}

