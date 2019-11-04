#include<stdlib.h>
#include<stdio.h>
#include "items.h"
struct Room {

  char *description;
  struct Item *items;
  struct Room *north, *south, *east, *west, *up, *down;
};

struct Room * room (char* description, struct Item* items, struct Room *north, struct Room *south, struct Room *east, struct Room *west, struct Room *up, struct Room *down) {

  struct Room *room = (struct Room *)malloc(sizeof(struct Room));
  room->description = description;
  room->items = items;
  room->north = north;
  room->south = south;
  room->east = east;
  room->west = west;
  room->up = up;
  room->down = down;
  return room;
};

void room_exit_north(struct Room* current, struct Room* other) {
  if(current == NULL){
    return;
  }
  current->north = other;
}

void room_exit_south(struct Room* current, struct Room* other) {
  if(current == NULL){
    return;
  }
  current->south = other;
}

void room_exit_east(struct Room* current, struct Room* other) {
  if(current == NULL){
    return;
  }
  current->east = other;
}

void room_exit_west(struct Room* current, struct Room* other) {
  if(current == NULL){
    return;
  }
  current->west = other;
}
void room_exit_up(struct Room* current, struct Room* other){
    if(current == NULL){
        return;
    }
    current->up = other;
}
void room_exit_down(struct Room* current, struct Room* other){
    if(current == NULL){
        return;
    }
    current->down = other;
}