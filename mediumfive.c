#include <stdio.h>
#include <stdlib.h>

int main() {
    int L1, L2, L3, W1, W2, W3, D, n;

    printf("Enter limits L1 L2 L3: ");
    scanf("%d %d %d", &L1, &L2, &L3);

    printf("Enter wear factors W1 W2 W3: ");
    scanf("%d %d %d", &W1, &W2, &W3);

    printf("Enter number of targets: ");
    scanf("%d", &n);

    int targets[100];
    printf("Enter targets:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &targets[i]);
    }

    printf("Enter D: ");
    scanf("%d", &D);

    //starting position
    int prevI = 0, prevM = 0, prevO = 0, totalCost = 0;

    for (int t = 0; t < n; t++) {
        int target = targets[t];

        int minCost = 1000000;
        int bestI = 0, bestM = 0, bestO = 0;

        //trying all combinations
        for (int i = 0; i <= L1; i++) {
            for (int j = 0; j <= L2; j++) {
                int k = target - i - j;

                if (k < 0 || k > L3) continue;

                if (abs(i - k) > D) continue;

                int cost = abs(i - prevI) * W1 +
                           abs(j - prevM) * W2 +
                           abs(k - prevO) * W3;

                if (cost < minCost) {
                    minCost = cost;
                    bestI = i;
                    bestM = j;
                    bestO = k;
                }
            }
        }

        totalCost += minCost;

        //updating the previous position
        prevI = bestI;
        prevM = bestM;
        prevO = bestO;
    }

    printf("\nMinimum total wear cost: %d\n", totalCost);

    return 0;
}
