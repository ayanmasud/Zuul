#include <iostream>
#include <map>

using namespace std;

class room {
 public:
  char name[80];
  char description[80];
  bool hasItem1 = false;
  bool hasItem2 = false;
  bool hasItem3 = false;
  bool hasItem4 = false;
  bool hasItem5 = false;

  map<char, room*> exits;

  room();
  void setExit(char direction, room* neighbor);
  void getDescription();
};
