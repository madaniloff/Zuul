#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>
#include <map>
#include "item.h"

using namespace std;

class room {
 public:
  //Creation of variables and methods
  room();
  char* getDescription();
  room* getcurrentRoom();
  char* getroomName();
  void setExit(map<char*, room*>*);
  map<char*, room*>* getExits();
  vector<item*>* backItems();
  char* setItem(item* itemName);
  bool validItem(char* itemName);
  bool validExit(char* direction);
  char* getItems();
  char* printExits();
  vector<item*>* roomItem;
  char Description[200];
  char roomName[100];
  char itemName[100];
  room *currentRoom; 
  map<char*, room*>* exits;
};


#endif
