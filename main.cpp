//This program creates an adventure game called Zuul with 15 rooms and 5 items
//Author: Mark Daniloff
//12/2/2019
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stdio.h>
#include <cctype>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

int main() {
  //Create room vector
  vector<room*> *r = new vector<room*>();
  //Create inventory vector
  vector<item*> *i = new vector<item*>();
  bool playing = true;
  
  //Introduction
  cout << "You are driving across the countryside when you spot a dark castle in the distance" << endl;
  cout << "Intrigued by the possibility of treasure, you drive up to it and park outside" << endl;
  cout << "Now you must investigate and bring back some treasure from the castle!" << endl;

  //Defining rooms
  //A room is created, then a name and description is added to it in the room class
  //Then it's pushed back into the room array " r"
  room* rVan = new room();
  strcpy(rVan->Description, "Bring back treasure!");
  strcpy(rVan->roomName, "Van");
  r->push_back(rVan);
  room* rOutside = new room();
  strcpy(rOutside->Description, "A big drawbridge looms before you. The grass is patchy and uncared for. Thunder cracks in the distance");
  strcpy(rOutside->roomName, "Outside of the castle");
  r->push_back(rOutside);
  room* rShed = new room();
  strcpy(rShed->Description, "There's not much in here except for rusty tools and moldy crates.");
  strcpy(rShed->roomName, "Groundskeeping shed");
  r->push_back(rShed);
  room* rStable = new room();
  strcpy(rStable->Description, "Piles of old hay and cobwebs line the room");
  strcpy(rStable->roomName, "Stable");
  r->push_back(rStable);
  room* rEntry = new room();
  strcpy(rEntry->Description, "You enter a large stone hall.");
  strcpy(rEntry->roomName, "Castle Entry");
  r->push_back(rEntry);
  room* rThroneroom = new room();  
  strcpy(rThroneroom->Description, "A huge rusty throne is against the back wall.");
  strcpy(rThroneroom->roomName, "Throne Room");
  r->push_back(rThroneroom);
  room* rLibrary = new room();
  strcpy(rLibrary->Description, "A large room filled with dusty bookshelves");
  strcpy(rLibrary->roomName, "Library");
  r->push_back(rLibrary);
  room* rCellar = new room();
  strcpy(rCellar->Description, "A small stone room lined with barrels of alcohol");
  strcpy(rCellar->roomName, "Cellar");
  r->push_back(rCellar);
  room* rChapel = new room();
  strcpy(rChapel->Description, "A stone chapel with stained glass, decrepit pews, and an altar");
  strcpy(rChapel->roomName, "Chapel");
  r->push_back(rChapel);
  room* rTreasure = new room();
  strcpy(rTreasure->Description, "A secret room filled with chests");
  strcpy(rTreasure->roomName, "Treasure room");
  r->push_back(rTreasure);
  room* rBlacksmith = new room();
  strcpy(rBlacksmith->Description, "A blacksmiths room with many old tools lying around");
  strcpy(rBlacksmith->roomName, "Blacksmith");
  r->push_back(rBlacksmith);
  room* rQuarry = new room();
  strcpy(rQuarry->Description, "A large quarry with large stones strewn about");
  strcpy(rQuarry->roomName, "Quarry");
  room* rKitchen = new room();
  strcpy(rKitchen->Description, "A room filled with rusted pots and pans and rotting food");
  strcpy(rKitchen->roomName, "Kitchen");
  r->push_back(rKitchen);
  room* rPantry = new room();
  strcpy(rPantry->Description, "A small room lined with cans and rotten food");
  strcpy(rPantry->roomName, "Pantry");
  r->push_back(rPantry);
  room* rDungeon = new room();
  strcpy(rDungeon->Description, "A stone room filled with cells and skeletons");
  strcpy(rDungeon->roomName, "Dungeon");

  //set the current room
  room* currentRoom = rVan;
   
  //Defining items
  //Item is created and is assigned a name and definition
  //After that it is added to an item vector in its assigned room
  item* iBook = new item();
  strcpy(iBook->itemName, "Book");
  rLibrary->setItem(iBook);
  item* iCrown = new item();
  strcpy(iCrown->itemName, "Crown");
  rTreasure->setItem(iCrown);
  item* iSword = new item();
  strcpy(iSword->itemName, "Sword");
  rBlacksmith->setItem(iSword);
  item* iJewel = new item();
  strcpy(iJewel->itemName, "Jewel");
  rDungeon->setItem(iJewel);
  item* iCross = new item();
  strcpy(iCross->itemName, "Cross");
  rChapel->setItem(iCross);
  
  //Setting exits
  //Create map
  map<char*, room*>* zmap = new map<char*, room*>(); 
  //Insert exits
  //Van
  zmap->insert(pair<char*, room*>("NORTH", rOutside));
  rVan->setExit(zmap);
  zmap = new map<char*, room*>();
  //Outside
  zmap->insert(pair<char*, room*>("SOUTH", rVan));
  rOutside->setExit(zmap);
  zmap->insert(pair<char*, room*>("NORTH", rEntry));
  rOutside->setExit(zmap);
  zmap->insert(pair<char*, room*>("EAST", rStable));
  rOutside->setExit(zmap);
  zmap->insert(pair<char*, room*>("WEST", rShed));
  rOutside->setExit(zmap);
  zmap = new map<char*, room*>();
  //Shed
  zmap->insert(pair<char*, room*>("EAST", rOutside));
  rShed->setExit(zmap);
  zmap = new map<char*, room*>();
  //Stable
  zmap->insert(pair<char*, room*>("WEST", rOutside));
  rStable->setExit(zmap);
  zmap = new map<char*, room*>();
  //Entry
  zmap->insert(pair<char*, room*>("SOUTH", rOutside));
  rEntry->setExit(zmap);
  zmap->insert(pair<char*, room*>("NORTH", rThroneroom));
  rEntry->setExit(zmap);
  zmap->insert(pair<char*, room*>("EAST", rLibrary));
  rEntry->setExit(zmap);
  zmap->insert(pair<char*, room*>("WEST", rKitchen));
  rEntry->setExit(zmap);
  zmap = new map<char*, room*>();
  //Library
  zmap->insert(pair<char*, room*>("WEST", rEntry));
  rLibrary->setExit(zmap);
  zmap->insert(pair<char*, room*>("NORTH", rChapel));
  rLibrary->setExit(zmap);
  zmap->insert(pair<char*, room*>("EAST", rCellar));
  rLibrary->setExit(zmap);
  zmap = new map<char*, room*>();
  //Cellar
  zmap->insert(pair<char*, room*>("WEST", rLibrary));
  rCellar->setExit(zmap);
  zmap = new map<char*, room*>();
  //Chapel
  zmap->insert(pair<char*, room*>("SOUTH", rLibrary));
  rChapel->setExit(zmap);
  zmap->insert(pair<char*, room*>("WEST", rThroneroom));
  rChapel->setExit(zmap);
  zmap = new map<char*, room*>();
  //Throneroom
  zmap->insert(pair<char*, room*>("SOUTH", rEntry));
  rThroneroom->setExit(zmap);
  zmap->insert(pair<char*, room*>("EAST", rChapel));
  rThroneroom->setExit(zmap);
  zmap->insert(pair<char*, room*>("NORTH", rTreasure));
  rThroneroom->setExit(zmap);
  zmap = new map<char*, room*>();
  //Treasure room
  zmap->insert(pair<char*, room*>("SOUTH", rThroneroom));
  rTreasure->setExit(zmap);
  zmap->insert(pair<char*, room*>("WEST", rBlacksmith));
  rTreasure->setExit(zmap);
  zmap = new map<char*, room*>();
  //Blacksmith
  zmap->insert(pair<char*, room*>("EAST", rTreasure));
  rBlacksmith->setExit(zmap);
  zmap->insert(pair<char*, room*>("NORTH", rQuarry));
  rBlacksmith->setExit(zmap);
  zmap = new map<char*, room*>();
  //Quarry
  zmap->insert(pair<char*, room*>("SOUTH", rBlacksmith));
  rQuarry->setExit(zmap);
  zmap = new map<char*, room*>();
  //Kitchen
  zmap->insert(pair<char*, room*>("EAST", rEntry));
  rKitchen->setExit(zmap);
  zmap->insert(pair<char*, room*>("NORTH", rPantry));
  rKitchen->setExit(zmap);
  zmap->insert(pair<char*, room*>("WEST", rDungeon));
  rKitchen->setExit(zmap);
  zmap = new map<char*, room*>();
  //Pantry
  zmap->insert(pair<char*, room*>("SOUTH", rKitchen));
  rPantry->setExit(zmap);
  zmap = new map<char*, room*>();
  //Dungeon
  zmap->insert(pair<char*, room*>("EAST", rKitchen));
  rDungeon->setExit(zmap);
  zmap = new map<char*, room*>();
  
  //Game loop
  while (playing == true) {
    char input[10];
    //Tell the player where they are and what commands they can use
    cout << "You are currently in the " << currentRoom->roomName << ". " << currentRoom->Description << endl;
    cout << "Exits: " << endl;
    currentRoom->printExits();
    cout << "Items: " << endl;
    currentRoom->getItems();
    cout << "Type in an exit to go in that room, GET or DROP to pick up or drop an item, INVENTORY to check your inventory, HELP for help, or QUIT to quit." << endl;
    cin.get(input, 10);
    cin.ignore();
    cin.clear();
    //DIRECTION
    if (strcmp(input, "NORTH") == 0 || strcmp(input, "EAST") == 0 || strcmp(input, "SOUTH") == 0 || strcmp(input, "WEST") == 0) {
      //Create iterator
      map<char*, room*>::iterator it;
      //Go through exits and check if it matches input
      for (it = currentRoom->exits->begin(); it != currentRoom->exits->end(); it++) {
	//If the input matches an exit
	if (strcmp(it->first, input)==0) {
	  //Change the current room
	  currentRoom = it->second;
	  break;
	}
      }
    }
    //GET
    if  (strcmp(input, "GET")==0) {
      //Ask which item they want to get
      cout << "Which item? " << endl;
      char itemInput[20];
      cin.get(itemInput, 20);
      cin.ignore();
      //Create an iterator to go through the item vector in the room
      vector<item*>::iterator it;
      for (it = currentRoom->backItems()->begin(); it != currentRoom->backItems()->end(); it++) {
	//If the inputted item matches an item in the vector
	if (strcmp((*it)->itemName, itemInput)==0) {
	  //Add the item to the inventory vector
	  i->push_back(*it);
	  //Remove the item from the room
	  currentRoom->backItems()->erase(it);
	  break;
	}
	else {
	  cout << "That item is not here! \n" << endl;
	  break;
	}
      }
    }
    //DROP
    if (strcmp(input, "DROP")==0) {
      //Ask which item they want to drop
      cout << "Which item?" << endl;
      char itemInput[20];
      cin.get(itemInput, 20);
      cin.ignore();
      //Create an iterator to go through the inventory vector
      vector<item*>::iterator it;
      for (it = i->begin(); it != i->end(); it++) {
	//If the inputted item matches an item in the inventory
	if (strcmp((*it)->itemName, itemInput)==0) {
	  //Add the item to the room vector
	  currentRoom->roomItem->push_back(*it);
	  //Remove the item from the inventory vector
	  i->erase(it);
	  break;
	}
	else {
	  cout << "That item isn't in your inventory! \n" << endl;
	}
      }
    }
    //INVENTORY
    if (strcmp(input, "INVENTORY")==0) {
      cout << "Inventory:" << endl;
      //Create an interator to go through the array
      vector<item*>::iterator it;
      for (it = i->begin(); it != i->end(); it++ ) {
	//Print out the items in the vector
	cout << (*it)->itemName << endl;
      }
    }
    //HELP
    if (strcmp(input, "HELP")==0) {
      cout << "You have come to a castle in search of treasure. Bring back all valuable items to your van to win!" << endl;
    }
    //QUIT
    if (strcmp(input, "QUIT") == 0) {
      playing = false;
    }
    //WINNING CONDITION
    if(playing == true) {
      //Checks for the 5 different items in rVan
      bool check1 = false;
      bool check2 = false;
      bool check3 = false;
      bool check4 = false;
      bool check5 = false;
      //Iterator to go through item vector in rVan
      vector<item*>::iterator it;
      for (it = rVan->backItems()->begin(); it != rVan->backItems()->end(); it++) {
	//Check if each item exists in the roomItem vector for rVan
	if (strcmp((*it)->itemName, "Book")  == 0) {
	  check1 = true;
	}
	if (strcmp((*it)->itemName, "Crown") == 0) {
	  check2 = true;
	}
	if (strcmp((*it)->itemName, "Jewel") == 0) {
	  check3 = true;
	}
	if (strcmp((*it)->itemName, "Cross") ==0) {
	  check4 = true;
	}
	if (strcmp((*it)->itemName, "Sword") == 0) {
	    check5 = true;
	}
	//If rVan has all 5 items
	if (check1 == true && check2 == true && check3 == true && check4 == true && check5 == true) {
	  cout << "Congratulations! You have found all of the treasure in the castle! " << endl;
	  cout << "You drive off into the night, in search of new treasures once again" << endl;
	  playing = false;
	}
      }
    }
  }
}
  
