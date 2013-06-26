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
  int x,y,z;
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
      else if(board[l][k]=='*'){
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
      else if(board[l][k]=='*'){
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
        z=0;
        if(l>j+1){
          for(y=j+1;y<l;y++){
            if(board[y][i]!='*'){
              z++;
            }
          }
        }
        if(j>l+1){
          for(y=l+1;y<j;y++){
            if(board[y][i]!='*'){
              z++;
            }
          }
        }
        if (k>i+1){
          for(y=i+1;y<k;y++){
            if(board[j][y]!='*'){
              z++;
            }
          }
        }
        if(i>k+1){
          for(y=k+1;y<i;y++){
            if(board[j][y]!='*'){
              z++;
            }
          }
        }
      }

      if(z>0){
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
    case 'R':
      if(j==l||i==k){
        z=0;
        if(l>j+1){
          for(y=j+1;y<l;y++){
            if(board[y][i]!='*'){
              z++;
            }
          }
        }
        if(j>l+1){
          for(y=l+1;y<j;y++){
            if(board[y][i]!='*'){
              z++;
            }
          }
        }
        if (k>i+1){
          for(y=i+1;y<k;y++){
            if(board[j][y]!='*'){
              z++;
            }
          }
        }
        if(i>k+1){
          for(y=k+1;y<i;y++){
            if(board[j][y]!='*'){
              z++;
            }
          }
        }
      }

      if(z>0){
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
      if(j==l||i==k){
        z=0;
        if(l>j+1){
          for(y=j+1;y<l;y++){
            if(board[y][i]!='*'){
              z++;
            }
          }
        }
        if(j>l+1){
          for(y=l+1;y<j;y++){
            if(board[y][i]!='*'){
              z++;
            }
          }
        }
        if (k>i+1){
          for(y=i+1;y<k;y++){
            if(board[j][y]!='*'){
              z++;
            }
          }
        }
        if(i>k+1){
          for(y=k+1;y<i;y++){
            if(board[j][y]!='*'){
              z++;
            }
          }
        }
      }



      for(x=1;x<8;x++){
        if((l==j+x && k==i+x)||(l==j-x && k==i-x)){
          z=0;
        }
        if((l==j+x && k==i-x)||(l==j-x && k==i+x)){
          z=0;
        }
      }



      for(x=1;x<8;x++){
        if(l==j+x && k==i+x){
          for(y=1;y<x;y++){
            if(board[j+y][i+y]!='*'){
              z++;
            }
          }
        }
        if(l==j-x && k==i-x){
          for(y=1;y<x;y++){
            if(board[j-y][i-y]!='*'){
              z++;
            }
          }
        }
        if(l==j+x && k==i-x){
          for(y=1;y<x;y++){
            if(board[j+y][i-y]!='*'){
              z++;
            }
          }
        }
        if(l==j-x && k==i+x){
          for(y=1;y<x;y++){
            if(board[j-y][i+y]!='*'){
              z++;
            }
          }
        }
      }

      if(z>0){
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
    case 'Q':
      for(x=1;x<8;x++){
        if((l==j+x && k==i+x)||(l==j-x && k==i-x)){
          move(i,j,k,l);
          x=11;
        }
        if((l==j+x && k==i-x)||(l==j-x && k==i+x)){
          move(i,j,k,l);
          x=11;
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
      z=1;

      for(x=1;x<8;x++){
        if((l==j+x && k==i+x)||(l==j-x && k==i-x)){
          z=0;
        }
        if((l==j+x && k==i-x)||(l==j-x && k==i+x)){
          z=0;
        }
      }

      for(x=1;x<8;x++){
        if(l==j+x && k==i+x){
          for(y=1;y<x;y++){
            if(board[j+y][i+y]!='*'){
              z++;
            }
          }
        }
        if(l==j-x && k==i-x){
          for(y=1;y<x;y++){
            if(board[j-y][i-y]!='*'){
              z++;
            }
          }
        }
        if(l==j+x && k==i-x){
          for(y=1;y<x;y++){
            if(board[j+y][i-y]!='*'){
              z++;
            }
          }
        }
        if(l==j-x && k==i+x){
          for(y=1;y<x;y++){
            if(board[j-y][i+y]!='*'){
              z++;
            }
          }
        }
      }

      if(z>0){
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


      /*for(x=1;x<8;x++){
        if((l==j+x && k==i+x)||(l==j-x && k==i-x)){
          move(i,j,k,l);
          x=11;
        }
        if((l==j+x && k==i-x)||(l==j-x && k==i+x)){
          move(i,j,k,l);
          x=11;
        }
      }
      if(x<10){
        printf("Wybrałeś nieprawidłowy ruch. Podaj jeszcze raz współrzędne przesunięcia\n");
        scanf("%2s", coor2);
        k=(int)coor2[0]-95;
        l=(int)coor2[1]-47;
        l=11-l;
        check(i,j,k,l,board[j][i]);
      }*/
    break;
    case 'B':
      z=1;

      for(x=1;x<8;x++){
        if((l==j+x && k==i+x)||(l==j-x && k==i-x)){
          z=0;
        }
        if((l==j+x && k==i-x)||(l==j-x && k==i+x)){
          z=0;
        }
      }

      for(x=1;x<8;x++){
        if(l==j+x && k==i+x){
          for(y=1;y<x;y++){
            if(board[j+y][i+y]!='*'){
              z++;
            }
          }
        }
        if(l==j-x && k==i-x){
          for(y=1;y<x;y++){
            if(board[j-y][i-y]!='*'){
              z++;
            }
          }
        }
        if(l==j+x && k==i-x){
          for(y=1;y<x;y++){
            if(board[j+y][i-y]!='*'){
              z++;
            }
          }
        }
        if(l==j-x && k==i+x){
          for(y=1;y<x;y++){
            if(board[j-y][i+y]!='*'){
              z++;
            }
          }
        }
      }

      if(z>0){
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

char player_check(char *coor, char *coor2, int player){
  int i,j;
  i=(int)coor[0]-95;
  j=(int)coor[1]-47;
  j=11-j;
  if(board[j][i]=='*'){
    printf("Jako figurę wybrałeś puste pole, podaj współrzędne figury, którą chcesz przesunąć (np. a1)\n");
    scanf("%2s", coor);
    printf("Podaj współrzędne, na którą chcesz ją przesunąć (np. a2)\n");
    scanf("%2s", coor2);
  }
  if(player==0){
    if(board[j][i]=='P'||board[j][i]=='R'||board[j][i]=='N'||board[j][i]=='B'||board[j][i]=='Q'||board[j][i]=='K'){
      printf("Wybrałeś figurę przeciwnika, wskaż jeszcze raz współrzędne\n");
      scanf("%2s", coor);
      printf("Podaj współrzędne, na którą chcesz ją przesunąć (np. a2)\n");
      scanf("%2s", coor2);
      player_check(coor,coor2,player);
    }
    else{
      transform(coor,coor2);
    }
  }
  else{
    if(board[j][i]=='p'||board[j][i]=='r'||board[j][i]=='n'||board[j][i]=='b'||board[j][i]=='q'||board[j][i]=='k'){
      printf("Wybrałeś figurę przeciwnika, wskaż jeszcze raz współrzędne\n");
      scanf("%2s", coor);
      printf("Podaj współrzędne, na którą chcesz ją przesunąć (np. a2)\n");
      scanf("%2s", coor2);
      player_check(coor,coor2,player);
    }
    else{
      transform(coor,coor2);
    }
  }
}
/*
void szachowanie(){
  int x,y,i,j,k,l;
  for(x=0;x<SIZE;x++){
    for(y=0;y<SIZE;y++){
      if(board[x][y]=='k'){
        i=x;
        j=y;
      }
      else if(board[x][y]=='K'){
        k=x;
        l=y;
      }
    }
  }

  for(i+1;i<SIZE;i++){
    if(board[i][j]!='*'){
      printf("Warunek 1\n");
      if(board[i][j]=='R'){
        printf("Król małych liter jest szachowany1\n");
        break;
      }
    }
  }
  for(i-1;i>0;i--){
    if(board[i][j]!='*'){
      printf("Warunek 2\n");
      if(board[i][j]=='R'){
        printf("Król małych liter jest szachowany2\n");
      }
    if(board[i][j]!='R'){
        break;
      }
    }
  }
  for(j+1;j<SIZE;j++){
    if(board[i][j]!='*'){
            printf("Warunek 3\n");
      if(board[i][j]=='R'){
        printf("Król małych liter jest szachowany3\n");
        break;
      }
    }
  }
  for(j-1;j>2;j--){
    if(board[i][j]!='*'){
            printf("Warunek 4\n");
            printf("%c\n",board[i][j]);
      if(board[i][j]=='R'){
        printf("Król małych liter jest szachowany4\n");
        break;
      }
    }
  }
}*/

void roszada_krotka(player){
  char coor[2];
  char coor2[2];
  if(player==0){
    if(board[9][9]=='r' && board[9][6]=='k' && board[9][7]=='*' && board[9][8]=='*'){
      board[9][8]='k';
      board[9][7]='r';
      board[9][6]='*';
      board[9][9]='*';
      draw_board();
    }
    else{
      printf("Nie możesz wykonać roszady krótkiej. Wybierz figurę, którą chcesz przesunąć (np. a1)\n");
      scanf("%2s",coor);
      printf("Podaj współrzędne, na którą chcesz ją przesunąć (np. a2)\n");
      scanf("%2s", coor2);
      player_check(coor,coor2,player);
    }
  }
  else{
    if(board[2][9]=='R' && board[2][6]=='K' && board[2][7]=='*' && board[2][8]=='*'){
      board[2][8]='K';
      board[2][7]='R';
      board[2][6]='*';
      board[2][9]='*';
      draw_board();
    }
    else{
      printf("Nie możesz wykonać roszady krótkiej. Wybierz figurę, którą chcesz przesunąć (np. a1)\n");
      scanf("%2s",coor);
      printf("Podaj współrzędne, na którą chcesz ją przesunąć (np. a2)\n");
      scanf("%2s", coor2);
      player_check(coor,coor2,player);
    }
  }

}


void roszada_dluga(player){
  char coor[2];
  char coor2[2];
  if(player==0){
    if(board[9][2]=='r' && board[9][6]=='k' && board[9][3]=='*' && board[9][4]=='*' && board[9][5]=='*'){
      board[9][4]='k';
      board[9][5]='r';
      board[9][2]='*';
      board[9][6]='*';
      draw_board();
    }
    else{
      printf("Nie możesz wykonać roszady długiej. Wybierz figurę, którą chcesz przesunąć (np. a1)\n");
      scanf("%2s",coor);
      printf("Podaj współrzędne, na którą chcesz ją przesunąć (np. a2)\n");
      scanf("%2s", coor2);
      player_check(coor,coor2,player);
    }
  }
  else{
    if(board[2][2]=='R' && board[2][6]=='K' && board[2][3]=='*' && board[2][4]=='*' && board[2][5]=='*'){
      board[2][5]='R';
      board[2][4]='K';
      board[2][2]='*';
      board[2][6]='*';
      draw_board();
    }
    else{
      printf("Nie możesz wykonać roszady długiej. Wybierz figurę, którą chcesz przesunąć (np. a1)\n");
      scanf("%2s",coor);
      printf("Podaj współrzędne, na którą chcesz ją przesunąć (np. a2)\n");
      scanf("%2s", coor2);
      player_check(coor,coor2,player);
    }
  }

}

int main(){
  int i, j, k, l,x,y, end,player;
  char coor[3];
  char coor2[3];
  char p[3];
  end=0;
  fill_board();
  draw_board();
  printf("Roszada krótka -rk, roszada długa-rd\n");
  printf("Pierwszy ruch należy do małych(białych) liter\n");
  while(1){
    //szachowanie();
    end=0;
    for(x=0;x<10;x++){
      for(y=0;y<10;y++){
        if(board[x][y]=='k'){
         end++;
        }
      }
    }
    if(end==0){
      printf("Koniec gry. Wygrały wielkie litery.\n");
      break;
    }
    player=0;
    printf("Ruch małych liter\n");
    printf("Podaj współrzędne figury, którą chcesz przesunąć (np. a1)\n");
    scanf("%2s",coor);
    if((int)coor[0]==114){
      if((int)coor[1]==107){
        roszada_krotka(player);
      }
      else if((int)coor[1]==100){
        roszada_dluga(player);
      }
    }
    else{
      printf("Podaj współrzędne, na którą chcesz ją przesunąć (np. a2)\n");
      scanf("%2s",coor2);
      player_check(coor,coor2,player);
    }
    //szachowanie();
    end=0;
    for(x=0;x<10;x++){
      for(y=0;y<10;y++){
        if(board[x][y]=='K'){
         end++;
        }
      }
    }
    if(end==0){
      printf("Koniec gry. Wygrały małe litery.\n");
      break;
    }
    player=1;
    printf("Ruch WIELKICH liter\n");
    printf("Podaj współrzędne figury, którą chcesz przesunąć (np. a1)\n");
    scanf("%2s", coor);
    if((int)coor[0]==114){
      if((int)coor[1]==107){
        roszada_krotka(player);
      }
      else if((int)coor[1]==100){
        roszada_dluga(player);
      }
    }
    else{
      printf("Podaj współrzędne, na którą chcesz ją przesunąć (np. a2)\n");
      scanf("%2s",coor2);
      player_check(coor,coor2,player);
    }
  }
}
