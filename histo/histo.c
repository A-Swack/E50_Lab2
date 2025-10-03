#include <stdio.h>
#include <stdlib.h>

#define NBINS 16

int main(void) {
    int bins[NBINS] = {0};
    int bin_size = 1;
    int max_value = NBINS * bin_size;

    int value;
    while (scanf("%d", &value) == 1) {
        if (value < 0) continue; // ignore negatives as said in instructions

        // Expand range until val fits
        while (value >= max_value) {
            bin_size *= 2;
            max_value = NBINS * bin_size;

            // compress bins
            for (int i = 0; i < NBINS / 2; i++) {
                bins[i] = bins[2*i] + bins[2*i + 1];
            }
            for (int i = NBINS / 2; i < NBINS; i++) {
                bins[i] = 0;
            }
            printf("%d bins of size %d for range [0,%d)\n", NBINS, bin_size, max_value);
        }

        int bin_index = value / bin_size;
        if (bin_index >= NBINS) bin_index = NBINS - 1; // safety
        bins[bin_index]++;
    }

    //print histogram
    for (int i = 0; i < NBINS; i++) {
        int low = i * bin_size;
        int high = (i+1) * bin_size - 1;
        printf("[%3d:%3d] ", low, high);
        for (int j = 0; j < bins[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}

