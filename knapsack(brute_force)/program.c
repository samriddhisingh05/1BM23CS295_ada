#include <stdio.h>
#include <math.h>

void knapsack(int weights[], int values[], int n, int capacity) {
    int max_value = 0;
    int selected_items = 0;

    for (int subset = 0; subset < (1 << n); subset++) {
        int total_weight = 0, total_value = 0;
        for (int i = 0; i < n; i++) {
            if (subset & (1 << i)) {
                total_weight += weights[i];
                total_value += values[i];
            }
        }
        
        if (total_weight <= capacity && total_value > max_value) {
            max_value = total_value;
            selected_items = subset;
        }
    }

   
    printf("Max value: %d\n", max_value);

    printf("Selected items: ");
    for (int i = 0; i < n; i++) {
        if (selected_items & (1 << i)) {
            printf("Item %d (Weight: %d, Value: %d) ", i+1, weights[i], values[i]);
        }
    }
    printf("\n");
}

int main() {
    int n, capacity;
    printf("Enter number of items and knapsack capacity: ");
    scanf("%d %d", &n, &capacity);

    int weights[n], values[n];
    printf("Enter weights: ");
    for (int i = 0; i < n; i++) scanf("%d", &weights[i]);
    
    printf("Enter values: ");
    for (int i = 0; i < n; i++) scanf("%d", &values[i]);

    knapsack(weights, values, n, capacity);
    return 0;
}

