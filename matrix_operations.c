#include <stdio.h>

void inputMatrix(int mat[10][10], int rows, int cols);
void displayMatrix(int mat[10][10], int rows, int cols);
void addMatrix(int A[10][10], int B[10][10], int rows, int cols);
void multiplyMatrix(int A[10][10], int B[10][10], int r1, int c1, int c2);
void transposeMatrix(int mat[10][10], int rows, int cols);

int main()  {
    int choice;
    int A[10][10], B[10][10];
    int r1, c1, r2, c2;

    do
    {
        printf("\n===== MATRIX OPERATIONS =====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter rows and columns of Matrix B: ");
                scanf("%d%d", &r2, &c2);

                if(r1 != r2 || c1 != c2)
                {
                    printf("Addition is not possible.\n");
                    break;
                }

                printf("Enter elements of Matrix A:\n");
                inputMatrix(A, r1, c1);

                printf("Enter elements of Matrix B:\n");
                inputMatrix(B, r2, c2);

                addMatrix(A, B, r1, c1);
                break;

            case 2:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter rows and columns of Matrix B: ");
                scanf("%d%d", &r2, &c2);

                if(c1 != r2)
                {
                    printf("Multiplication is not possible.\n");
                    break;
                }

                printf("Enter elements of Matrix A:\n");
                inputMatrix(A, r1, c1);

                printf("Enter elements of Matrix B:\n");
                inputMatrix(B, r2, c2);

                multiplyMatrix(A, B, r1, c1, c2);
                break;

            case 3:
                printf("Enter rows and columns of Matrix: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter matrix elements:\n");
                inputMatrix(A, r1, c1);

                transposeMatrix(A, r1, c1);
                break;

            case 4:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}

void inputMatrix(int mat[10][10], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &mat[i][j]);
        }}}

void displayMatrix(int mat[10][10], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int A[10][10], int B[10][10], int rows, int cols)
{
    int C[10][10];
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nAddition Result:\n");
    displayMatrix(C, rows, cols);
}

void multiplyMatrix(int A[10][10], int B[10][10], int r1, int c1, int c2)
{
    int C[10][10];
    int i, j, k;

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            C[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMultiplication Result:\n");
    displayMatrix(C, r1, c2);
}

void transposeMatrix(int mat[10][10], int rows, int cols)
{
    int i, j;

    printf("\nTranspose Matrix:\n");

    for(i = 0; i < cols; i++)
    {
        for(j = 0; j < rows; j++)
        {
            printf("%d\t", mat[j][i]);
        }
        printf("\n");
    }
}
