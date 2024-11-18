/*Zuul: a text-based adventure game
  Author: Ayan Masud
  Date: 11/18/24
 */

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
  room* outside = new room();
  strcpy(outside->name, "Outside");
  strcpy(outside->description, "outside.");
  rooms.push_back(outside);
  room* livingroom = new room();
  strcpy(livingroom->name, "Living Room");
  strcpy(livingroom->description, "in the living room.");
  rooms.push_back(livingroom);
  room* kitchen = new room();
  strcpy(kitchen->name, "Kitchen");
  strcpy(kitchen->description, "in the kitchen.");
  rooms.push_back(kitchen);
  room* bathroom = new room();
  strcpy(bathroom->name, "Bathroom");
  strcpy(bathroom->description, "in the bathroom.");
  rooms.push_back(bathroom);
  room* diningroom = new room();
  strcpy(diningroom->name, "Dining Room");
  strcpy(diningroom->description, "in the dining room.");
  rooms.push_back(diningroom);
  room* recroom = new room();
  strcpy(recroom->name, "Recreational Room");
  strcpy(recroom->description, "in the recreational room.");
  rooms.push_back(recroom);
  room* corridor = new room();
  strcpy(corridor->name, "Corridor");
  strcpy(corridor->description, "in the corridor.");
  rooms.push_back(corridor);
  room* ayanroom = new room();
  strcpy(ayanroom->name, "Ayan's Bedroom");
  strcpy(ayanroom->description, "in Ayan's bedroom.");
  rooms.push_back(ayanroom);
  room* bathroom2 = new room();
  strcpy(bathroom2->name, "Bathroom");
  strcpy(bathroom2->description, "in the bathroom.");
  rooms.push_back(bathroom2);
  room* ehanroom = new room();
  strcpy(ehanroom->name, "Ehan's Bedroom");
  strcpy(ehanroom->description, "in Ehan's bedroom.");
  rooms.push_back(ehanroom);
  room* livingroom2 = new room();
  strcpy(livingroom2->name, "Living Room");
  strcpy(livingroom2->description, "in the living room.");
  rooms.push_back(livingroom2);
  room* hallway = new room();
  strcpy(hallway->name, "Hallway");
  strcpy(hallway->description, "in the hallway.");
  rooms.push_back(hallway);
  room* gymroom = new room();
  strcpy(gymroom->name, "Gym Room");
  strcpy(gymroom->description, "in the gym room.");
  rooms.push_back(gymroom);
  room* garage = new room();
  strcpy(garage->name, "Garage");
  strcpy(garage->description, "in the garage.");
  rooms.push_back(garage);
  room* outside2 = new room();
  strcpy(outside2->name, "Outside");
  strcpy(outside2->description, "outside again!");
  rooms.push_back(outside2);
  
  // initialize items
  kitchen->hasItem1 = true;
  bathroom2->hasItem2 = true;
  ehanroom->hasItem3 = true;
  livingroom2->hasItem4 = true;
  garage->hasItem5 = true;

  // set the exits for each room
  outside->setExit('n', livingroom);
  livingroom->setExit('s', outside);
  livingroom->setExit('e', diningroom);
  livingroom->setExit('n', kitchen);
  kitchen->setExit('s', livingroom);
  kitchen->setExit('e', bathroom);
  bathroom->setExit('w', kitchen);
  diningroom->setExit('w', livingroom);
  diningroom->setExit('e', recroom);
  recroom->setExit('w', diningroom);
  recroom->setExit('e', corridor);
  corridor->setExit('w', recroom);
  corridor->setExit('e', ehanroom);
  corridor->setExit('n', ayanroom);
  corridor->setExit('s', livingroom2);
  ayanroom->setExit('s', corridor);
  ayanroom->setExit('e', bathroom2);
  bathroom2->setExit('w', ayanroom);
  ehanroom->setExit('w', corridor);
  livingroom2->setExit('n', corridor);
  livingroom2->setExit('e', hallway);
  hallway->setExit('w', livingroom2);
  hallway->setExit('e', gymroom);
  gymroom->setExit('w', hallway);
  gymroom->setExit('n', garage);
  garage->setExit('s', gymroom);
  garage->setExit('n', outside2);
  outside2->setExit('s', garage);

  // sets the inventory
  bool hasItem1 = false; // spoon
  bool hasItem2 = false; // toilet paper
  bool hasItem3 = false; // photo of ehan
  bool hasItem4 = false; // phone
  bool hasItem5 = false; // car keys

  currentroom = outside; // starts the player at this room

  // prints a starting message
  cout << "Welcome to my home!" << endl << "Objective: Although you are already outside, find a second way to get outside." << endl << "If you need any help with commands, type 'help'" << endl << "Good luck!" << endl;
  currentroom->getDescription();
  
  bool playing = true;
  while(playing == true) {

    char cmd[10];
    cout << endl << "Command: ";
    cin.getline(cmd, 10);

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

      if (currentroom == outside2) { // winning condition
	cout << "Great job getting outside! Hope you had fun.";
	break;
      }
      
      currentroom->getDescription(); // gives a description of the room you just went into
    }
    else if (strcmp(cmd, "get") == 0) { // get items from a room command
      cout << "What? ";
      char item[16];
      cin.getline(item, 16);

      vector<room*>::iterator it;
      
      for (it = rooms.begin(); it < rooms.end(); it++) {
        if (strcmp((*it)->name, currentroom->name) == 0) { // we need to run an iterator through the vector of rooms to figure out which room in the vector we are in. that way, we can actually change the room instead of the variable holding the current room
          if (strcmp(item, "Spoon") == 0) {
            if (currentroom->getItem(1) == true) { // room has spoon
              (*it)->hasItem1 = false;
              hasItem1 = true;
            }
          }
          else if (strcmp(item, "Toilet Paper") == 0) {
            if (currentroom->getItem(2) == true) { // room has toilet paper
              (*it)->hasItem2 = false;
              hasItem2 = true;
            }
          }
          else if (strcmp(item, "Photo of Ehan") == 0) {
            if (currentroom->getItem(3) == true) { // room has photo of ehan
              (*it)->hasItem3 = false;
              hasItem3 = true;
            }
          }
          else if (strcmp(item, "Phone") == 0) {
            if (currentroom->getItem(4) == true) { // room has phone
              (*it)->hasItem4 = false;
              hasItem4 = true;
            }
          }
          else if (strcmp(item, "Car Keys") == 0) {
            if (currentroom->getItem(5) == true) { // room has car keys
              (*it)->hasItem5 = false;
              hasItem5 = true;
            }
          }
          else {
            cout << "This room does not have this item." << endl;
          }
          //currentroom->getDescription(); // shows the description again because it got updated
        }
      }
    }
    else if (strcmp(cmd, "drop") == 0) { // drop items into a room command
      cout << "What? ";
      char item[15];
      cin.getline(item, 15);

      vector<room*>::iterator it;
      
      for (it = rooms.begin(); it < rooms.end(); it++) {
        if (strcmp((*it)->name, currentroom->name) == 0) { // we need to run an iterator through the vector of rooms to figure out which room in the vector we are in. that way, we can actually change the room instead of the variable holding the current room
          if (strcmp(item, "Spoon") == 0) {
            if (hasItem1 == true) { // you have spoon
              hasItem1 = false;
              currentroom->hasItem1 = true;
              (*it)->hasItem1 = true;
            }
          }
          else if (strcmp(item, "Toilet Paper") == 0) {
            if (hasItem2 == true) { // you have toilet paper
              hasItem2 = false;
              currentroom->hasItem2 = true;
              (*it)->hasItem2 = true;
            }
          }
          else if (strcmp(item, "Photo of Ehan") == 0) {
            if (hasItem3 == true) { // you have photo of ehan
              hasItem3 = false;
              currentroom->hasItem3 = true;
              (*it)->hasItem3 = true;
            }
          }
          else if (strcmp(item, "Phone") == 0) {
            if (hasItem4 == true) { // you have phone
              hasItem4 = false;
              currentroom->hasItem4 = true;
              (*it)->hasItem4 = true;
            }
          }
          else if (strcmp(item, "Car Keys") == 0) {
            if (hasItem5 == true) { // you have car keys
              hasItem5 = false;
              currentroom->hasItem5 = true;
              (*it)->hasItem5 = true;
            }
          }
          else {
            cout << "You do not have this item." << endl;
          }
          //currentroom->getDescription(); // shows the description again because it got updated
        }
      }
    }
    else if (strcmp(cmd, "inventory") == 0) { // prints the inventory based off what items you have
      cout << endl << "Inventory:" << endl;
      if (hasItem1 == true) {
        cout << "Spoon" << endl;
      }
      if (hasItem2 == true) {
        cout << "Toilet Paper" << endl;
      }
      if (hasItem3 == true) {
        cout << "Photo of Ehan" << endl;
      }
      if (hasItem4 == true) {
        cout << "Phone" << endl;
      }
      if (hasItem5 == true) {
        cout << "Car Keys" << endl;
      }
      cout << endl;
    }
    else if (strcmp(cmd, "help") == 0) { // prints a list of all the commads that the player can do
      cout << endl << "Possible commands:" << endl << "go -> n,s,e,w" << endl << "quit" << endl << "help" << endl << "inventory" << endl << "get -> item name" << endl << "drop -> item name" << endl << endl;
    }
    else if (strcmp(cmd, "quit") == 0) { // quit command
      break;
    }
  }

  return 0;
}
