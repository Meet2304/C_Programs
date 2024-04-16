#include <stdio.h>
#include <stdlib.h>

// Structure to store license information
// Typedef is used to create an alias for the structure named Lisence
typedef struct {
    int index;
    double growth_rate;
} License;

// Function to swap two licenses
void swap(License *a, License *b) {
    License temp = *a;
    *a = *b;
    *b = temp;
}

// Function to compute the order of buying licenses
void buyLicenses(int n, double growth_rates[]) {
    License licenses[n];
    
    // Populate the license array with growth rates and indices
    for (int i = 0; i < n; i++) {
        licenses[i].index = i + 1; // Indexing starts from 1
        licenses[i].growth_rate = growth_rates[i];
    }

    // Bubble sort to sort the licenses based on growth rates
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (licenses[j].growth_rate < licenses[j + 1].growth_rate) {
                swap(&licenses[j], &licenses[j + 1]);
            }
        }
    }

    // Print the order of buying licenses
    printf("Order of buying licenses to minimize spending:\n");
    for (int i = 0; i < n; i++) {
        printf("Buy license %d\n", licenses[i].index);
    }
}

int main() {
    int n;
    printf("Enter the number of licenses: ");
    scanf("%d", &n);

    double growth_rates[n];
    printf("Enter the growth rates of licenses:\n");
    for (int i = 0; i < n; i++) {
        printf("Growth rate for license %d: ", i + 1);
        scanf("%lf", &growth_rates[i]);
    }

    buyLicenses(n, growth_rates);

    return 0;
}
