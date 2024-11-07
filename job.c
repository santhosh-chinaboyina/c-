#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int board[MAX][MAX];

bool isSafe(int row, int col, int n) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int n, int col) {
    if (col >= n)
        return true;
    int i;
    for (i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1;
            if (solveNQUtil(n, col + 1))
                return true;
            board[i][col] = 0;
        }
    }

    return false;
}

void printSolution(int n) {
    int i;
    for (i = 0; i < n; i++) {
        int j;
        for ( j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (solveNQUtil(n, 0) == false) {
        printf("Solution does not exist\n");
    } else {
        printSolution(n);
    }

    return 0;
}
