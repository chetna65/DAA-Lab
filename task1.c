#include <stdio.h>
#include <string.h>

#define MAX 100

void findLCS(char X[], char Y[]) 
{
    int m = strlen(X);
    int n = strlen(Y);
    int cost[m + 1][n + 1];
    char dir[m + 1][n + 1];
    
    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0) 
            {
                cost[i][j] = 0;
                dir[i][j] = '-';
            } 
            else if (X[i - 1] == Y[j - 1]) 
            {
                cost[i][j] = cost[i - 1][j - 1] + 1;
                dir[i][j] = 'D';
            } 
            else if (cost[i - 1][j] >= cost[i][j - 1]) 
            {
                cost[i][j] = cost[i - 1][j];
                dir[i][j] = 'U';
            } 
            else 
            {
                cost[i][j] = cost[i][j - 1];
                dir[i][j] = 'L';
            }
        }
    }

    printf("\nCOST MATRIX WITH DIRECTIONS:\n\n");
    printf("     ");
    for (int j = 0; j < n; j++)
    {
        printf("  %c ", Y[j]);
    }
    printf("\n");

    for (int i = 0; i <= m; i++) 
    {
        if (i == 0)
        {
            printf("  ");
        }
        else
        {
            printf("%c ", X[i - 1]);
        }
        for (int j = 0; j <= n; j++) 
        {
            printf("%2d%c ", cost[i][j], dir[i][j]);
        }
        printf("\n");
    }

    int lcsLength = cost[m][n];
    printf("\nLength of LCS = %d\n", lcsLength);

    char lcsSeq[MAX];
    int i = m, j = n, index = lcsLength;
    lcsSeq[index] = '\0';

    while (i > 0 && j > 0) 
    {
        if (dir[i][j] == 'D') 
        {
            lcsSeq[--index] = X[i - 1];
            i--;
            j--;
        } 
        else if (dir[i][j] == 'U')
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("LCS = %s\n", lcsSeq);
}

int main() 
{
    char X[] = "AGCCCTAAGGGCTACCTAGCTT";
    char Y[] = "GACAGCCTACAAGCGTTAGCTTG";

    printf("Sequence X: %s\n", X);
    printf("Sequence Y: %s\n", Y);

    findLCS(X, Y);

    return 0;
}
