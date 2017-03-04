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

#define DNDEBUG
#define LINE_LENGTH 50
//-------------------------------------------------------------------------------------
// CONSTANTS and TYPES
//-------------------------------------------------------------------------------------
typedef enum state {NEVER = ' ',SOMEPOINT = ',',WALL = '!',LIGHTSOURCE = '%'} State;
typedef enum border {CORNER = '+', VERTICAL = '-', HORIZONTAL = '|'} Border;
typedef enum Bool {FALSE, TRUE} BOOL;
typedef struct game
{
    char title[LINE_LENGTH];
    int gameBoard[120][120];
    int columns;
    int rows;
} GAME;
//-------------------------------------------------------------------------------------
// VARIABLES
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// PROTOTYPES
//-------------------------------------------------------------------------------------
void makeMoves(GAME * game1,int r, int c, char command[]);
int min(int x, int y);
int max(int min, int x, int y);
BOOL wallPresent(GAME * game1, int yPosition, int xPosition, int yLight, int xLight);
void makeBorder(GAME *game1,int rows, int columns);
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
    while(fgets(game1.title,LINE_LENGTH,file)){
        if(game1.title[0] == '*'){
            int i,j;
            printf("%s", game1.title);
            fscanf(file, "%d %d %d", &game1.rows, &game1.columns, &moves);
            fgetc(file);
            fgetc(file);
            char command[100];
            makeBorder(&game1,game1.rows, game1.columns);
            int r=0, c=0;
            for(i=1;i<game1.rows+1;i++){
                for(j=1;j<game1.columns+1;j++){
                        char ch = fgetc(file);
                    if(ch == '@'){
                            game1.gameBoard[i][j] = LIGHTSOURCE;
                        r = i;
                        c = j;
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
                fgetc(file);
            }
            print(&game1,r,c,0);
            fgets(command, 100, file);
            makeMoves(&game1,r,c, command);
        }
    }
    fclose(file);
    return EXIT_SUCCESS;
    }
}
void makeMoves(GAME * game1,int r, int c, char command[]){
int i;
int moves = strlen(command);
int start = 0;
/*#ifdef DNDEBUG
start = moves - 10;
#endif
#ifndef DNDEBUG
 start = 0;
 #endif*/
            for(i = start; i < moves; i++){
                    if(command[i] == '>'){
                        c++;
                    }
                    else if(command[i] == 'v'){
                        r++;
                    }
                    else if(command[i] == '^'){
                        r--;
                    }
                    else{
                        c--;
                    }
             print(game1,r,c,i+1);
            }
	    //#endif
}
void makeBorder(GAME *game1,int rows, int columns){
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
void print(GAME *game1,int rows, int columns, int move)
{
    printf("Move %d\n", move);
    int r, c;
    double distance;
    for(r = 0; r < game1->rows+2; r++)
    {
        for(c = 0; c < game1->columns+2; c++){
                distance = sqrt(pow(((double)(r-rows)),2) + pow(((double)(c-columns)),2));
                if(move == 0 || r == 0 || r == game1->rows+1 || c == 0 || c == game1->columns+1 || game1->gameBoard[r][c] == WALL || (wallPresent(game1,r,c,rows,columns) == TRUE)){
                   printf("%c", game1->gameBoard[r][c] );
                }
            else if((distance < 1.00)){
                    game1->gameBoard[r][c] = SOMEPOINT;
                printf("%c", '%');
            }
            else if (distance < 2.00){
               game1->gameBoard[r][c] = SOMEPOINT;
                printf("%c", '#');
            }
            else if (distance < 3.00){
                 game1->gameBoard[r][c] = SOMEPOINT;
                printf("%c", '=');
            }
            else{
                    if(distance < 4.00){
                game1->gameBoard[r][c] = SOMEPOINT;
                printf("%c", '-');
            }
            else{
               printf("%c", game1->gameBoard[r][c]);
            }
          }
        }
        printf("\n");
    }
}
BOOL wallPresent(GAME * game1, int yPosition, int xPosition, int yLight, int xLight){
int i;
BOOL result = FALSE;
int minX, maxX, minY, maxY;
minX = min(xPosition, xLight);
maxX = max(minX, xPosition, xLight);
minY = min(yPosition, yLight);
maxY = max(minY, yPosition, yLight);
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
    for(i = minX + 1; i < maxX && result == FALSE; i++){
            int y = slope * i + intersect;
        if(game1->gameBoard[y][i] == WALL){
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
