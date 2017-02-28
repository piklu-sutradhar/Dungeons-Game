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
struct game{
    char title[50];
    char board[100][100];
    int columns;
    int rows;
    int moves;
};
//-------------------------------------------------------------------------------------
// VARIABLES
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// PROTOTYPES
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// FUNCTIONS
//-------------------------------------------------------------------------------------
void print(struct game *game1);
int main( int argc, char *argv[] )
{
    struct game game1;
    FILE *file = NULL;
    char *title;
//    if(argc < 2){
//        printf("Enter the file name");
//        return EXIT_SUCCESS;
//    }
   // else{
        file = fopen("sample.txt","r");
        char line[100];
        fgets(line, 100, file);
        printf("%s",line);
	    fscanf(file,"%d %d %d",&game1.rows, &game1.columns, &game1.moves);
        int r, c;
        for(r = 0; r < game1.rows; r++){
            for(c = 0; c < game1.columns; c++){
                game1.board[r][c] = fgetc(file);
                printf("%c",game1.board[r][c]);
            }
        }
        //file.close();
    //}
    print(&game1);
      return EXIT_SUCCESS;
}
void print(struct game *game1){
printf("%s", game1->title);
        int r, c;
        for(r = 0; r < game1->rows; r++){
            for(c = 0; c < game1->columns; c++){
                printf("%c", game1->board[r][c]);
            }
            printf("\n");
        }
}

