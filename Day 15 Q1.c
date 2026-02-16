#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int sum = 0;
    int matrix[m][n];

    // Read matrix elements
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate primary diagonal sum
    int limit = (m < n) ? m : n;
    for(int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    // Print result
    printf("%d\n", sum);

    return 0;
}
