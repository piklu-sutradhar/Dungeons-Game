//-----------------------------------------
// NAME: Piklu Sutradhar
// STUDENT NUMBER: 7820870
// COURSE: COMP 2160, SECTION: A01
// INSTRUCTOR: Franklin Bristow
// ASSIGNMENT: assignment # 2, QUESTION: question # 1
//
// REMARKS: Game
//
//-----------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<unistd.h>

#define LENGTH 200
//-------------------------------------------------------------------------------------
// CONSTANTS and TYPES
//-------------------------------------------------------------------------------------
typedef enum state {NEVER = ' ',SOMEPOINT = ',',WALL = '!',LIGTHSOURCE = '%',INTENSITY1 = '#',INTENSITY2 = '=',INTENSITY3 = '-'} State;
typedef enum border {CORNER = '+', VERTICAL = '-', HORIZONTAL = '|'} Border;
typedef enum Bool {FALSE, TRUE} BOOL;
typedef struct game
{
    char title[LENGTH];
    int gameBoard[LENGTH][LENGTH];
    int columns;
    int rows;
} GAME;
//-------------------------------------------------------------------------------------
// VARIABLES
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// PROTOTYPES
//-------------------------------------------------------------------------------------
//invariants
void checkPoints(GAME const *game1, int r, int c);
void updateBoard(GAME *game1,int rows, int columns);
void makeMoves(GAME * game1,int r, int c, char command[],int moves);
int min(int x, int y);
int max(int min, int x, int y);
BOOL wallPresent(GAME * game1, int yPosition, int xPosition, int yLight, int xLight);
void makeBorder(GAME *game1);
void print(GAME *game1,int r,int c, int move);
//-------------------------------------------------------------------------------------
// FUNCTIONS
//-------------------------------------------------------------------------------------

int main( int argc, char *argv[] )
{
    GAME game1;
    int moves;
    FILE * file;
    if (argc < 2){
    printf("One Argument Expected\n");
    return EXIT_FAILURE;
    }
    else if (argc > 2){
    printf("More Than Expected Argument Entered\n");
    return EXIT_FAILURE;
    }
    else{
    assert(argc == 2);
    file = fopen(argv[1],"r");
    while(fgets(game1.title,LENGTH,file)){
    assert(game1.title != NULL);
    assert(game1.title[0] == '*');
        if(game1.title[0] == '*'){
            int i,j;
            
            printf("%s", game1.title);
            #ifdef ANIMATION
            sleep(1);
            system("clear");
            #endif
            
            fscanf(file, "%d %d %d", &game1.rows, &game1.columns, &moves);
            fgetc(file);
            char command[moves+1];
            makeBorder(&game1);
            int r, c;
            for(i=1;i<game1.rows+1;i++){
                for(j=1;j<game1.columns+1;j++){
                        char ch = fgetc(file);
                    if(ch == '@'){
                            game1.gameBoard[i][j] = LIGTHSOURCE;
                        r = i;
                        c = j;
                        checkPoints(&game1,r,c);
                    }
                    else if (ch == '~'){
                        game1.gameBoard[i][j] = WALL;
                    }
                    else if (ch == ' '){
                        game1.gameBoard[i][j] = NEVER;
                    }
                    else{
                        game1.gameBoard[i][j] = SOMEPOINT;
                    }
                }
                fgetc(file);
            }
            print(&game1,r,c,0);
            #ifdef ANIMATION
            sleep(1);
            system("clear");
            #endif
            fgets(command,moves+1, file);
            fgetc(file);
            assert(strlen(command) == moves);
            makeMoves(&game1,r,c, command,moves);
        }
    }
    fclose(file);
    return EXIT_SUCCESS;
    }
}
//Invariants
void checkPoints(GAME const *game1, int r, int c){
assert(r>=0 && r<game1->rows + 2 && c >=0 && c < game1->columns + 2);
}
void makeMoves(GAME * game1,int r, int c, char command[],int moves){
int i;
//dsint start = 0;
for(i = 0; i < moves; i++){
                    if(command[i] == '>'){
                        c++;
                        checkPoints(game1,r,c);
                    }
                    else if(command[i] == 'v'){
                        r++;
                        checkPoints(game1,r,c);
                    }
                    else if(command[i] == '^'){
                        r--;
                        checkPoints(game1,r,c);
                    }
                    else{
                        c--;
                        checkPoints(game1,r,c);
                    }
                    checkPoints(game1,r,c);
                   updateBoard(game1, r, c);
                   #ifdef NDEBUG
                    if( i >= moves-10)
                   {
                   print(game1,r,c,i+1);
                   #ifdef ANIMATION
            sleep(1);
            system("clear");
            #endif
                   }
                   #endif
                   #ifndef NDEBUG
                   print(game1,r,c,i+1);
                   #ifdef ANIMATION
            sleep(1);
            system("clear");
            #endif
                   #endif
                  
            }
}
void makeBorder(GAME *game1){
int r, c;

    for(r = 0; r < game1->rows+2; r++)
    {
        for(c = 0; c < game1->columns+2; c++){
                if (r == 0 || r == game1->rows+1){
                    if(c ==0 || c == game1->columns+1){
                        game1->gameBoard[r][c] = CORNER;
                    }
                    else{
                        game1->gameBoard[r][c] = VERTICAL;
                    }
                }
                else{
                    if(c ==0 || c == game1->columns+1){
                      game1->gameBoard[r][c] = HORIZONTAL;
                    }
                }
        }
    }
}
void updateBoard(GAME *game1,int rows, int columns){
int r, c;
    double distance;
    checkPoints(game1, rows, columns);
    for(r = 0; r < game1->rows+2; r++)
    {
        for(c = 0; c < game1->columns+2; c++){
                distance = sqrt(pow(((double)(r-rows)),2) + pow(((double)(c-columns)),2));
                if(!(r == 0 || r == game1->rows+1 || c == 0 || c == game1->columns+1 || game1->gameBoard[r][c] == WALL || (wallPresent(game1,r,c,rows,columns) == TRUE))){
            if((distance < 1.00)){
                    game1->gameBoard[r][c] = LIGTHSOURCE;
            }
            else if (distance < 2.00){
               game1->gameBoard[r][c] = INTENSITY1;
            }
            else if (distance < 3.00){
                 game1->gameBoard[r][c] = INTENSITY2;
            }
            else{
                    if(distance < 4.00){
                game1->gameBoard[r][c] = INTENSITY3;
            }
            else if (game1->gameBoard[r][c] != ' '){
            game1->gameBoard[r][c] = SOMEPOINT;
            }
          }
        }
        }
        }
}
void print(GAME *game1,int rows, int columns, int move){
int r, c;
 printf("Move %d\n", move);
    for(r = 0; r < game1->rows+2; r++)
    {
        for(c = 0; c < game1->columns+2; c++){
        printf("%c",game1->gameBoard[r][c]);
        }
        printf("\n");
        } 
}
BOOL wallPresent(GAME * game1, int yPosition, int xPosition, int yLight, int xLight){
int i;
float x;
BOOL result = FALSE;
int minX, maxX, minY, maxY;
minX = min(xPosition, xLight);
maxX = max(minX, xPosition, xLight);
minY = min(yPosition, yLight);
maxY = max(minY, yPosition, yLight);
checkPoints(game1, minY, minX);
checkPoints(game1, maxY, maxX);
if(minX == maxX){
    for(i = minY + 1; i < maxY && result == FALSE; i++){
        if(game1->gameBoard[i][minX] == WALL){
            result = TRUE;
        }
    }
}
else if (minY == maxY){
     for(i = minX + 1; i < maxX && result == FALSE; i++){
        if(game1->gameBoard[minY][i] == WALL){
            result = TRUE;
        }
    }
}
else{
    double slope = (double)(yLight - yPosition)/(double)(xLight - xPosition);
    double intersect = yLight - (slope * xLight);
    for(x = (float)(minX); x < maxX && result == FALSE; x = x + 0.5){
            int y = slope * x + intersect;
            int c = (int) x;
            checkPoints(game1, y, c);
        if(game1->gameBoard[y][c] == WALL){
            result = TRUE;
            }
        }
  }
  return result;
}
int min(int x, int y){
    if (x < y){
        return x;
    }
    else{
        return y;
    }
}
int max(int min, int x, int y){
return x+y-min;
}
