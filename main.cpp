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
  rooms.push_back(bedroom);
  room* bathroom = new room();
  strcpy(bathroom->name, "Bathroom");
  strcpy(bathroom->description, "in the bathroom.");
  rooms.push_back(bathroom);

  // initialize items
  bedroom->hasItem1 = true;

  // set the exits for each room
  bedroom->setExit('n', bathroom);
  bathroom->setExit('s', bedroom);

  // sets the inventory
  bool hasItem1 = false;
  bool hasItem2 = false;
  bool hasItem3 = false;
  bool hasItem4 = false;
  bool hasItem5 = false;

  currentroom = bedroom;
  currentroom->getDescription();

  bool playing = true;
  while(playing == true) {

    char cmd[8];
    cout << endl << "Command: ";
    cin.getline(cmd, 8);

    if (strcmp(cmd, "go") == 0) { // go command
      cout << "Where? ";
      char dir[2];
      cin.getline(dir, 2);
      if (strcmp(dir, "n") == 0) { // go north
        currentroom = currentroom->getExit('n');
      }
      else if (strcmp(dir, "s") == 0) { // go south
        currentroom = currentroom->getExit('s');
      }
      else if (strcmp(dir, "e") == 0) { // go east
        currentroom = currentroom->getExit('e');
      }
      else if (strcmp(dir, "w") == 0) { // go west
        currentroom = currentroom->getExit('w');
      }
      currentroom->getDescription();
    }
    else if (strcmp(cmd, "get") == 0) { // get items from a room command
      cout << "What? ";
      char item[15];
      cin.getline(item, 15);

      vector<room*>::iterator it;
      //cout << "cr: " << currentroom->name;
      for (it = rooms.begin(); it < rooms.end(); it++) {
        //cout << (*it)->name << endl;
        if (strcmp((*it)->name, currentroom->name) == 0) { // we need to run an iterator through the vector of rooms to figure out which room in the vector we are in. that way, we can actually change the room instead of the variable holding the current room
          //cout << "through";
          if (strcmp(item, "Spoon") == 0) {
            if (currentroom->getItem(1) == true) { // room has spoon
              (*it)->hasItem1 = false;
              hasItem1 = true;
            }
          }
          else if (strcmp(item, "Toilet Paper") == 0) {
            if (currentroom->getItem(2) == true) { // room has spoon
              (*it)->hasItem2 = false;
              hasItem2 = true;
            }
          }
          else if (strcmp(item, "Photo of Ehan") == 0) {
            if (currentroom->getItem(3) == true) { // room has spoon
              (*it)->hasItem3 = false;
              hasItem3 = true;
            }
          }
          else if (strcmp(item, "Phone") == 0) {
            if (currentroom->getItem(4) == true) { // room has spoon
              (*it)->hasItem4 = false;
              hasItem4 = true;
            }
          }
          else if (strcmp(item, "Car Keys") == 0) {
            if (currentroom->getItem(5) == true) { // room has spoon
              (*it)->hasItem5 = false;
              hasItem5 = true;
            }
          }
          else {
            cout << "This room does not have this item." << endl;
          }
        }
      }
    }
    else if (strcmp(cmd, "drop") == 0) {

    }
    else if (strcmp(cmd, "inventory") == 0) {

    }
    else if (strcmp(cmd, "help") == 0) {

    }
    else if (strcmp(cmd, "quit") == 0) { // quit command
      break;
    }
  }

  return 0;
}
