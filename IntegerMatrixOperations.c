#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
    int **matrix;
}  Matrix;

Matrix M_create(int row, int col)
{
    Matrix M;
    M.row = row;
    M.col =col;

    M.matrix = (int **) calloc(row, sizeof(int *));
    for (int I=0; I<row;I++)
        M.matrix[I] = (int *) calloc(col, sizeof(int));

    return M;
}

void M_destroy(Matrix M) 
{
    for (int I=0;I<M.row;I++)
        free(M.matrix[I]);
    free(M.matrix);
}

Matrix M_multiply(Matrix M1, Matrix M2)
{
    if (M1.col == M2.row)
    {
        Matrix M = M_create(M1.row, M2.col);
        int constant = M1.col;
        for (int j=0; j<M.row; j++) {
            for (int k=0; k<M.col; k++) {
                for (int i=0; i<constant; i++) {
                    M.matrix[j][k] += (M1.matrix[j][i] *
                                       M2.matrix[i][k]);
                }
            }
        }
        return M;
    } else
        printf("Matrices can't be multiplied\n");
}

Matrix M_add(Matrix M1, Matrix M2)
{
    if (M1.row == M2.row &&
        M1.col == M2.col) 
    {
        int row = M1.row;
        int col = M1.col;
        Matrix M = M_create(row, col);
        for (int j=0; j<row; j++)
            for (int k=0; k<col; k++)
                M.matrix[j][k] = M1.matrix[j][k] + 
                                 M2.matrix[j][k];
        return M;
    } else
        printf("Matrices aren't compatible for addition\n");
}

Matrix M_subtract(Matrix M1, Matrix M2)
{
    if (M1.row == M2.row &&
        M1.col == M2.col) 
    {
        int row = M1.row;
        int col = M1.col;
        Matrix M = M_create(row, col);
        for (int j=0; j<row; j++)
            for (int k=0; k<col; k++)
                M.matrix[j][k] = M1.matrix[j][k] - 
                                 M2.matrix[j][k];
        return M;
    } else
        printf("Matrices aren't compatible for subtraction\n");
}

int main()
{
    Matrix M[3];
    for (int I=0; I<3; I++)
        M[I] = M_create(2, 2);

    for (int i=0; i<3; i++)
        for (int j=0; j<M[i].row; j++)
            for (int k=0; k<M[i].col; k++)
                M[i].matrix[j][k] = k+1;
    
    M[2] = M_multiply(M[0], M[1]);

    for (int i=0; i<3; i++)
        for (int j=0; j<M[i].row; j++) {
            for (int k=0; k<M[i].col; k++)
                printf("%d ", M[i].matrix[j][k]);
            printf("\n");
        }

    return 0;
}
