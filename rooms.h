#ifndef __ROOMS_H
#define __ROOMS_H
#include "items.h"
struct Room {

  char *description;
  struct Item *items;
  struct Room *north, *south, *east, *west, *up, *down;
};

struct Room * room (char* description, struct Item* items, struct Room *north, struct Room *south, struct Room *east, struct Room *west, struct Room *up, struct Room *down);

void room_exit_north(struct Room* current, struct Room* other);
void room_exit_south(struct Room* current, struct Room* other);

void room_exit_east(struct Room* current, struct Room* other);

void room_exit_west(struct Room* current, struct Room* other);
void room_exit_up(struct Room* current, struct Room* other);
void room_exit_down(struct Room* current, struct Room* other);

#endif