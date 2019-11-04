#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "items.h"
#include "rooms.h"
#define width 32
#define length 32

//we are going to represent all the rooms, items in the form a grid board.
//*ci & *cj are the coordinates of the avatar
//*ki & *kj are the coordinates of the psychokiller

//We have a combination of pointers & arrays. Mainly arrays are just length 1 to store the status of object. 

//For this, we need a structure to hold the position of every room with respect to the grid

struct positionInBoard{
   int i1,i2,j1,j2;
};

//returns a random number. This is needed for the movement of psychokiller which is random since he teleports(he is a ghost)

int rando(void){
   return rand()%31+1;
}

//function to initialize grid, rooms, items, doors, and walls

void initializeBoard(char board[length][width], struct room *r[9], struct positionInBoard pos[8]){
  for(int i=0;i<length;i++){
    for(int j=0;j<20;j++){
      board[i][j]=',';     //',' represents thick wax. If avatar steps on it, the psychokiller will hear him and kill him
    }
  }
  
  for(int i=0;i<length;i++){
      for(int j=20;j<width;j++){
          board[i][j]='.';  //'.' represents thin wax. Avatar is safe if he steps on it.
      }
  }

  for(int i=0;i<length;i++){
    board[i][0]='X';
    board[i][width-1]='X';  //Create walls for the boundary of the mansion
  }

  for(int j=0;j<width;j++){
    board[0][j]='X';
    board[length-1][j]='X';  //Create walls for the boundary of the mansion
  }



  //create 11 rooms along with their items and descriptions

  r[0] = room("You are now in the psychokiller's storeroom. This is your ultimate chance to save your friend. Hurry up before it is too late", item("Map", "Leads to underground basement by making magical door appear", NULL), NULL, NULL, NULL, NULL, NULL, NULL);

  r[1]=room("You are now in the psychokiller's room. Beware. Dollar chain is your saviour. Use it wisely.", item("Candle","Summons psychokiller so that you can kill him.",NULL), NULL, NULL, NULL, NULL, NULL, NULL);

  r[2] = room("You are now in the doctor's storeroom. Here you will find things to save as well as to kill", item("SpecialKnife","cannot use me unless...",item("Paper","Killer uses my friend's body. Sacred Mirror + Knife= Salvation", item("Medikit"," Heals whoever you use it on",NULL))), NULL, NULL, NULL, NULL, NULL, NULL);
    
  r[3] = room("You are now in the Doctor's room. Green is for life & green is the color of the walls. Go green ... Go music", item("Flute", "Text Written: Playing will help playing",NULL), NULL, NULL, NULL, NULL, NULL, NULL);

  r[4] = room("This is the sacred storeroom. Your best friend is here. Don't mind the mushy walls.", item("DollarChain","Necklace which prevents the killer from killing you. Text written:rungNUM 'pasBER'" ,NULL), NULL, NULL, NULL, NULL, NULL, NULL);

  r[5] = room("This is the sacred room. Mirrors mirrors mirrors everywhere. Hall of mirrors actually.", item("Book", "Front Side: There is a ghost of the great King Rungnum Pasber in this palace. If you are reading this, please help him for salvation. His father will be waiting for him in heaven.\n BackSide:Caps don't lock they open. Chain is the gain. Text in chain is the key. Candle does not burn, it sticks.", item("Cap", "RUNGnum PASber", NULL)), NULL, NULL, NULL, NULL, NULL, NULL);

  r[6] = room("Here is the visitor's storeroom where you have hidden away your friend for safety", NULL, NULL, NULL, NULL, NULL, NULL, NULL);

  r[7] = room("Here is the visitor's room. Multicolored room decorated with sofas & a deadly villain is lurking out in the mansion", item("Lighter","Melts thick wax to thin wax",NULL), NULL, NULL, NULL, NULL, NULL, NULL);

  r[8] = room("This is the hallway. Very colossal. Careful about the thick wax. Nice painting though.", item("Painting", "Depicts psychokiller's father wearing dollar chain",NULL),NULL, NULL, NULL, NULL, NULL, NULL);
  
  struct room* attic = room("Dark top most room", NULL, NULL, NULL, NULL, NULL, NULL, NULL);
  struct room* basement = room("Scary underground creepy room", NULL, NULL, NULL, NULL, NULL, NULL, NULL);

  //connect all the rooms according to their allignment.

  room_exit_east(r[0], r[1]);
  room_exit_west(r[1], r[0]);
  
  room_exit_east(r[1], r[8]);
  room_exit_west(r[8], r[1]);
  
  room_exit_east(r[2], r[3]);
  room_exit_west(r[3], r[2]);
  
  room_exit_south(r[3], r[8]);
  room_exit_north(r[8], r[3]);
  
  room_exit_north(r[4], r[8]);
  room_exit_south(r[8], r[4]);
  
  room_exit_east(r[4], r[5]);
  room_exit_west(r[5], r[4]);
  
  room_exit_east(r[5], r[8]);
  room_exit_west(r[8], r[5]);
  
  room_exit_east(r[6], r[7]);
  room_exit_west(r[7], r[6]);
  
  room_exit_north(r[7], r[8]);
  room_exit_south(r[8], r[7]);
  
  room_exit_up(r[7], attic);
  room_exit_down(attic, r[7]);
  
  room_exit_down(r[0], basement);
  room_exit_up(basement, r[0]);
  
   
  //set positions and dimensions of every room with respect to the board
  
  pos[0].i1=0;
  pos[0].i2=11;
  pos[0].j1=0;
  pos[0].j2=5;

  
  pos[1].i1=0;
  pos[1].i2=11;
  pos[1].j1=6;
  pos[1].j2=11;

  


  pos[2].i1=0;
  pos[2].i2=11;
  pos[2].j1=20;
  pos[2].j2=25;

  
  pos[3].i1=0;
  pos[3].i2=11;
  pos[3].j1=26;
  pos[3].j2=31;

  


  pos[4].i1=20;
  pos[4].i2=31;
  pos[4].j1=0;
  pos[4].j2=5;

  

  pos[5].i1=20;
  pos[5].i2=31;
  pos[5].j1=6;
  pos[5].j2=11;

  pos[6].i1=20;
  pos[6].i2=31;
  pos[6].j1=20;
  pos[6].j2=25;

  pos[7].i1=20;
  pos[7].i2=31;
  pos[7].j1=26;
  pos[7].j2=31;


  for(int k=0;k<4;k++){
    for(int i=pos[k].i1;i<pos[k].i2;i++){
      board[i][pos[k].j2]='X';                   //Create vertical walls for the room k<=4
    }
    for(int j=pos[k].j1;j<pos[k].j2;j++){
      board[pos[k].i2][j]='X';                   //Create horizontal walls for room k<=4
    }
    board[pos[k].i2][pos[k].j2]='X';             //Put a wall in the corner
  }

  for(int k=4;k<8;k++){
    for(int i=pos[k].i1;i<pos[k].i2;i++){
      
      board[i][pos[k].j2]='X';                   //Create vertical walls for the room k>=4
    }
    for(int j=pos[k].j1;j<pos[k].j2;j++){
      board[pos[k].i1][j]='X';                   //Create horizontal walls for room k>=4
    }
    board[pos[k].i2][pos[k].j2]='X';             //Put a wall in the corner
  }


  for(int i=pos[2].i1;i<pos[2].i2;i++){
    board[i][pos[2].j1]='X';                   //Put walls on left of room 2
  }

  for(int i=pos[6].i1;i<pos[6].i2;i++){
    board[i][pos[6].j1]='X';                   //Put walls on left of room 6
  }

  
  //create doors which separate two rooms. They may be locked or unlocked depending on state of game

  board[(pos[0].i1 + pos[0].i2)/2][pos[0].j2]='|';
  board[(pos[0].i1 + pos[0].i2)/2 + 1][pos[0].j2]='|';

  board[(pos[1].i1 + pos[1].i2)/2][pos[1].j2]='-';
  board[(pos[1].i1 + pos[1].i2)/2 + 1][pos[1].j2]='-';

  board[pos[3].i2][(pos[3].j1 + pos[3].j2)/2]='|';
  board[pos[3].i2][(pos[3].j1 + pos[3].j2)/2 + 1]='|';

  board[(pos[2].i1 + pos[2].i2)/2][pos[2].j2]='|';
  board[(pos[2].i1 + pos[2].i2)/2 + 1][pos[2].j2]='|';

  board[(pos[5].i1 + pos[5].i2)/2][pos[5].j2]='-';
  board[(pos[5].i1 + pos[5].i2)/2 + 1][pos[5].j2]='-';

  board[(pos[4].i1 + pos[4].i2)/2][pos[4].j2]='|';
  board[(pos[4].i1 + pos[4].i2)/2 + 1][pos[4].j2]='|';

  board[pos[7].i1][(pos[7].j1 + pos[7].j2)/2]='|';
  board[pos[7].i1][(pos[7].j1 + pos[7].j2)/2 + 1]='|';

  board[(pos[6].i1 + pos[6].i2)/2][pos[6].j2]='|';
  board[(pos[6].i1 + pos[6].i2)/2 + 1][pos[6].j2]='|';

  board[length/2][width-1]='|';
  board[length/2 - 1][width-1]='|';
  
  board[pos[6].i1 + 2][pos[6].j1 + 2]='F';     //Friend is in room 6 injured by the psychokiller
  
  return pos;              //always we return the structure containing room positions with respect to board. This is needed during actual game play
}


//prints the current state of the board

void printBoard(char board[length][width]){
  for(int i=0;i<width;i++){
      for(int j=0;j<length;j++){
        printf("%c ", board[i][j]);
      }
      printf("\n");
    }
}


//checks if player is on thick wax. If yes, return 1 else return 0. 

int checkThickWax(char board[length][width],int *ci, int *cj){

    if(board[*ci][*cj]==','){  //',' is thick wax
        return 1;
    }
    return 0;
}

//if player uses lighter, then this function will get called and thick wax gets converted to thin wax.

void convertThickToThin(char board[length][width],int *ci, int *cj){



        for(int i=-9;i<10;i++){
            for(int j=-9;j<10;j++){    //radius of 5 melting thick to thin wx
                if(*ci+i<0 || *cj+j<0 || *ci+i>=length || *cj+j>=width){
                    continue; //if not valid index skip to next iteration
                    
                }
                if(board[*ci+i][*cj+j]=='P' || board[*ci+i][*cj+j]=='F' || board[*ci+i][*cj+j]=='K' || board[*ci+i][*cj+j]=='X' || board[*ci+i][*cj+j]=='-' || board[*ci+i][*cj+j]=='|'){
                    continue; //do not overwrite wall, doors, player, or killer
                }
                board[*ci+i][*cj+j]='.';  //'.' is thin wax
            }
        }
}






void openDoor(char board[length][width], int firstDoorI, int firstDoorJ, char allignment){
    int secondDoorI, secondDoorJ;   //find where second door is
    switch(allignment){
        case '-':
        secondDoorI=firstDoorI;    //here i coordinate of second door is same as first
        if(board[firstDoorI][firstDoorJ-1]==allignment){
            secondDoorJ=firstDoorJ-1;    //door is on the left
        }
        
        else{
            secondDoorJ=firstDoorJ+1;     //door is on the right
        }
        board[firstDoorI][firstDoorJ]='|';
        board[secondDoorI][secondDoorJ]='|';      //opened both
        printf("Door is now open!\n");
        break;
        
        case '|':
        secondDoorJ=firstDoorJ;    //here j coordinate of second door is same as first
        if(board[firstDoorI-1][firstDoorJ]==allignment){
            secondDoorI=firstDoorI-1;    //door is above
        }
        
        else{
            secondDoorI=firstDoorI+1;     //door is below
        }
        board[firstDoorI][firstDoorJ]='-';
        board[secondDoorI][secondDoorJ]='-';    //opened both
        printf("Door is now open!\n");
        break;
    }
}



//if knife is activated for more than 20 minutes, then knife gets inactivated

void updateKnifeStatus(int knifeMove[1],int knifeStatus[1]){
    if(knifeMove[0]>=20){
        knifeStatus[0]=0;     //inactivate knife
        knifeMove[0]=0;     //reset counter
        printf("Knife is inactivated! Please activate again!\n");
    }
}

//after every 20 moves, friend's life decreases

void updateFriendStatus(int friendsMove[1],int friendsLife[1]){
    if(friendsMove[0]>=20){
         friendsLife[0]=friendsLife[0]-1;
         friendsMove[0]=0;
         printf("Friend lost some health! Please help him before he dies.\n");
    }
}


//Once avatar has candle, he can lure the psychokiller where upon he has a chance to kill him if he is also wearing the dollar chain

void placingCandle(char board[length][width],int *ci,int *cj,int *ki,int *kj, int candleStatus[1]){
int j;
int a; int b;
/*
printf("Where do you want to place?\n");
scanf("%i",&j);      //decide where to place the candle
switch(j){
case 1:a=*ci-1; b=*cj;
       board[*ci-1][*cj]='+';
case 2: a=*ci; b=*cj+1;
       board[*ci][*cj+1]='+';
case 3: a=*ci+1; b=*cj;
       board[*ci+1][*cj]='+';
case 4: a=*ci; b=*cj-1;
       board[*ci][*cj-1]='+';
}
printBoard(board);
*/
int call;
printf("Do you want to call the killer? Enter 1/2 respectively for yes or no\n");
scanf("%i",&call);  
if(call==1){  //if yes
candleStatus[0]=1;
board[*ki][*kj]='.';   //move killer from current spot and replace with thin wax
*ki=*ci-1;
*kj=*cj;
board[*ki][*kj]='K';    //new position of killer
}
}

//function which returns 1 if the radial distance between killer and avatar is 1 unit. Returns 0 otherwise.

int isNearby(int *ki, int *kj, int*ci, int*cj){
    if(abs(*ki-*ci)<=1 && abs(*kj-*cj)<=1){
        return 1;
    }
    return 0;
}



//function which determines what happens if player wants to use item

void useItem(char board[length][width], char command[10],int *ci, int*cj, int *ki, int*kj, struct Item *inventory,int roomPosition[1],int knifeStatus[1],int knifeMove[1],int friendsMove[1],int dollarStatus[1],int friendsLife[1], int killerStatus[1], int candleStatus[1]){

//first check if item is there in the inventory

int itemPresent=0;
for(struct Item *ptr=inventory;ptr!=NULL;ptr=ptr->next){
    if(strcmp(command,ptr->nm)==0){
        itemPresent=1;
        break;
    }
}
if(itemPresent==0){
    printf("Sorry, item is not there in your inventory");
    return; //do not proceed further
}


//if flute is used in third room, open door to second room

if(strcmp(command,"Flute")==0&& roomPosition[0]==3){
//opens the door 
   printf("Flute is played\n");
   openDoor(board,5,25,'|');

}

//if lighter is used convert thick wax to thin wax

else if(strcmp(command,"Lighter")==0){

    convertThickToThin(board,ci,cj);

}

//if medikit is used, revive friend

else if(strcmp(command,"Medikit")==0&&roomPosition[0]==7){
friendsLife[0]=5;
friendsMove[0]=0;
}

//open friend's door
else if(strcmp(command, "Key")==0 && roomPosition[0]==7){
     openDoor(board, 25, 25, '|');
}
else if(strcmp(command,"Cap")==0&&roomPosition[0]==5){
    printf("Enter passcode to get in to next room\n");
    char passcode[20];
    scanf("%s",passcode);
    if (strcmp("RUNGPAS", passcode)==0){
        printf("Correct!\n");
        openDoor(board,25,5,'|');
    }
    else{
        printf("Incorrect!\n");
    }
}

else if(strcmp(command,"SpecialKnife")==0){
int ch;
printf("Do you want to turn it on or use it to kill? Press 1 / 2 respectively\n");
scanf("%i",&ch);
if(ch==1&&roomPosition[0]==5){
knifeStatus[0]=1;
knifeMove[0]=0;
}


else if(ch==2){
    if(dollarStatus[0]==1 && isNearby(ki,kj,ci,cj)==1 && knifeStatus[0]==1){
        printf("You have killed the killer.\n");
        killerStatus[0]=0;
    }
    else {
        printf("Sorry missed the killer!\n");
    }
}
} 
else if(strcmp(command,"DollarChain")==0){
    int useDC;
    printf("Do you wanna wear it or use it to open door? Enter 1 / 2 respectively\n");
    scanf("%i",&useDC);
    if(useDC==1){
        dollarStatus[0]=1;
        printf("Chain is worn by you\n");
    }
    else if(useDC==2 && roomPosition[0]==2){
        printf("Enter code for opening door\n");
        int code;
        scanf("%i",&code);
        if(code==161192518){
            openDoor(board,5,5,'|');
        }
    }
    
} 
else if(strcmp(command,"Candle")==0){ 
placingCandle(board,ci,cj,ki,kj, candleStatus);
} 
else if(strcmp(command,"Map")==0){
board[25][28]='#';        //underground door

} 

}



//c1 is avatar's i-coordinate
//c2 is avatar's j-coordinate

//checks for obstacles in the avatar's path. If there is door or wall in the way, return 0 else return 1. We also count the number of times avatar steps on thick wax

int checkObstacles(char board[length][width],int *c1,int *c2,int ans1,int ans2, int *countThickWax){
  
  switch(ans1){
    case 1:
    
    for(int i=*c1;i>=*c1-ans2;i--){
      if(board[i][*c2]=='-'){      //door check
        printf("Cannot move there since door is locked. Please open it!\n");
        return 0;
      }
      if(board[i][*c2]=='X'){     //wall check
        printf("There is a wall in your path! Try again!\n");
        return 0;
      }
      
      
    }
    for(int i=*c1;i>=*c1-ans2;i--){
        if(board[i][*c2]==','){
            (*countThickWax)++;   //count
        }
    }
    return 1;
    case 3:
    for(int i=*c1;i<=*c1+ans2;i++){
      if(board[i][*c2]=='-'){     //door check
        printf("Cannot move there since door is locked. Please open it!\n");
        //openDoor(board,i,*c2,'-');
        return 0;
      }
       if(board[i][*c2]=='X'){    //wall check
        printf("There is a wall in your path! Try again!\n");
        return 0;
      }
      
    }
    for(int i=*c1;i<=*c1+ans2;i++){
        if(board[i][*c2]==','){
            (*countThickWax)++;   //count
        }
    }
    return 1;
    case 2:
    for(int j=*c2;j<=*c2+ans2;j++){
      if(board[*c1][j]=='X'){    //wall count
        printf("There is a wall in your path! Try again!\n");
        return 0;
      }
       if(board[*c1][j]=='|'){     //door check
        printf("Cannot move there since door is locked. Please open it!\n");
        //openDoor(board,*c1,j,'|');
        return 0;
      }
      
    }
    for(int j=*c2;j<=*c2-ans2;j++){
        if(board[*c1][j]==','){
            (*countThickWax)++;     //count
        }
    }
    return 1;
    
    case 4:
    for(int j=*c2;j>=*c2-ans2;j--){
      if(board[*c1][j]=='X'){     //wall check
        printf("There is a wall in your path! Try again!\n");
        return 0;
      }
    
     if(board[*c1][j]=='|'){      //door check
      //  printf("hi!\n");
        printf("Cannot move there since door is locked. Please open it!\n");
        //openDoor(board,*c1,j,'|');
        return 0;
      }
      
    }
    for(int j=*c2;j>=*c2-ans2;j--){
        if(board[*c1][j]==','){
            (*countThickWax)++;     //count
        }
    }
  return 1;
  default:
  return 1;
}
}


//function to play avatar's move. 5 options: look, go, take, use, drop. We return inventory.

struct Item* movePlayer(char board[length][width],int *ci, int *cj,int *ki, int*kj,struct Item* playerInventory, int currentRoom[1], struct positionInBoard pos[8], struct Room *r[9],int knifeStatus[1],int knifeMove[1],int friendsMove[1],int dollarStatus[1],int friendsLife[1], int *countThickWax, int killerStatus[1], int candleStatus[1]){

  printf("It's your turn! What do you want to do? Options:\n 1. look\n 2. go \n 3. take\n 4. use\n 5. drop\n");
  int ans,ans1,ans2;
  scanf("%i", &ans);
  while(ans<1 && ans>5){   //keep taking ans until valid choice
    printf("Invalid choice. Re-enter!-_- \n");
    scanf("%i", &ans);   
  }
  
  if(ans==1){                      //prints items in the room
      printf("Looking ... \n");
      for(struct Item *ptr=r[currentRoom[0]]->items;ptr!=NULL;ptr=item_next(ptr)){
          printf("%s : %s\n", item_name(ptr), item_description(ptr));
      }
  }
  
  
  
  if(ans==2){                   //go in that direction a certain number of steps
  do{
    printf("Choose direction\n1. North\n2. East\n3. South\n4. West\n5. Up\n6. Down\n");
    scanf("%i", &ans1);
    printf("Press steps\n");
    scanf("%i", &ans2);
    switch(ans1){                         //always check for validity of new index. The new path should be obstacle free. Current position of avatar should be replaced by '.'
      case 1:                             //north
        if(*ci-ans2<0){
          printf("Cannot move there!\n");
        }        
        else if(checkObstacles(board, ci, cj, ans1, ans2, countThickWax)==1 && currentRoom[0]>=0){
          board[*ci][*cj]='.';
          *ci=*ci-ans2;
          
          
        }
        break;
      case 2:                           //east
        if(*cj+ans2>=width){
          printf("Cannot move there!\n");
        }
        else if(checkObstacles(board, ci, cj, ans1, ans2, countThickWax)==1){
          board[*ci][*cj]='.';
          *cj=*cj+ans2;
          
          
        }
        break;
      case 3:                           //south
        if(*ci+ans2>=length){
          printf("Cannot move there!\n");
        }
        else if(checkObstacles(board, ci, cj, ans1, ans2, countThickWax)==1){
          board[*ci][*cj]='.';
          *ci=*ci+ans2;
          
          // curI=&ci;
          // curJ=&cj;
        }
        break;
      case 4:                           //west
        if(*cj-ans2<0){
          printf("Cannot move there!\n");
        }
        else if(checkObstacles(board,ci, cj, ans1, ans2, countThickWax)==1){
          board[*ci][*cj]='.';
          *cj=*cj-ans2;
          
          // curI=&ci;
          // curJ=&cj;
        }
        break;

	//For currentRoom[0], -1 is attic and -2 is basement 
	
        case 5:
        if(currentRoom[0]==-1){               //attic topmost floor
            printf("Already in the attic!\n");
        }
        else if(currentRoom==-2){
            currentRoom[0]=7;
            printf("You are now on the ground floor!\n");
        }
        else{
            printf("You are now in the attic!\n");
            currentRoom[0]=-1;
        }
        
        case 6:
        if(currentRoom[0]==-2){                     //basement is top most
            printf("Already in the basement!\n");
        }
        else if(currentRoom==-1){
            currentRoom[0]=7;
            printf("You are now on the ground floor!\n");
        }
        else{
            printf("You are now in the basement!\n");
            currentRoom[0]=-2;
        }
        
      default:
        printf("Invalid direction select again!\n");
    }
    //Find out the new room the avatar is in
       if(currentRoom[0]>=0){                               //as long as I am not in attic or basement
            currentRoom[0]=8;                               //if for loop fails, avatar must be in hallway
            for(int m=0;m<8;m++){
            if(*ci>=pos[m].i1 && *ci<=pos[m].i2 && *cj>=pos[m].j1 && *cj<=pos[m].j2){  //range check
               currentRoom[0]=m;
            }
        }
    }
  
  int flag=checkThickWax(board, ci, cj);             //flag for checking if avatar stepped on thick wax
  board[*ci][*cj]='P';                                //place avatar in new position

  }while(ans1!=1 && ans1!=2 && ans1!=3 && ans1!=4 && ans1!=5 && ans1!=6);  // checking for invalid choice
  
 }
  
  
  if(ans==3){   //take item
      printf("Select which item to take! Enter below:\n");
      char ans3[50];
      scanf("%s",ans3);
      struct Item *newItem=item_take(r[currentRoom[0]]->items,ans3);   //take requested item if there
      if(newItem==r[currentRoom[0]]->items){
          r[currentRoom[0]]->items=r[currentRoom[0]]->items->next;      //edge case for head of linked list removal
      }
      for(struct Item *ptr=r[currentRoom[0]]->items;ptr!=NULL && ptr->next!=NULL;ptr=ptr->next){
          if(ptr->next==newItem){
              ptr->next=ptr->next->next;                                //delete the item from the room list
          }
      }
      if (newItem!=NULL){
          printf("Item added successfully to inventory!\n");
          playerInventory=item(newItem->nm,newItem->desc,playerInventory);   //add to inventory
      }
      else{ 
	   printf("Item not found in the room!\n");
      }
    
  }
  if (ans==4){  //use
       printf("Select which item to use:\n");
        char answer[50];
          scanf("%s", answer);
      //pass item to useItem and use it if there in inventory
       useItem(board,answer,ci,cj, ki,kj, playerInventory,currentRoom, knifeStatus,knifeMove,friendsMove,dollarStatus,friendsLife, killerStatus, candleStatus);   
       
  }
  
  if(ans==5){      //drop
      printf("Select which item to drop:\n");
          char ans5[50];
          scanf("%s", ans5);
          struct Item *dropped=NULL;
          if(strcmp(ans5, playerInventory->nm)==0){    //check head of inventory linked list and drop it
              dropped=playerInventory;
              playerInventory=playerInventory->next;
          }
          for(struct Item *ptr=playerInventory;ptr!=NULL && ptr->next!=NULL;ptr=ptr->next){
            if(strcmp(ptr->next->nm, ans5)==0){       //check rest of inventory
              printf("fgh");
              dropped=ptr->next;
              ptr->next=ptr->next->next;
              break;
            }
          }
          //put the dropped item back in the room
          if(dropped!=NULL){
             printf("Dropped successfully!\n");
             r[currentRoom[0]]->items=item(dropped->nm, dropped->desc, r[currentRoom[0]]->items);
          }

          else{
	     printf("Sorry! Item does not exist in the inventory!\n");
          }
          
      
  }
  return playerInventory;
  
}

//killer's move is completely random achieved by generating random numbers

void moveKiller(char board[length][width], int *ki, int *kj, int candleStatus[1]){
    if(candleStatus[0]==1){
       return;
    }
    board[*ki][*kj]='.';
    do{
        *ki=rando();
        *kj=rando();
    }while(board[*ki][*kj]=='X' || board[*ki][*kj]=='|' || board[*ki][*kj]=='-' || board[*ki][*kj]=='F');  //generate again if invalid index
    board[*ki][*kj]='K';
}





//determines if game is over, -1 means loss, +1 means victory, 0 means game is still in play
int gameOver(int friendsLife[1], int killerStatus[1], int *countThickWax, int didWeWin[0]){
    if(friendsLife[0]==0 || *countThickWax>0){   // if friend is dead or avatar stepped on thick wax, we lose
        didWeWin[0]=-1;
        return -1;//loss
    }
    if(killerStatus[0]==0){                 //if we kill psychokiller, we win
        didWeWin[0]=1;
        return 1;//victory
    }
    return 0; //game still in play
}


void printInventory(struct Item *inventory){
   printf("The things in your inventory are\n");
   for(struct Item* ptr=inventory;ptr!=NULL;ptr=ptr->next){
      printf("%s:  %s\n", ptr->nm, ptr->desc);
   }
}

int main(void){
  char board[length][width];      // grid representation of rooms
  int curI=25;                    //starting i-pos of avatar
  int curJ=26;                    //starting j-pos of avatar
  int *ci=&curI;                  //curr pos of avatar
  int *cj=&curJ;
  int killI=12;                   //starting i-pos of killer
  int killJ=5;                    //starting j-pos of avatar
  int *ki=&killI;                 //curr pos of killer 
  int *kj=&killJ;
  struct Item *playerInventory=item("Key", "Opens friend's door",item("Backpack", "Holds things and is very useful", NULL));  //avatar's inventory
  struct Room *r[9];        //array of 9 rooms
  struct positionInBoard pos[8];           //position of rooms relative to board
  initializeBoard(board,r,pos);           //before starting game, initialize everything
  int friendsMove[1];                     //number of moves we have played. After every 20, friend's health deteriorates
  friendsMove[0]=0;
  int friendsLife[1];                     //Friend's health. He is injured
  friendsLife[0]=1;
  int knifeStatus[1];                      //0 means knife is inactive, 1 means it is active
  knifeStatus[0]=0;
  int knifeMove[1];                        //tracks number of how long the knife is active. After 20 moves, it becomes inactive
  knifeMove[0]=0;
  int dollarStatus[1];                     //1 means avatar is wearing dollar chain which protects him psychokiller, 0 means he is not
  dollarStatus[0]=0;
  int killerStatus[1]={1};                  //1 means killer is alive, 0 means killer is dead
  int moveThick=0;                          //number of times stepped on thick wax
  int *countThickWax=&moveThick;            //corresponding pointer to above
  int currentRoom[1]={7};                  //stores index of current room in room array
  int didWeWin[0];                          //-1 means we lost, 1 means we won
  int candleStatus[0]={0};                  //1 means we planted the candle 0 means not

  board[*ci][*cj]='P';                  //place avatar

   //as long as game is not over .... play game
  while(gameOver(friendsLife,killerStatus,countThickWax, didWeWin)==0){   
    
    //avatar moves
    playerInventory=movePlayer(board,ci,cj,ki,kj, playerInventory, currentRoom, pos, r, knifeStatus,knifeMove,friendsMove,dollarStatus,friendsLife, countThickWax, killerStatus, candleStatus);
    
    //killer moves
    moveKiller(board, ki, kj, candleStatus);
    
    //print status of board
    printBoard(board);

    //print inventory
    printInventory(playerInventory);

    //print description of current room
    printf("%s\n",r[currentRoom[0]]->description);
    
    //increment moves we have taken
    friendsMove[0]=friendsMove[0]+1;
    
    //update knife move if avatar has it
    if(knifeStatus[0]==1){
        knifeMove[0]=knifeMove[0]+1;
    }
    //if killer is in vicinity and avatar is not wearing dollar chain, then killer kills
    if(isNearby(ki,kj,ci,cj)==1 && dollarStatus[0]==0){
        printf("Oopsies! Killer killed you!\n");
        didWeWin[0]=-1;          //loss
        break;                 //get out of gameOver loop
    }
  }
  if(didWeWin[0]==-1){   //loss
      printf("Sorry! You lost and the psychokiller has claimed two more victims! Better Luck next time!\n");
  }
  else if(didWeWin[0]==1){  //win
      printf("Yippee! You won the game and have given salvation to the psychokiller!\n");
  }
  free(ci);
  free(cj);
  free(ki);
  free(kj);
  free(countThickWax);
  free(playerInventory);
  free(r);

  return 0;
}