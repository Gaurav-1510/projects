//Rock paper scissor..
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //a library in c

int generateRandomNumber(int n) // step one generation of function  to generte a random number for the game..
{
    srand(time(NULL)); //srands takes seeds as input and its defined inside stdlib.h library...
    return rand() % n;
}

int greater(char char1, char char2)
{
    // for rock paper scissior returns 1 if c1>c2 and 0 otherwise if c1==c2  it will give -1
    if (char1 == char2)
    {
        return -1;
    }

    else if ((char1 == 'r') && (char2 == 's'))
    {
        return 1;
    }
    else if ((char2 == 'r') && (char1 == 's'))
    {
        return 0;
    }

    else if ((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else if ((char2 == 'p') && (char1 == 'r'))
    {
        return 0;
    }
    else if ((char1 == 's') && (char2 == 'p'))
    {
        return 1;
    }
    else if ((char2 == 's') && (char1 == 'p'))
    {
        return 0;
    }
}

int main()
{
    char name[15];
    int playerscore = 0, compscore = 0, temp;
    char dict[] = {'r', 'p', 's'};
    char playerChar, compChar;
    printf("\n");
    printf("~~~welcome to the Rock,Paper,Scissor~~~\n\n");
    printf("enter the name of player 1  your opponent player 2 is by default your system:\n");
    scanf("%s", name);

    for (int i = 0; i < 3; i++)
    {
        //take player1 input....
        printf("%s turn : \n", name);
        printf("choose 1 for Rock and , 2 for  Paper, 3 for  Scissor:\n");
        scanf("%d", &temp);
        getchar();
        playerChar = dict[temp - 1];
        printf(" %s choose %c \n", name, playerChar);
        // generete computer input...
        printf("computer's turn:\n");
        printf("choose 1 for Rock  , 2 for  Paper, 3 for  Scissor\n");
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];
        printf(" system choose %c \n", compChar);

        if (greater(compChar, playerChar) == 1)
        {
            compscore += 1;
            printf("sytem got it!\n");
        }
        else if (greater(compChar, playerChar) == -1)
        {
            compscore += 1;
            playerscore += 1;
            printf(" ayye its a draw!\n");
        }
        else
        {
            playerscore += 1;
            printf(" %s you played well !\n", name);
        }
        printf(" %s : %d \n system:%d\n\n", name, playerscore, compscore);
    }
    if (playerscore > compscore)
    {
        printf("congratulations  %s you  won the game :\n", name);
    }
    else if (playerscore < compscore)
    {
        printf("oops better try next time system won:\n");
    }
    else
    {
        printf("lol it's a draw :\n");
    }
    return 0;
}
