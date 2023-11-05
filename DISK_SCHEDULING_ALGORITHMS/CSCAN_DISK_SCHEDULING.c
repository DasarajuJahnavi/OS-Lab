#include <stdio.h>

int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], p, sum = 0, tot;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of the head: ");
    scanf("%d", &h);

    printf("Enter the total tracks: ");
    scanf("%d", &tot);

    t[0] = 0;
    t[1] = h;
    t[2] = tot - 1;

    printf("Enter the tracks:\n");
    for (i = 3; i <= n + 2; i++)
        scanf("%d", &t[i]);

    for (i = 0; i <= n + 2; i++) {
        for (j = 0; j <= (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    for (i = 0; i <= n + 2; i++) {
        if (t[i] == h) {
            j = i;
            k = i;
        }
    }

    p = 0;
    while (t[j] != tot - 1) {
        atr[p] = t[j];
        j++;
        p++;
    }

    atr[p] = t[j];
    p++;
    i = 0;

    while (p != n + 3 && t[i] != t[h]) {
        atr[p] = t[i];
        i++;
        p++;
    }

    for (j = 0; j < n + 2; j++) {
        if (atr[j] > atr[j + 1])
            d[j] = atr[j] - atr[j + 1];
        else
            d[j] = atr[j + 1] - atr[j];
        sum += d[j];
    }

    printf("Total header movements: %d\n", sum);
    printf("Average is %f\n", (float)sum / n);

    return 0;
}
