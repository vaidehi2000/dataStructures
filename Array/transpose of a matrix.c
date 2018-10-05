#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], m, n, i, j;
    printf("Enter rows and columns of matrix: ");
    scanf("%d %d", &m, &n);

    printf("\nEnter elements of matrix:\n");
    for(i=0; i<m; ++i)
        for(j=0; j<n; ++j)
        {
            printf("Enter element a%d%d: ",i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    printf("\nEntered Matrix: \n");
    for(i=0; i<m; ++i)
        for(j=0; j<n; ++j)
        {
            printf("%d  ", a[i][j]);
            if (j == n-1)
                printf("\n\n");
        }

    for(i=0; i<m; ++i)
        for(j=0; j<n; ++j)
        {
            b[j][i] = a[i][j];
        }

    printf("\nTranspose of Matrix:\n");
    for(i=0; i< n; ++i)
        for(j=0; j<m; ++j)
        {
            printf("%d  ",b[i][j]);
            if(j==m-1)
                printf("\n\n");
        }

    return 0;
}
