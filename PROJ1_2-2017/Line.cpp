#include "Line.h"
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
#include "Company.h"

Line::Line(string textLine){

  // INITIALISATION CODE GOES IN HERE
	string aux;
	string s1, s2, s3;
	int i, freq;
	int aux1;
	vector<string> seq;
	vector<int> t;

	stringstream ss1; // uso de stringstream para os numeros correspondentes a detalhes da linha 
	s3 = textLine.substr(0, textLine.find_first_of(';')); // passa para s3 o id da linha como string 
	ss1.str(s3);
	ss1 >> i;
	textLine = textLine.substr(textLine.find_first_of(';') + 1); // s deixa agora de ter a parte do id ..

	s3 = textLine.substr(0, textLine.find_first_of(';'));  // passa para s3 a freq da linha 
	ss1.str(s3);
	ss1 >> freq;
	textLine = textLine.substr(textLine.find_first_of(';') + 1); // s fica sem a freq ..

	s1 = textLine.substr(0, textLine.find_first_of(';'));
	s2 = textLine.substr(textLine.find_first_of(';') + 1);

	while (true) {
		if (s1.find_first_of(',') == -1) {
			s1 = s1.substr(1);
			seq.push_back(s1);
			break;
		}
		string aux = s1.substr(1, s1.find_first_of(',') - 1);
		s1 = s1.substr(s1.find_first_of(',') + 1);
		seq.push_back(aux);
	}


	while (true)
	{    // ciclo utilizado para passar o tempo entre paragens para o vetor t (vetor de inteiros)
		if (s2.find_first_of(',') == -1)
		{
			ss1.str(s2);
			ss1 >> aux1;
			t.push_back(aux1);
			break;
		}

		string aux = s2.substr(1, s2.find_first_of(',') - 1);
		s2 = s2.substr(s2.find_first_of(',') + 1);
		ss1.str(aux);
		ss1 >> aux1;
		t.push_back(aux1);
		ss1.clear();


	}

	setId(i);
	setFreq(freq);
	setBusStops(seq);
	setTimings(t);
}

////////////////
// get methods
////////////////

unsigned int Line::getId() const{
  return id;
}

unsigned int Line::getFreq() const{
	return freq;
}

vector<string> Line::getBusStops() const{
  return busStopList;
}

vector<int> Line::getTimings() const{
  return timesList;
}

