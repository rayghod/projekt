#include <stdio.h>
#include <math.h>
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
      if((l==j+2 && k==i-1)||(l==j+1 && k==i-2)||(l==j-1 && k==i-2)||(l==j-2 && k==i-1)||
         (l==j-2 && k==i+1)||(l==j-1 && k==i+2)||(l==j+1 && k==i+2)||(l==j+2 && k==i+1)){
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
    case 'N':
      if((l==j+2 && k==i-1)||(l==j+1 && k==i-2)||(l==j-1 && k==i-2)||(l==j-2 && k==i-1)||
         (l==j-2 && k==i+1)||(l==j-1 && k==i+2)||(l==j+1 && k==i+2)||(l==j+2 && k==i+1)){
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
    case 'k':
      if(fabs(j-l)<=1 && fabs(i-k)<=1){
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
    case 'K':
      if(fabs(j-l)<=1 && fabs(i-k)<=1){
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
    case 'q':
      for(x=1;x<8;x++){
        for(y=1;y<8;y++){
          if((l==j+x && k==i+y)||(l==j-x && k==i-y)){
            move(i,j,k,l);
            x=11;
          }
          if((l==j+x && k==i-y)||(l==j-x && k==i+y)){
            move(i,j,k,l);
            x=11;
          }
        }
      }
      if(j==l||i==k){
        move(i,j,k,l);
        x=11;
      }
      if(x<10){
        printf("Wybrałeś nieprawidłowy ruch. Podaj jeszcze raz współrzędne przesunięcia\n");
        scanf("%2s", coor2);
        k=(int)coor2[0]-95;
        l=(int)coor2[1]-47;
        l=11-l;
        check(i,j,k,l,board[j][i]);
      }
    break;
    case 'Q':
      for(x=1;x<8;x++){
        for(y=1;y<8;y++){
          if((l==j+x && k==i+y)||(l==j-x && k==i-y)){
            move(i,j,k,l);
            x=11;
          }
          if((l==j+x && k==i-y)||(l==j-x && k==i+y)){
            move(i,j,k,l);
            x=11;
          }
        }
      }
      if(j==l||i==k){
        move(i,j,k,l);
        x=11;
      }
      if(x<10){
        printf("Wybrałeś nieprawidłowy ruch. Podaj jeszcze raz współrzędne przesunięcia\n");
        scanf("%2s", coor2);
        k=(int)coor2[0]-95;
        l=(int)coor2[1]-47;
        l=11-l;
        check(i,j,k,l,board[j][i]);
      }
    break;
    case 'b':
      for(x=1;x<8;x++){
        for(y=1;y<8;y++){
          if((l==j+x && k==i+y)||(l==j-x && k==i-y)){
            move(i,j,k,l);
            x=11;
          }
          if((l==j+x && k==i-y)||(l==j-x && k==i+y)){
            move(i,j,k,l);
            x=11;
          }
        }
      }
      if(x<10){
        printf("Wybrałeś nieprawidłowy ruch. Podaj jeszcze raz współrzędne przesunięcia\n");
        scanf("%2s", coor2);
        k=(int)coor2[0]-95;
        l=(int)coor2[1]-47;
        l=11-l;
        check(i,j,k,l,board[j][i]);
      }
    break;
    case 'B':
      for(x=1;x<8;x++){
        for(y=1;y<8;y++){
          if((l==j+x && k==i+y)||(l==j-x && k==i-y)){
            move(i,j,k,l);
            x=11;
          }
          if((l==j+x && k==i-y)||(l==j-x && k==i+y)){
            move(i,j,k,l);
            x=11;
          }
        }
      }
      if(x<10){
        printf("Wybrałeś nieprawidłowy ruch. Podaj jeszcze raz współrzędne przesunięcia\n");
        scanf("%2s", coor2);
        k=(int)coor2[0]-95;
        l=(int)coor2[1]-47;
        l=11-l;
        check(i,j,k,l,board[j][i]);
      }
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
  int i, j, k, l,x,y, end;
  char coor[3];
  char coor2[3];
  end=0;
  fill_board();
  draw_board();
  printf("Pierwszy ruch należy do małych liter\n");
  while(end!=1){
    printf("Podaj współrzędne figury, którą chcesz przesunąć (np. a1)\n");
    scanf("%2s", coor);
    printf("Podaj współrzędne, na którą chcesz ją przesunąć (np. a2)\n");
    scanf("%2s", coor2);
    transform(coor,coor2);
    end=1;
    for(x=0;x<10;x++){
      for(y=0;y<10;y++){
        if(board[x][y]=='k'){
         end=end+1;
        }
        else if(board[x][y]=='K'){
         end=end+1;
        }
      }
    }  
    end=end-1;
  }

  printf("Koniec gry\n");


}

/*
 K  W
[0][0]
[1][0]
[2][0]
[3][0]
[4][0]
*/
