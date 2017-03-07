Commands to compile and run my .c file:


To compile without defining the NDEBUG and ANIMATION
1: clang -Wall game.c -o game

To run without defining the NDEBUG and ANIMATION:
2: ./game fileName
Ex: ./game data.txt


To compile with defining the NDEBUG
1:  clang -Wall -DNDEBUG game.c -o game

To run with defining the NDEBUG:
2: ./game fileName
Ex: ./game data.txt


To compile with defining the ANIMATION
1:  clang -Wall -DANIMATION game.c -o game

To run with defining the ANIMATION:
2: ./game fileName
Ex: ./game data.txt


To compile with defining both the NDEBUG and ANIMATION
1:  clang -Wall -DNDEBUG -DANIMATION game.c -o game
or
2:  clang -Wall -DANIMATION -DNDEBUG game.c -o game

To run with defining both the NDEBUG and ANIMATION
2: ./game fileName
Ex: ./game data.txt