#include <stdio.h>


int n = 5;

int p[10] = {3, 3, 2, 5, 1};
int w[10] = {10, 15, 10, 12, 8};


int W = 10;

int main() {
    int cur_w;
    float tot_v = 0.0;
    int i, maxi;
    int used[10] = {0};

    cur_w = W;

    while (cur_w > 0) {
        maxi = -1;
        for (i = 0; i < n; ++i) {
            if (used[i] == 0 && (maxi == -1 || (float)p[i] / w[i] > (float)p[maxi] / w[maxi])) {
                maxi = i;
            }
        }

        used[maxi] = 1;
        if (w[maxi] <= cur_w) {

            cur_w -= w[maxi];
            tot_v += p[maxi];
            printf("Added object %d (%d, %d) completely in the bag. Space left: %d.\n", maxi + 1, w[maxi], p[maxi], cur_w);
        } else {

            tot_v += (float)p[maxi] * cur_w / w[maxi];
            printf("Added %.2f%% (%d, %d) of object %d in the bag.\n", (float)(cur_w * 100) / w[maxi], w[maxi], p[maxi], maxi + 1);
            cur_w = 0;
        }
    }

    printf("Filled the bag with objects worth %.2f.\n", tot_v);

    return 0;
}
