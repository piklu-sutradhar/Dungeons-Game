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


//-------------------------------------------------------------------------------------
// CONSTANTS and TYPES
//-------------------------------------------------------------------------------------
typedef struct game{
    char title[50];
    char board[100][100];
    int columns;
    int rows;
    int moves;
}Game;
//-------------------------------------------------------------------------------------
// VARIABLES
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// PROTOTYPES
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// FUNCTIONS
//-------------------------------------------------------------------------------------

int main( int argc, char *argv[] )
{
    Game game;
    FILE *file;
    char *title;
    if(argc < 2){
        printf("Enter the file name");
        return EXIT_SUCCESS;
    }
    else{
        file = fopen(argv[1],"r");
        //char line[100];
        fgets(game->title, 100, file);
        fscanf(file,"%d %d %d",game->rows, game->columns, game)
        while(line != EOF){
            char c = fgetc(file);
            if(c == '*'){
                while(fgetc(file)!= '\n'){
                  title = fgetc(file);   
                }
                title = fgetc(file);
            }
        }
  return EXIT_SUCCESS;
}
