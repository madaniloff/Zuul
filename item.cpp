//Return methods for items
#include <iostream>
#include <cstring>
#include <string.h>
#include "item.h"
#include "room.h"

using namespace std;

item::item() {

}
//Returns description of an item
char* item::getDescription() {
  return Description;
}
//Returns the name of an item
char* item::getitemName() {
  return itemName;
}
