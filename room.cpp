#ifndef ROOM_H // header guard
#define ROOM_H
#include <iostream>
#include <cstring>
#include "room.h"
#include <map>

using namespace std;

room::room() {
  
}
void room::setExit(char direction[6], room neighbor) {
  exits.insert(pair<char, room>(direction, neighbor));
}
void room::getDescription() {
  cout << "You are " << description << endl << endl;
  cout << "Exits: " << endl << endl; //figure out maps
  cout << "Items in the room: " << endl;
  if (hasItem1) {
    cout << "Item 1" << endl;
  }
  if (hasItem2) {
    cout << "item 2" << endl;
  }
  if (hasItem3) {
    cout << "item 3" << endl;
  }
  if (hasItem4) {
    cout << "item 4" << endl;
  }
  if (hasItem5) {
    cout << "item 5" << endl;
  }
  cout << endl;
}

#endif
