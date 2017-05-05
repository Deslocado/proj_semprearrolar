#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Line.h"
#include "Driver.h"


using namespace std;

class Company{
 private:
  string nome;
  vector<Driver> condutores;
  vector<Line> linhas;
  string fichCondutores;
  string fichLinhas;
 public:
	 Company(string nome, string fichCondutores, string fichLinhas);
  // metodos get
	 string getFichDrivers();
	 string getFichLinhas();
  string getNome() const;
  vector<Line> Company::getLines() const;
  vector<Driver> Company::getDrivers() const;
  // metodos set
  void setCondutores(vector<Driver> vector)
  {
	  condutores = vector;
  }
  // outros metodos
  void distribuiServico(); // funcao que implementa a afectacao de servico
};
