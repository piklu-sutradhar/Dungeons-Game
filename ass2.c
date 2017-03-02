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
typedef enum state {NEVER,SOMEPOINT,WALL,LIGHTSOURCE} State;
typedef struct game
{
    char title[LINE_LENGTH];
    int gameBoard[100][100];
    char board[100][100];
    int columns;
    int rows;
    int moves;
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
void print(GAME *game1,int r,int c);
int main( int argc, char *argv )
{
    GAME game1;
    char firstChar;
    char title[LINE_LENGTH];
    FILE * file;
    file = fopen("data.txt.txt", "r" );
    firstChar = fgetc(file);
    while(firstChar){
        if(firstChar == '*'){
            int i,j;
            fgets(game1.title,LINE_LENGTH,file);
            //printf("%s", game1.title);
            fscanf(file, "%d %d %d", &game1.rows, &game1.columns, &game1.moves);
            fgetc(file);
            //printf("%d %d %d",game1.rows, game1.columns, game1.moves);
            char command[100];
            //game1.gameBoard = int[game1.rows][game1.columns];
            int r=0, c=0;
            for(i=0;i<game1.rows;i++){
                for(j=0;j<game1.columns;j++){
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
/*void setBoard(GAME *game1; int rows, int columns){
    game1->board = char ga

*/
/*void printBoard(GAME *game1, int rows, int columns){
//char board[rows + 2][columns + 2];
int r, c;
    for(r = 0; r < game1->rows+2; r++)
    {
        for(c = 0; c < game1->columns+2; c++){

}*/
void print(GAME *game1,int rows, int columns)
{
    //printf("%s", game1->title);
    int r, c;
    double distance;
    for(r = 0; r < game1->rows+2; r++)
    {
        for(c = 0; c < game1->columns+2; c++){
                distance = sqrt(pow(((double)(r-rows+1)),2) + pow(((double)(c-columns+1)),2));
                if ((r == 0 && c == 0) || (r == 0 && c == game1->columns+1) || (r == game1->rows+1 && c == 0) ||
                (r == game1->rows+1 && c == game1->columns+1)){
                printf("%c", '+');
                }
                else if(r == 0 || r == game1->rows+1){
                  printf("%c", '-');
                }
                else if(c == 0 || c == game1->columns+1){
                  printf("%c", '|');
                }
                //distance = sqrt(pow(((double)(r-rows)),2) + pow(((double)(c-columns)),2));
            else if((distance < 1.00) && (game1->gameBoard[r][c] != WALL)){
                    game1->gameBoard[r-1][c] = SOMEPOINT;
                printf("%c", '%');
            }
            else if ((distance < 2.00) && (game1->gameBoard[r][c] != WALL)){
               game1->gameBoard[r][c] = SOMEPOINT;
                printf("%c", '#');
            }
            else if ((distance < 3.00) && (game1->gameBoard[r][c] != WALL)){
                 game1->gameBoard[r][c] = SOMEPOINT;
                printf("%c", '=');
            }
            else if ((distance < 4.00) && (game1->gameBoard[r][c] != WALL)){
                game1->gameBoard[r][c] = SOMEPOINT;
                printf("%c", '-');
            }
            else{
            switch(game1->gameBoard[r][c]){
            /*case '@':
                printf("%c", '%');
                break;*/
            case WALL:
                printf("%c", '!');
                break;
            case NEVER:
                printf("%c", ' ');
                break;
            default:
                printf("%c", ',');
                break;
            }
            //printf("%c", game1->board[r][c]);
        }
        }
        printf("\n");
    }
}

