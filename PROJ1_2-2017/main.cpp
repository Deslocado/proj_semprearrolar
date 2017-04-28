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
using namespace std;


void PedirNomeFicheiroLinhas()
{
	string FileName;
	ifstream LinesFile;
	cout << "Indique o nome do ficheiro de linhas a utilizar (ex : filename.txt) : ";
	cin.ignore();
	getline(cin, FileName);
	LinesFile.open(FileName);
	if (LinesFile.fail())



}

void InitialMenu()
{




}



int main() {
	
	return 0;
}
