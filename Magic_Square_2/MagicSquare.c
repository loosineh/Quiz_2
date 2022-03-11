#include <stdio.h>
int main()
{
    int square[50][50];
    int num1, num2;
    int size;
    int rowSum, columnSum, diagonalSum;
    int magic = 0;

    printf("Enter the order of the matrix:\n");
    scanf("%d %d", &num1,&num2);
    if(num1 == num2)
    {
        printf("Enter the elements of matrix:\n");
        for(int i = 0; i < num1; i++)
        {
            for(int j = 0; j < num2; j++)
            {
                scanf("%d", &square[i][j]);
            }
        }

        printf("\n\nMatrix is:\n");
        for(int i = 0; i < num1; i++)
        {
            for(int j = 0; j < num2; j++)
            {
                printf("%3d\t", square[i][j]);
            }
            printf("\n");
        }

        //Calculate sum of diagonal 
        diagonalSum = 0;
        for(int i = 0; i < num1; i++)
        {
            for(int j = 0; j < num2; j++)
            {
                if(i==j)
                {
                    diagonalSum = diagonalSum + square[i][j];
                }
            }
        }

        //Calculate sum of row
        for(int i = 0; i < num1; i++)
        {
            rowSum = 0;
            for(int j = 0; j < num2; j++)
            {
                rowSum = rowSum + square[i][j];
            }
            if(rowSum != diagonalSum)
            {
                printf("\nThe matrix is not a magic square!");
            }
        }

        //Calculate sum of column
        for(int i = 0; i < num1; i++)
        {
            columnSum = 0;
            for(int j = 0; j < num2; j++)
            {
                columnSum = columnSum + square[i][j];
            }
            if(columnSum != diagonalSum)
            {
                printf("\nThe matrix is not a magic square!");
            }
        }

        printf("\nThe matrix is a magic square!");
    }
    else
    {
        printf("\n\nPlease enter the square matrix order\n\n");
    }
    return 0;
}