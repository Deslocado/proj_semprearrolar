#include "Driver.h"
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

Driver::Driver(string textLine){

  // INITIALISATION CODE GOES IN HERE
	int id, h_t, h_s, t_r;
	string nome;
	stringstream ss;
	string aux1;

	aux1 = textLine.substr(0, textLine.find_first_of(';'));
	ss.str(aux1);
	ss >> id;
	ss.clear();
	textLine = textLine.substr(textLine.find_first_of(';') + 1);
	aux1 = textLine.substr(1, textLine.find_first_of(';') - 2);
	textLine = textLine.substr(textLine.find_first_of(';') + 1);
	nome = aux1;
	aux1 = textLine.substr(0, textLine.find_first_of(';'));
	ss.str(aux1);
	ss >> h_t;
	ss.clear();
	textLine = textLine.substr(textLine.find_first_of(';') + 1);
	aux1 = textLine.substr(0, textLine.find_first_of(';'));
	ss.str(aux1);
	ss >> h_s;
	ss.clear();
	textLine = textLine.substr(textLine.find_first_of(';') + 1);
	ss.str(textLine);
	ss >> t_r;
	ss.clear();
	
	setId(id);
	setName(nome);
	setMaxHours(h_t);
	setMaxWeekHours(h_s);
	setMinHours(t_r);
}

//////////////
// get methods
//////////////

unsigned int Driver::getId() const{
  return id;
}

string Driver::getName() const{
  return name;
}

unsigned int Driver::getShiftMaxDuration() const{
  return maxHours;
}

unsigned int Driver::getMaxWeekWorkingTime() const{
  return maxWeekWorkingTime;
}

unsigned int Driver::getMinRestTime() const{
  return minRestTime;
}

vector<Shift> Driver::getShifts() const{
  return shifts;
}

///// set methods ////

void Driver::setId(unsigned int i)
{
	id = i;
}

void Driver::setMaxHours(unsigned int i)
{
	maxHours = i;
}

void Driver::setName(string name)
{
	this->name = name;
}

void Driver::setMaxWeekHours(unsigned int i)
{
	maxWeekWorkingTime = i;
}

void Driver::setMinHours(unsigned int i)
{
	minRestTime = i;
}

void Driver::setShifts(vector<Shift> vector)
{
	shifts = vector;
}