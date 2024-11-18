#ifndef ROOM_H // header guard
#define ROOM_H
#include <iostream>
#include <cstring>
#include "room.h"
#include <map>

using namespace std;

// this file carries the functions that the room types can do
room::room() {

}
void room::setExit(char direction, room* neighbor) { // sets exits for a room
  exits.insert(pair<char, room*>(direction, neighbor));
}
void room::getDescription() { // print information about the room you're in
  cout << endl << "You are " << description << endl << endl;

  map<char, room*>::iterator it = exits.begin(); // prints the exits for the room
  cout << "Exits: " << endl;
  while (it != exits.end()) {
    cout << it->second->name << " is '" << it->first << "'" << endl;
    ++it;
  }
  cout << endl;

  cout << "Items in the room: " << endl; // prints the items inside the room
  if (hasItem1) {
    cout << "Spoon" << endl;
  }
  if (hasItem2) {
    cout << "Toilet Paper" << endl;
  }
  if (hasItem3) {
    cout << "Photo of Ehan" << endl;
  }
  if (hasItem4) {
    cout << "Phone" << endl;
  }
  if (hasItem5) {
    cout << "Car Keys" << endl;
  }
  cout << endl;
}
room* room::getExit(char direction) {
  if (exits.find(direction) != exits.end()) { // checks to see if this direction exists in the map
    return exits[direction]; // returns that exit so that the current room can turn into it
  }
  else { // direction inputted isnt in the map
    cout << "Direction does not exist in this room" << endl;
  }
  return this; // since we have to return something if the direction inputted doesnt exist, we return this room which it already is
}
bool room::getItem(int id) { // after recieving the id of the item being picked up, it will check if the room has that item and if it does, you picked it up!
  if (id == 1 && hasItem1 == true) {
    cout << "You picked up a spoon." << endl;
    hasItem1 == false;
    return true;
  }
  if (id == 2 && hasItem2 == true) {
    cout << "You picked up toilet paper." << endl;
    hasItem2 == false;
    return true;
  }
  if (id == 3 && hasItem3 == true) {
    cout << "You picked up a photo of Ehan." << endl;
    hasItem3 == false;
    return true;
  }
  if (id == 4 && hasItem4 == true) {
    cout << "You picked up a phone." << endl;
    hasItem4 == false;
    return true;
  }
  if (id == 5 && hasItem5 == true) {
    cout << "You picked up a car keys." << endl;
    hasItem5 == false;
    return true;
  }
  return false;
}

#endif
