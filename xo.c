#include <stdio.h>
#define SIZE 7

char board[SIZE][SIZE];

void draw_board() {
  int x, y;

  for (y = 0; y < SIZE; y++){
    for (x = 0; x < SIZE; x++){
	printf("%2c ", board[x][y]);
    }
    printf("\n");
  }
}

void fill_board() {
  int x, y;
  char z;

  for(y=0; y<1; y++){
    for (x = 0; x < SIZE; x++){
      z=(x+1+'0');
      board[x][y] =z;
    }
  }

  for (y = 1; y < SIZE; y++){
    for (x = 0; x < SIZE; x++){
      board[x][y] = '*';
    }
  }
}

void move(int choice, char gracz){
  int i, z;
  z=0; 
  choice= choice-1;
  for(i=6;z!=1;i--){
    if(board[choice][i] == '*'){
      board[choice][i] = gracz;
      z=1;
    }
    if(i==0){
      printf("Wybrana kolumna jest już zapełniona. Proszę wybrać inną\n");
      scanf("%i", &choice);
      choice=choice-1;
      i=7;
    }
  }
  draw_board();
}

int check(){
  int i, j, win;
  win=0;

  for(i=0; i<4; i++){
    for(j=1; j<7; j++){
      if(board[i][j] !='*' && board[i][j]==board[i+1][j] && board[i+1][j]==board[i+2][j] && board[i+2][j]==board[i+3][j]){
        win=1;
      }
    }
  }//-


  for(i=0; i<7; i++){
    for(j=1; j<4; j++){
      if(board[i][j] !='*' && board[i][j]==board[i][j+1] && board[i][j+1]==board[i][j+2] && board[i][j+2]==board[i][j+3]){
        win=1;
      }
    }
  }//|


  for(i=0; i<4; i++){
    for(j=1; j<4; j++){
      if(board[i][j] !='*' && board[i][j]==board[i+1][j+1] && board[i+1][j+1]==board[i+2][j+2] && board[i+2][j+2]==board[i+3][j+3]){
        win=1;
      }
    }
  }// \


  for(i=0; i<4; i++){
    for(j=6; j>3; j--){

      if(board[i][j] !='*' && board[i][j]==board[i+1][j-1] && board[i+1][j-1]==board[i+2][j-2] && board[i+2][j-2]==board[i+3][j-3]){
        win=1;
      }
    }
  } // /

return win;
}

int check2(){
  int i, j, x;
  x=0;

  for(i=0;i<SIZE;i++){
    for(j=0;j<SIZE;j++){
      if(board[i][j]=='*'){
        x=1;
      }
    }
  }

return x;  
}

int main(){
  int choice, win;
  char gracz;

  fill_board();
  printf("\nWitajcie w naszej grze Connect Four!\n");
  printf("Pierwszy z graczy posiada znak X, drugi O, wygrywa ten kto pierwszy ułoży nieprzerwany ciag 4 znaków\n");
  printf("Powodzenia!\n\n");
  draw_board();

  while(win !=1){
    
    gracz='X';
    printf("Ruch gracza nr 1 (X)\n");
    printf("Wpisz kolumnę, w którą ma wpaść Twój żeton (1-7) i wciśnij enter\n");
    scanf("%i", &choice);
    move(choice, gracz);
    win=check();
    if(win==1){
      printf("Gratulacje wygrał gracz nr 1 (X)!\n");
      break;
    }

    gracz='O';
    printf("Ruch gracza nr 2 (O)\n");
    printf("Wpisz kolumnę, w którą ma wpaść Twój żeton (1-7) i wciśnij enter\n");
    scanf("%i", &choice);
    move(choice, gracz);
    win=check();
    if(win==1){
      printf("Gratulacje wygrał gracz nr 2 (0)!\n");
    }
    if(check2()==0){
      printf("REMIS\n");
      break;
    }
  }
  

  return 0;
}


