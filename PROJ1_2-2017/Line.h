#pragma once

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Line{
 private:
  unsigned int id;
  unsigned int freq;
  vector<string> busStopList;
  vector<int> timesList;
 public:
	 Line(string textLine);
  // metodos get
  unsigned int getId() const;
  unsigned int getFreq() const;
  vector<string> getBusStops() const;
  vector<int> getTimings() const;
  // set methods

  void setId(unsigned int i);
  void setFreq(unsigned int i);
  void setBusStops(vector<string> stops);
  void setTimings(vector<int> timings);


  // other methods
  
};
