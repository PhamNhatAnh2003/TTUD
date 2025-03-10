#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestCommonSubsequence(int *X, int n, int *Y, int m) {
    int dp[n + 1][m + 1];
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int X[n], Y[m];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    for (int j = 0; j < m; j++) {
        scanf("%d", &Y[j]);
    }

    printf("%d\n", longestCommonSubsequence(X, n, Y, m));
    return 0;
}
