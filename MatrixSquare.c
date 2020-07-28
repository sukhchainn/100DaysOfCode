#include <stdio.h>

int M_square(int row, int col, int a[][col]) {
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            a[i][j] *= a[i][j];
}

int main() {
    int a[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row = 3, col = 3;

    M_square(row, col, a);

    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            printf("%d ", a[i][j]);

    return 0;
}
