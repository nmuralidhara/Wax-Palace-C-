#ifndef __ITEMS_H
#define __ITEMS_H
struct Item{
  char *nm;
  char *desc;
  struct Item *next;
};

struct Item *item(char *name, char *description, struct Item *link);

char *item_name(struct Item *i);

char *item_description(struct Item *i);

struct Item *item_next(struct Item *i);

struct Item *item_take(struct Item *i, char *name);
  
#endif