#pragma once
#include <string>
using namespace std;
class semana
{
private:
	string dia;
	unsigned int inicioDia;
	unsigned fimDia;
public:
	semana(string day , unsigned int inicio, unsigned int fim);
	////get////
	unsigned int getInicioDia() const;
	unsigned int getFimDia() const;
	string getDia() const;

	/////set////
	void setInicioDia(unsigned int i);
	void setFimDia(unsigned int i);
	void setDia(string s);
};

