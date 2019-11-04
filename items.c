#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define width 32
#define length 32





struct Item{
  char *nm;
  char *desc;
  struct Item *next;
};

struct Item *item(char *name, char *description, struct Item *link){
  struct Item *i=(struct Item *)malloc(sizeof(struct Item));
  i->nm=name;
  i->desc=description;
  i->next=link;
  return i;
}

char *item_name(struct Item *i){
  return i->nm;
}

char *item_description(struct Item *i){
  return i->desc;
}

struct Item *item_next(struct Item *i){
  return i->next;
}

struct Item *item_take(struct Item *i, char *name){
  if(strcmp(i->nm, name)==0){
      struct Item *t=i;
      i=i->next;
      return t;
  }
  for(struct Item *ptr=i; ptr->next!=NULL;ptr=ptr->next){
    if(strcmp(ptr->next->nm, name)==0){
      struct Item *temp=ptr->next;
      ptr->next=ptr->next->next;
      return temp;
    }
  }
  return NULL;
}