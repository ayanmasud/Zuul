File Edit Options Buffers Tools C++ Help
#include <iostream>
#include "room.h"
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

int main() {
  vector<room*> rooms;
  room* currentroom; // holds the room you are currently in

  // create the rooms and set their descriptions
  room* bedroom = new room();
  strcpy(bedroom->name, "Bedroom");
  strcpy(bedroom->description, "in the bedroom.");
  room* bathroom = new room();
  strcpy(bathroom->name, "Bathroom");
  strcpy(bathroom->description, "in the bathroom.");

  // initialize items
  bedroom->hasItem1 = true;

  // set the exits for each room
  bedroom->setExit('n', bathroom);
  bathroom->setExit('s', bedroom);

  bool playing = true;
  while(playing == true) {
    currentroom = bedroom;
    currentroom->getDescription();

    char cmd[8];
    char direction[2];

    char input[80];
    cin.getline(input, 80);

    bool space = false;
    int j = 0;
    int k = 0;
    for (int i = 0; i < strlen(input); i++) {
      if (input[i] == ' '){
        space = true;
      }

      if (space == false) {
        cmd[j] = input[i];
        j++;
      }
      else {
        direction[k] = input [i];
        k++;
      }
    }

    if (strcmp(cmd, "go") == 0) {

    }

    break;
  }

  return 0;
}
