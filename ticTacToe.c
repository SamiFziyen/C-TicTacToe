#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char player1[15], player2[15];
char plays[9] = "         ";
int filledslots[9];
int winner = 0;  // this is for while loop for the game to continue as long as there is no winner.
int chosenslot;
char playAgain = 'O';
int playsLimit = 9;
void player1Turn(){
    printf("\e[1;1H\e[2J");
    printf("<====================X=| TicTacToe |=O====================>\n\n");
    printf("                        ___ ___ ___                      \n");
    printf("                       | %c | %c | %c |                       \n", plays[0],plays[1],plays[2]);
    printf("                       |___|___|___|                       \n");
    printf("                       | %c | %c | %c |                       \n", plays[3],plays[4],plays[5]);
    printf("                       |___|___|___|                       \n");
    printf("                       | %c | %c | %c |                       \n", plays[6],plays[7],plays[8]);
    printf("                       |___|___|___|                       \n\n");
    printf("<=========================================================>\n\n");
    printf("   -=> %s's turn ' X ' : \n\n", player1);
    printf("-=> Please insert A number (1-9) : ");
    scanf("%d", &chosenslot);
    while (filledslots[chosenslot - 1] != 0 || chosenslot > 9 || chosenslot <= 0){
        printf("\nThe chosen slot has already been selected before or is out of range.\n Please re-insert a new number :");
        scanf("%d", &chosenslot);
    }
    plays[chosenslot - 1] = 'X';
    filledslots[chosenslot - 1] = 1;
    playsLimit--;
}
void checkwinner(){
    // Diagonal checks
     if (filledslots[0] != 0 && filledslots[0] == filledslots[4] && filledslots[0] == filledslots[8]){
         if (filledslots[0] ==  1){
                winner = 1;
            }else{ winner = 2; } 
            return;  
    }
    if (filledslots[2] != 0 && filledslots[2] == filledslots[4] && filledslots[2] == filledslots[6]){
        if (filledslots[2] ==  1){
                winner = 1;
            }else{ winner = 2; }
            return; 
    }
    int x = 0;
    int y = 0;
    for (int i = 0; i < 3; i++)
    {
        // horizontal check 
        if (filledslots[x] != 0 && filledslots[x] == filledslots[x+1] && filledslots[x] == filledslots[x+2]){
            if (filledslots[x] ==  1){
                winner = 1;
            }else{ winner = 2; } 
            return;
        } else { x = x + 3;}
        // Vertical Check
        if (filledslots[y] != 0 && filledslots[y] == filledslots[y+3] && filledslots[y] == filledslots[y+6] ){
            if (filledslots[y] ==  1){
                winner = 1;
            }else{ winner = 2; } 
            return;
        }else { y++; }
    }
}
void player2Turn(){
    printf("\e[1;1H\e[2J");
    printf("<====================X=| TicTacToe |=O====================>\n\n");
    printf("                        ___ ___ ___                      \n");
    printf("                       | %c | %c | %c |                       \n", plays[0],plays[1],plays[2]);
    printf("                       |___|___|___|                       \n");
    printf("                       | %c | %c | %c |                       \n", plays[3],plays[4],plays[5]);
    printf("                       |___|___|___|                       \n");
    printf("                       | %c | %c | %c |                       \n", plays[6],plays[7],plays[8]);
    printf("                       |___|___|___|                       \n\n");
    printf("<=========================================================>\n\n");
    printf("   -=> %s's turn ' O ' : \n\n", player2);
    printf("-=> Please insert A number (1-9) : ");
    scanf("%d", &chosenslot);
    while (filledslots[chosenslot - 1] != 0 || chosenslot > 9 || chosenslot <= 0){
        printf("\nThe chosen slot has already been selected before.\n Please re-insert a new number :");
        scanf("%d", &chosenslot); 
    }
    plays[chosenslot - 1] = 'O';
    filledslots[chosenslot - 1] = 2;
    playsLimit--;
}
void displayWinner(){
    printf("\e[1;1H\e[2J");
    printf("<====================X=| TicTacToe |=O====================>\n\n");
    printf("                        ___ ___ ___                      \n");
    printf("                       | %c | %c | %c |                       \n", plays[0],plays[1],plays[2]);
    printf("                       |___|___|___|                       \n");
    printf("                       | %c | %c | %c |                       \n", plays[3],plays[4],plays[5]);
    printf("                       |___|___|___|                       \n");
    printf("                       | %c | %c | %c |                       \n", plays[6],plays[7],plays[8]);
    printf("                       |___|___|___|                       \n\n");
    printf("<=========================================================>\n\n");
    if (winner == 1)
    {
       printf(" -=> The winner is : %s\n\n", player1);
    } else if (winner == 2){
        printf(" -=> The winner is : %s\n\n", player2);
     }
    printf("     Do you wish to play again ? (O/N) : ");
    scanf(" %c", &playAgain); // leaving a blank space before the %c otherwise it does not work.
    
}
void ticTacToe(){
    printf("\e[1;1H\e[2J");
    printf("<====================X=| TicTacToe |=O====================>\n\n");
    printf("                        ___ ___ ___                      \n");
    printf("                       | T | I | C |                       \n");
    printf("                       |___|___|___|                       \n");
    printf("                       | T | A | C |                       \n");
    printf("                       |___|___|___|                       \n");
    printf("                       | T | O | E |                       \n");
    printf("                       |___|___|___|                       \n\n");
    printf("<=========================================================>\n\n");
    printf(" -=> Insert player 1 Name : ");
    scanf("%s", player1);
    printf(" -=> Insert player 2 Name : ");
    scanf("%s", player2);
    printf("\e[1;1H\e[2J");
    printf("<====================X=| TicTacToe |=O====================>\n\n\n");
    printf("                  -=> !! Get ready !! <=-\n\n");
    printf("-=> %s plays as ' X ' .\n\n", player1);
    printf("-=> %s plays as ' O ' .\n\n", player2);
    printf("<=========================================================>\n\n");
    system("pause");
    
    // handling turns

    while(playsLimit > 0 && winner == 0){
       player1Turn();
       checkwinner();
       if (playsLimit > 0 && winner == 0){
       player2Turn();
       checkwinner();
       }
    }

    // checking if the game ended in a draw or a win

    if (winner != 0)
    {
        displayWinner();
    } else {
         printf("\e[1;1H\e[2J");
         printf("<====================X=| TicTacToe |=O====================>\n\n");
        printf("                        ___ ___ ___                      \n");
        printf("                       | %c | %c | %c |                       \n", plays[0],plays[1],plays[2]);
        printf("                       |___|___|___|                       \n");
        printf("                       | %c | %c | %c |                       \n", plays[3],plays[4],plays[5]);
        printf("                       |___|___|___|                       \n");
        printf("                       | %c | %c | %c |                       \n", plays[6],plays[7],plays[8]);
        printf("                       |___|___|___|                       \n\n");
        printf("<=========================================================>\n\n");
        printf(" -=> The game ended in a draw !\n\n     Do you wish to play again ? (O/N) : ");
        scanf(" %c", &playAgain); // leaving a blank space before the %c otherwise it does not work.
    }

    // For replayability 

    if (playAgain == 'O'){
        for (int i = 0; i < 9; i++)
        {
            plays[i] = ' ';
        }
        for (int i = 0; i < 9; i++){filledslots[i] = 0;}
        winner = 0;  // this is for while loop for the game to continue as long as there is no winner.
        playsLimit = 9;
    }
}
int main()
{
    while (playAgain == 'O'){
        ticTacToe();
    }
}