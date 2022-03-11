#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int square[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d", square[i][j]);
        }
        printf("\n");
    }
}

int isMagicSquare(int square[3][3])
{
    //Storing sum of first row in 'sum' and comparing it with other values.
    int sum = 0;
    int temp = 0;
    
    //To check first row
    for(int i = 0; i < 3; i++)
    {
        sum = sum + square[0][i];
    }

    //To check second and third row
    for(int i = 1; i < 3; i++)
    {
        temp = 0;
        for(int j = 0; j < 3; j++)
        {
            temp = temp + square[i][j];
        }
        if(temp != sum)
        {
            return 0;
        }
    }

    //To check all columns
    for(int i = 0; i < 3; i++)
    {
        temp = 0; 
        for(int j = 0; j < 3; j++)
        {
            temp = temp + square[j][i];
        }
        if(temp != sum)
        {
            return 0;
        }
    }

    //To check diagonals
    temp = 0;
    for(int i = 0; i < 3; i++)
    {
        temp = temp + square[i][i];
    }
    if(temp != sum)
    {
        return 0;
    }

    temp = square[0][2] + square[1][1] + square[2][0];
    if(temp != sum)
    {
        return 0;
    }

    return 1;
}

int main()
{
    int square[3][3];
    int count = 0;
        count++;
        int number[10] = {0};
        srand(time(0) + count); //Using random in order to get new values each time.
        for(int i = 0; i < 3; i++)
        {
            for(int j = 3; j < 3; j++)
            {
                int n = rand() % 9 + 1;
                while(number[n])
                {
                    n = rand() % 9 + 1;
                }
                square[i][j] = n;
                number[n] = 1;
            }
        }
        
        //If a magic square is found then end the loop.
        if(isMagicSquare(square) == 1)
        {
            return EXIT_FAILURE;
        }
        printf("Number of squares: %d\n", count);
        print(square);
    return 0;
}