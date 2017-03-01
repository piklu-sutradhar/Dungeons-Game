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

#define LINE_LENGTH 50
//-------------------------------------------------------------------------------------
// CONSTANTS and TYPES
//-------------------------------------------------------------------------------------
int ROWS = 100;
int COLUMNS = 100;
int MOVES = 100;
typedef struct game
{
    char title[LINE_LENGTH];
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
void print(GAME *game1);
int main( int argc, char *argv )
{
    GAME game1;
    char firstChar;
    char title[LINE_LENGTH];
    FILE * file;
    file = fopen("std.txt.txt", "r" );
    firstChar = fgetc(file);
    while(firstChar){
        if(firstChar == '*'){
            int i,j;
            fgets(game1.title,LINE_LENGTH,file);
            printf("%s", game1.title);
            fscanf(file, "%d %d %d", &game1.rows, &game1.columns, &game1.moves);
            printf("%d %d %d",game1.rows, game1.columns, game1.moves);
            char command[100];
            for(i=0;i<game1.rows;i++){
                for(j=0;j<game1.columns;j++){
                    game1.board[i][j] = fgetc(file);
                    printf("%c",game1.board[i][j])
                }
                fgetc(file);
            }
            fgetc(file);
            fgets(command, 100, file);
        }
        firstChar = fgetc(file);
    }
    fclose(file);
    return EXIT_SUCCESS;
}
void setBoard(GAME *game1; int rows, int columns){
    game1->board = char ga

}
void print(struct game *game1)
{
    printf("%s", game1->title);
    int r, c;
    for(r = 0; r < game1->rows; r++)
    {
        for(c = 0; c < game1->columns; c++)
        {
            printf("%c", game1->board[r][c]);
        }
        printf("\n");
    }
}

