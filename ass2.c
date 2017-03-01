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
            int r=0, c=0;
            for(i=0;i<game1.rows;i++){
                for(j=0;j<game1.columns;j++){
                        char ch = fgetc(file);
                        game1.board[i][j] = ch;
                    if(ch == '@'){
                        r = i;
                        c = j;
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
void print(GAME *game1,int rows, int columns)
{
    //printf("%s", game1->title);
    int r, c;
    double distance;
    for(r = 0; r < game1->rows; r++)
    {
        for(c = 0; c < game1->columns; c++){
                distance = sqrt(pow(((double)(r-rows)),2) + pow(((double)(c-columns)),2));
            if((distance < 1.00) && (game1->board[r][c] != '~')){
                    game1->board[r][c] = '%';
                printf("%c", '%');
            }
            else if ((distance < 2.00) && (game1->board[r][c] != '~')){
                game1->board[r][c] = '#';
                printf("%c", '#');
            }
            else if ((distance < 3.00) && (game1->board[r][c] != '~')){
                    game1->board[r][c] = '=';
                printf("%c", '=');
            }
            else if ((distance < 4.00) && (game1->board[r][c] != '~')){
                game1->board[r][c] = '-';
                printf("%c", '-');
            }
            else{
            switch(game1->board[r][c]){
            /*case '@':
                printf("%c", '%');
                break;*/
            case '~':
                printf("%c", '!');
                break;
            case ' ':
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

