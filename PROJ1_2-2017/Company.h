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
 public:
	 Company(string nome, string fichCondutores, string fichLinhas);
  // metodos get
  string getNome() const;
  vector<Line> Company::getLines() const;
  vector<Driver> Company::getDrivers() const;
  // metodos set
  // outros metodos
  void distribuiServico(); // funcao que implementa a afectacao de servico
};
