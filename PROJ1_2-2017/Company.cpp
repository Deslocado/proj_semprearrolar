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

Empresa::Empresa(string nome, string fichCondutores, string fichLinhas){
  
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

vector<Line> Empresa::getLines() const
{

	return linhas;


}
vector<Driver> Empresa::getDrivers() const
{
	return condutores;
}
///////////////////////////////
string Empresa::getNome() const{
  return nome;
}

//////////////////////////////
// metodos set
/////////////////////////////

////////////////////////////
// outros metodos
///////////////////////////
void Empresa::distribuiServico(){
}
