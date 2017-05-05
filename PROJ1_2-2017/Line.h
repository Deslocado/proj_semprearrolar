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

  void setId(int i)
  {
	  id = i;
	}
  void setFreq(int i)
  {
	  freq = i;
  }
  void setBusStops(vector<string> stops)
  {
	  busStopList = stops;
  }
  void setTimings(vector<int> timings)
  {
	  timesList = timings;
}


  // other methods
  
};
