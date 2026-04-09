#include <stdio.h>

//function for Muchiko
void movingAverage(int arr[], int n) {
    printf("\nMuchiko Filter (Moving Average):\n");

    for (int i = 1; i < n - 1; i++) {
        float avg = (arr[i-1] + arr[i] + arr[i+1]) / 3.0;
        printf("%.2f ", avg);
    }
    printf("\n");
}

//function to find median of 3 numbers
int median(int a, int b, int c) {
    if ((a >= b && a <= c) || (a <= b && a >= c))
        return a;
    else if ((b >= a && b <= c) || (b <= a && b >= c))
        return b;
    else
        return c;
}

//function for Sanchiko
void medianFilter(int arr[], int n) {
    printf("\nSanchiko Filter (Median):\n");

    for (int i = 1; i < n - 1; i++) {
        int m = median(arr[i-1], arr[i], arr[i+1]);
        printf("%d ", m);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of readings: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter sensor values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    movingAverage(arr, n);
    medianFilter(arr, n);

    return 0;
}
