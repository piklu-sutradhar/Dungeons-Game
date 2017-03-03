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

#define LINE_LENGTH 50
//-------------------------------------------------------------------------------------
// CONSTANTS and TYPES
//-------------------------------------------------------------------------------------
int ROWS = 100;
int COLUMNS = 100;
int MOVES = 100;
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

//-------------------------------------------------------------------------------------
// FUNCTIONS
//-------------------------------------------------------------------------------------
int min(int x, int y);
int max(int min, int x, int y);
BOOL wallPresent(GAME * game1, int yPosition, int xPosition, int yLight, int xLight);
void makeBorder(GAME *game1,int rows, int columns);
void print(GAME *game1,int r,int c);
int main( int argc, char *argv[] )
{
    GAME game1;
    char firstChar;
    int moves;
    char title[LINE_LENGTH];
    FILE * file;
    file = fopen("std.txt.txt", "r" );
    firstChar = fgetc(file);
    while(firstChar){
        if(firstChar == '*'){
            int i,j;
            fgets(game1.title,LINE_LENGTH,file);
            //printf("%s", game1.title);
            fscanf(file, "%d %d %d", &game1.rows, &game1.columns, &moves);
            fgetc(file);
            //printf("%d %d %d",game1.rows, game1.columns, game1.moves);
            char command[100];
            //game1.gameBoard = int[game1.rows][game1.columns];
            makeBorder(&game1,game1.rows, game1.columns);
            int r=0, c=0;
            for(i=1;i<game1.rows+1;i++){
                for(j=1;j<game1.columns+1;j++){
                        char ch = fgetc(file);
                        //game1.board[i][j] = ch;
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

                    //printf("%c",game1.board[i][j]);
                }
                fgetc(file);
            }
            printf("Move %d: \n", 0);
            print(&game1,r,c);
            //fgetc(file);
            fgets(command, 100, file);
            for(i = 0; i < strlen(command); i++){
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
                    printf("Move %d: \n", i+1);
             print(&game1,r,c);
            }

        }
        firstChar = fgetc(file);
    }

    fclose(file);
    return EXIT_SUCCESS;
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
void print(GAME *game1,int rows, int columns)
{
    //printf("%s", game1->title);
    int r, c;
    double distance;
    for(r = 0; r < game1->rows+2; r++)
    {
        for(c = 0; c < game1->columns+2; c++){
                distance = sqrt(pow(((double)(r-rows)),2) + pow(((double)(c-columns)),2));
                if(r == 0 || r == game1->rows+1 || c == 0 || c == game1->columns+1 || game1->gameBoard[r][c] == WALL || (wallPresent(game1,r,c,rows,columns) == TRUE)){
                   printf("%c", game1->gameBoard[r][c] );
                }
                //else if ((wallPresent(game1,r,c,rows,columns) == FALSE))
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
            /*else{
            switch(game1->gameBoard[r][c]){
            case NEVER:
                printf("%c", NEVER);
                break;
            default:
                printf("%c", SOMEPOINT);
                break;
            }
            //printf("%c", game1->board[r][c]);
        }*/
        }
        printf("\n");
    }
}
BOOL wallPresent(GAME * game1, int yPosition, int xPosition, int yLight, int xLight){
    BOOL result = FALSE;
    int i;
int minX, maxX, minY, maxY;
minX = min(xPosition, xLight);
maxX = max(minX, xPosition, xLight);
minY = min(yPosition, yLight);
maxY = max(minY, yPosition, yLight);
if(minX == maxX){
    for(i = minY + 1; i < maxY; i++){
        if(game1->gameBoard[i][minX] == WALL){
            return TRUE;
        }
    }
}
else if (minY == maxY){
     for(i = minX + 1; i < maxX; i++){
        if(game1->gameBoard[minY][i] == WALL){
            return TRUE;
        }
    }
}
else{
    double slope = (double)(yLight - yPosition)/(double)(xLight - xPosition);
    double intersect = yLight - (slope * xLight);
    for(i = minX + 1; i < maxX; i++){
            int y = slope * i + intersect;
        if(game1->gameBoard[y][i] == WALL){
            return TRUE;
            }
        }
    return FALSE;
    }
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
