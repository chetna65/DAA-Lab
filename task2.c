#include <stdio.h>
#include <string.h>

#define MAX 100

void findLRS(char S[]) 
{
    int n = strlen(S);
    int cost[n + 1][n + 1];
    
    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0)
                cost[i][j] = 0;
            else if (S[i - 1] == S[j - 1] && i != j)
                cost[i][j] = 1 + cost[i - 1][j - 1];
            else
                cost[i][j] = (cost[i - 1][j] > cost[i][j - 1]) ? cost[i - 1][j] : cost[i][j - 1];
        }
    }

    printf("\nCOST MATRIX:\n\n");
    printf("    ");
    for (int j = 0; j < n; j++)
        printf(" %c ", S[j]);
    printf("\n");

    for (int i = 0; i <= n; i++) 
    {
        if (i == 0)
            printf("  ");
        else
            printf("%c ", S[i - 1]);
        for (int j = 0; j <= n; j++) 
        {
            printf("%2d ", cost[i][j]);
        }
        printf("\n");
    }

    int index = cost[n][n];
    char lrs[index + 1];
    lrs[index] = '\0';

    int i = n, j = n;
    while (i > 0 && j > 0) 
    {
        if (cost[i][j] == cost[i - 1][j - 1] + 1 && S[i - 1] == S[j - 1] && i != j) 
        {
            lrs[--index] = S[i - 1];
            i--;
            j--;
        } 
        else if (cost[i - 1][j] > cost[i][j - 1])
            i--;
        else
            j--;
    }

    printf("\nLongest Repeating Subsequence (LRS) = %s\n", lrs);
    printf("Length of LRS = %d\n", cost[n][n]);
}

int main() 
{
    char S[] = "AABEBCDD";

    printf("Given String: %s\n", S);
    findLRS(S);

    return 0;
}
