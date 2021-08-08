#include <stdio.h>
#include <time.h>

/*
 * Function:  main
 * --------------------
 * Computes Collatz conjecture (3x + 1) for specified range of numbers
 *
 * Prints each time a new max is found
 *
 */
int main() {

    unsigned long long num;
    unsigned long long start = 1;
    unsigned long long end = 2147483648;
    unsigned long long max_height = 0;

    clock_t t;
    t = clock();

    for( num = start; num <= end; num = num + 1 ) {
        unsigned long long steps=0;
        unsigned long long height=0;
        unsigned long long next_num=0;
        unsigned long long curr_num = num;

        printf("\r%llu", num);
        fflush(stdout);

        // iterate until we get back to 1
        do {

            if (curr_num > height)
                height = curr_num;

            if (curr_num % 2 == 0)
                curr_num = curr_num / 2;
            else
                curr_num= 3 * curr_num + 1;

            steps++;

        } while (curr_num > 1);

        // printf("%d %d %d\n", num, height, steps);

        if(height > max_height) {
            max_height = height;
            printf("\r%llu %llu %llu\n", num, height, steps);
            fflush(stdout);
        }

    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\n\nTook %fs second(s)\n\n", time_taken);

    return 0;

}