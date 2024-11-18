#include <iostream>
#include <map>

using namespace std;

// this file carries each of the variables that room types have
class room {
 public:
  char name[80]; // room name
  char description[80]; // room description
  bool hasItem1 = false; // spoon
  bool hasItem2 = false; // toilet paper
  bool hasItem3 = false; // photo of ehan
  bool hasItem4 = false; // phone
  bool hasItem5 = false; // car keys

  map<char, room*> exits; // map contains all the possible exits for this room. stored by the direction (char) and the neighbor (room)

  room();
  void setExit(char direction, room* neighbor);
  void getDescription();
  room* getExit(char direction);
  bool getItem(int id);
};
