#include <stdio.h>

#define INF 999

void main() {
    int i, j, n, v, k, min, u, c[20][20], s[20], d[20];

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix (Enter 999 for no edge): \n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &v);

    for(i = 1; i <= n; i++) {
        s[i] = 0;
        d[i] = c[v][i];
    }

    d[v] = 0;
    s[v] = 1;


    for(k = 2; k <= n; k++) {
        min = INF;
        for(i = 1; i <= n; i++) {
            if(s[i] == 0 && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        s[u] = 1;


        for(i = 1; i <= n; i++) {
            if(s[i] == 0) {
                if(d[i] > (d[u] + c[u][i])) {
                    d[i] = d[u] + c[u][i];
                }
            }
        }
    }


    printf("\nThe shortest distances from vertex %d are:\n", v);
    for(i = 1; i <= n; i++) {
        if(d[i] == INF) {
            printf("%d --> %d = No Path\n", v, i);
        } else {
            printf("%d --> %d = %d\n", v, i, d[i]);
        }
    }
}
