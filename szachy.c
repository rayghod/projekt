#include <stdio.h>
#define SIZE 10

char board[SIZE][SIZE];

void fill_board(){
  int i,j,z;
  z='a';

  for(i=0;i<SIZE;i++){
    for(j=0;j<SIZE;j++){
      board[i][j]='*';
    }
  }

  for(i=2;i<SIZE;i++){
    board[8][i]='p';
  }
  
  for(i=2;i<SIZE;i++){
    board[3][i]='P';
  }

  for(i=2;i<SIZE;i++){
    board[0][i] =(z+i-2);
  }

  for(i=9;i>1;i--){
    z=(10-i+'0');
    board[i][0]=z;
  }

  for(i=0;i<SIZE;i++){
    board[1][i]=' ';
  }

  for(i=0;i<SIZE;i++){
    board[i][1]=' ';
  }

  board[0][0]=' ';  

  board[2][2]='R';
  board[2][3]='N';
  board[2][4]='B';
  board[2][5]='Q';
  board[2][6]='K';
  board[2][7]='B';
  board[2][8]='N';
  board[2][9]='R';

  board[9][2]='r';
  board[9][3]='n';
  board[9][4]='b';
  board[9][5]='q';
  board[9][6]='k';
  board[9][7]='b';
  board[9][8]='n';
  board[9][9]='r';

}

void draw_board(){
  int i,j;
  for(i=0;i<SIZE;i++){
    for(j=0;j<SIZE;j++){
      printf("%2c", board[i][j]);
    }
    printf("\n");
  }
}

void move(int i, int j, int k, int l){
  char x, y;
  x=board[j][i];
  board[j][i]='*';
  board[l][k]=x;
  draw_board();
  printf("\n");
}

void check(int i, int j, int k, int l, char name){
  char coor2[3];
  int x,y;
  if(j==l && i==k){
    printf("Bierka musi zmienić swoje położenie. Podaj jeszcze raz współrzędne przesunięcia\n");
        scanf("%2s", coor2);
        k=(int)coor2[0]-95;
        l=(int)coor2[1]-47;
        l=11-l;
        check(i,j,k,l,board[j][i]);
  }

  switch(name){
    case 'p':
      if(board[l][k]!='*' && (k==i+1||k==i-1) ){
        move(i,j,k,l);
      }
      if(board[l][k]=='*'){
        if(j-l==1 && i==k){
          move(i,j,k,l);
        }
        else if(j==8 && l==6 && i==k){
          if(j-l==2){
            move(i,j,k,l);
          }
        }
        else{
          printf("Wybrałeś nieprawidłowy ruch. Podaj jeszcze raz współrzędne przesunięcia\n");
          scanf("%2s", coor2);
          k=(int)coor2[0]-95;
          l=(int)coor2[1]-47;
          l=11-l;
          check(i,j,k,l,board[j][i]);
        }
      }
      else{
        printf("Wybrałeś nieprawidłowy ruch. Podaj jeszcze raz współrzędne przesunięcia\n");
        scanf("%2s", coor2);
        k=(int)coor2[0]-95;
        l=(int)coor2[1]-47;
        l=11-l;
        check(i,j,k,l,board[j][i]);
      }
    break;
    case 'P':
      if(board[l][k]!='*' && (k==i+1||k==i-1) ){
        move(i,j,k,l);
      }
      if(board[l][k]=='*'){
        if(l-j==1 && i==k){
          move(i,j,k,l);
        }
        else if(j==3 && l==5 && i==k){
          if(l-j==2){
            move(i,j,k,l);
          }
        }
        else{
          printf("Wybrałeś nieprawidłowy ruch. Podaj jeszcze raz współrzędne przesunięcia\n");
          scanf("%2s", coor2);
          k=(int)coor2[0]-95;
          l=(int)coor2[1]-47;
          l=11-l;
          check(i,j,k,l,board[j][i]);
        }
      }
      else{
        printf("Wybrałeś nieprawidłowy ruch. Podaj jeszcze raz współrzędne przesunięcia\n");
        scanf("%2s", coor2);
        k=(int)coor2[0]-95;
        l=(int)coor2[1]-47;
        l=11-l;
        check(i,j,k,l,board[j][i]);
      }
    break;
    case 'r':
       if(j==l||i==k){
        move(i,j,k,l);
      }
      else{
        printf("Wybrałeś nieprawidłowy ruch. Podaj jeszcze raz współrzędne przesunięcia\n");
        scanf("%2s", coor2);
        k=(int)coor2[0]-95;
        l=(int)coor2[1]-47;
        l=11-l;
        check(i,j,k,l,board[j][i]);
      }
    break;
    case 'R':
       if(j==l||i==k){
        move(i,j,k,l);
      }
      else{
        printf("Wybrałeś nieprawidłowy ruch. Podaj jeszcze raz współrzędne przesunięcia\n");
        scanf("%2s", coor2);
        k=(int)coor2[0]-95;
        l=(int)coor2[1]-47;
        l=11-l;
        check(i,j,k,l,board[j][i]);
      }
    break;
    case 'n':
      if(
    break;
    case 'N':
      printf("Wybrana figura to koń\n");
    break;
    case 'k':
      printf("Wybrana figura to król\n");
    break;
    case 'K':
      printf("Wybrana figura to król\n");
    break;
    case 'q':
      printf("Wybrana figura to królowa\n");
    break;
    case 'Q':
      printf("Wybrana figura to królowa\n");
    break;
    case 'b':
       if(j==l||i==k){
        printf("Wybrałeś nieprawidłowy ruch. Podaj jeszcze raz współrzędne przesunięcia\n");
        scanf("%2s", coor2);
        k=(int)coor2[0]-95;
        l=(int)coor2[1]-47;
        l=11-l;
        check(i,j,k,l,board[j][i]);
      }
      else{
        move(i,j,k,l);
      }
    break;
    case 'B':
      //bishop(i,j,k,l);
    break;
    case '*':
      printf("Jako figurę wybrałeś puste pole\n");
    break;
  }
}

void transform(char *coor, char *coor2){
  int i, j, k, l;

  i=(int)coor[0]-95;
  j=(int)coor[1]-47;
  j=11-j;
  k=(int)coor2[0]-95;
  l=(int)coor2[1]-47;
  l=11-l;

  check(i,j,k,l,board[j][i]);
}
 

int main(){
  int i, j, k, l, end;
  char coor[3];
  char coor2[3];
  end=0;
  fill_board();
  draw_board();
  printf("Pierwszy ruch należy do małych liter\n");
printf("%c",board[0][0]);
printf("%c",board[1][0]);
printf("%c",board[2][0]);
printf("%c",board[3][0]);
printf("%c",board[4][0]);
  while(end!=1){
    printf("Podaj współrzędne figury, którą chcesz przesunąć (np. a1)\n");
    scanf("%2s", coor);
    printf("Podaj współrzędne, na którą chcesz ją przesunąć (np. a2)\n");
    scanf("%2s", coor2);
    transform(coor,coor2);



  }
}

/*
 K  W
[0][0]
[1][0]
[2][0]
[3][0]
[4][0]
*/