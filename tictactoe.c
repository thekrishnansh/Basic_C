#include <stdio.h>
char board[3][3]={'1','2','3','4','5','6','7','8','9'}; //creating global matrix 
void printboard(char board[3][3]);    //for printing board
int checkvalidinput(int occupied[9],int input,int turn);    //to check the validity of the turn
int checkcondition();    //to check who won the game

int main()
{ 
    int player;    //for alternating the players
    int input;
    int turn;    //for taking the number of turns
    int game_end = 0;   //for ending the loop and game
    printf("the player 1 will have 'X'and player 2 will have 'O'");
    int occupied[9]={0,0,0,0,0,0,0,0,0};
    printboard(board);

    for(turn=1;turn<=9 && game_end == 0;turn++)
    {
        int player = turn % 2; //for changing players
        switch(player)
        {
            case  1:
                printf("Enter the position player 1: ");
                scanf("%d",&input);
                if((input >= 1 && input <=9) && checkvalidinput(occupied, input, turn)==1)
                { 
                    for (int i=0 ; i<3;i++)
                    {
                        for (int j=0;j<3;j++)
                        {
                            if(input==board[i][j]-48) //changing the character input to integer to compare
                            board[i][j] ='X';  //entering X in place of selected position

                        }
                    } 
                    if (checkcondition()==1) //to check if player 1 wins
                    {
                        printf("player 1 WINS");
                        game_end = 1;
                        printboard(board);
                    }
                    else 
                        printboard(board);
                }
                else   //input again for invalid or duplicate  inputs
                {
                    printf("Wrong Input.\n");
                    turn--;  // not skip chance
                }
                break;
            case 0: //same as player 1
                printf("Enter the position player 2: "); 
                scanf("%d",&input);
                if ((input >=1 && turn <=9) && checkvalidinput(occupied, input, turn)==1)
                {
                    for (int i=0 ; i<3;i++)
                    {
                        for (int j=0;j<3;j++)
                        {   
                    
                            if(input==board[i][j]-48) 
                                board[i][j] ='O';
                        }
                    } 
                        
                    if (checkcondition()==1) //to check if player 2 wins
                    {
                        printf("player 2 WINS");
                        game_end = 1;
                        printboard(board);
                    }
                    else 
                        printboard(board);
                }
                else
                {
                    printf("Wrong Input.\n");
                    turn--;
               
                }
               
                break;   
        }
        if (turn==9 && checkcondition()==0) //draw game
        {
            printf("THE GAME IS A DRAW");
        }
    }
}

void printboard(char board[3][3])
{
    printf("\033[H\033[J");// it clears console
    printf("\n");
    printf("\n");
    printf("TIC TAC TOE \n");
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkvalidinput(int occupied[9],int input, int turn)
{
    for(int i = 0; i < 9; i++)
    {
        if(input==occupied[i]) 
        return 0;        
    }
    occupied[turn-1]=input;
    return 1;
}

int checkcondition()
{ //first horizontal then vertical then diagonal

    if((board[0][0]==board[0][1]&&board[0][1]==board[0][2])||(board[1][0]==board[1][1]&&board[1][1]==board[1][2])
    ||(board[2][0]==board[2][1]&&board[2][1]==board[2][2])||(board[0][0]==board[1][0]&&board[1][0]==board[2][0])||
    (board[0][1]==board[1][1]&&board[1][1]==board[2][1])||(board[0][2]==board[1][2]&&board[1][2]==board[2][2])
    ||(board[0][0]==board[1][1]&&board[1][1]==board[2][2])||(board[2][0]==board[1][1]&&board[1][1]==board[0][2]))
        return 1;
    else
        return 0;
}  
