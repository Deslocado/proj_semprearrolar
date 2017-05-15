#include "Bus.h"


Bus::  Bus(unsigned int id, unsigned int driver, unsigned int line){

	orderInLine = id;
	driverId = driver;
	lineId = line;
  
}

Bus::Bus(unsigned int order, unsigned int linha) {
	lineId = linha;
	orderInLine = order;
}
////////////////////////////////
// get methods
///////////////////////////////
unsigned int Bus::getBusOrderInLine() const{
  return orderInLine;
}

unsigned int Bus::getDriverId() const{
  return driverId;
}

unsigned int Bus::getLineId() const{
  return lineId;
}

vector<Shift> Bus::getSchedule() const{
  return schedule;
}


//////////////////////////////
// metodos set
/////////////////////////////
void Bus::setBusOrderInLine(unsigned int i)
{
	orderInLine = i;
}

void Bus::setDriverId(unsigned int i)
{
	driverId = i;
}

void Bus::setLineId(unsigned int i)
{
	lineId = i;
}

void Bus::setSchedule(vector<Shift> vector)
{
	schedule = vector;
}


////////////////////////////
// outher methods
///////////////////////////
