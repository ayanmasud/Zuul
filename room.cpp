#ifndef ROOM_H // header guard
#define ROOM_H
#include <iostream>
#include <cstring>
#include "room.h"
#include <map>

using namespace std;

room::room() {

}
void room::setExit(char direction, room* neighbor) { // sets exits for a room
  exits.insert(pair<char, room*>(direction, neighbor));
}
void room::getDescription() { // print information about the room you're in
  cout << "You are " << description << endl << endl;

  map<char, room*>::iterator it = exits.begin(); // prints the exits for the room
  cout << "Exits: " << endl;
  while (it != exits.end()) {
    cout << it->second->name << " is '" << it->first << "'" << endl;
    ++it;
  }
  cout << endl;

  cout << "Items in the room: " << endl; // prints the items inside the room
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
