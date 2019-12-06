#ifndef ITEM_H
#define ITEM_H

//File that initializes variables and methods for the item class

#include <iostream>
#include <cstring>
#include <string.h>


using namespace std;

class item {
 public:
  item();
  char* getDescription();
  char* getitemName();
  char Description[50];
  char itemName[30];
};

#endif
