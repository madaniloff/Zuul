#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include "room.h"

using namespace std;

//Item vector for the room
room::room() {
  roomItem = new vector<item*>();
}
//Returns the description of the room
char* room::getDescription() {
  return Description;
}
//Returns the name of the room
char* room::getroomName() {
  return roomName;
}
//Return the currentRoom
room* room::getcurrentRoom() {
  return currentRoom;
}

void room::setExit(map<char*, room*>* zmap) {
  exits = zmap; 
}
//Return the exits in a room
map<char*, room*>* room::getExits() {
  return exits;
}
//Prints exits
char* room::printExits() {
  map<char*, room*>::iterator it;
    for (it=exits->begin(); it != exits->end(); it++) {
      cout << it->first << " ";
    }
  cout << endl;
}

//Adds item to item vector in the room
char* room::setItem(item* itemName) {
  roomItem->push_back(itemName);
}

//Returns items
vector<item*>* room::backItems() {
  return roomItem;
}

//Prints out items from the item vector
char* room::getItems() {
  //Creates an iterator to go through the item vector in the rooms
  vector<item*>::iterator it;
  for (it = roomItem->begin(); it != roomItem->end(); it++) {
    cout << (*it)->itemName << " ";
  }
  cout << endl;
}

//Checks if the exit exists within the room
bool room::validExit(char* direction) {
  //Create an iterator to go through the map
  map<char*, room*>::iterator it;
  //Check if any of the exits match the inputted char
  for (it=exits->begin(); it != exits->end(); it++) {
    if (strcmp(it->first, direction)==0) {
      return true;
    }
  }
  return false;
}

//Checks if the inputted string matches with an item in the room,
bool room::validItem(char* itemName) {
  //Creates an iterator to go through the vector
  vector<item*>::iterator it;
  for(it = roomItem->begin(); it != roomItem->end(); it++) {
    if (strcmp((*it)->getitemName(), itemName) == 0) {
      return true;
    }
  }
  return false;
}
