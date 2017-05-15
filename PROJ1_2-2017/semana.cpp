#include "semana.h"
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


semana::semana(string day , unsigned int inicio , unsigned int fim)
{
	inicioDia = inicio;
	fimDia = fim;
	dia = day;
}

///get////
unsigned int semana::getInicioDia() const
{
	return inicioDia;
}
unsigned int semana::getFimDia() const
{
	return fimDia;
}
string semana::getDia() const
{
	return dia;
}

///set///

void semana::setInicioDia(unsigned int i)
{
	inicioDia = i;
}
void semana::setFimDia(unsigned int i)
{
	fimDia = i;
}
void semana::setDia(string s)
{
	dia = s;
}