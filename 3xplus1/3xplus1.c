#include <limits.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "intal.h"

/*
 * Function:  main
 * --------------------
 * Computes Collatz conjecture (3x + 1) for specified range of numbers
 *
 * Prints each time a new max is found
 *
 */
int main()
{

    //unsigned long long num;
    unsigned long long start = 1;
    unsigned long long end = ULLONG_MAX;
    //unsigned long long max_height = 0;
    // char *max_height ="0";
    void *num;
    void *max_height;

    num = intal_create("0");
    max_height = intal_create("0");

    printf("max_height: %s\n", intal2str(max_height));

    //unsigned __int128 max_height = 0;

    clock_t t = clock(); // CPU time
    struct timespec t_start, t_now;
    clock_gettime(CLOCK_MONOTONIC, &t_start);

    printf("\nnumber height steps cpu_time wall_time\n");


    void *num_a;
    void *num_b;
    num_a = intal_create("5");
    num_b = intal_create("1000");

    void *div;
    div = intal_divide(num_b, num_a);
    printf("num_b/num_a: %s\n", intal2str(div));

    printf("num_a: %s\n", intal2str(num_a));
    printf("num_b: %s\n", intal2str(num_b));

    printf("num_b/num_a: %s\n", intal2str(intal_divide(num_b, num_a)));
    printf("(num_b/num_a) * num_a: %s\n", intal2str(intal_multiply(intal_divide(num_b, num_a), num_a)));
    printf("compare: %2d\n", intal_compare(intal_multiply(intal_divide(num_b, num_a), num_a), num_b));
    printf("mod: %s\n", (intal_compare(intal_multiply(intal_divide(num_b, num_a), num_a), num_b) == 0 ? "true" : "false"));

/*
    while (1)
    {
        //for( num = start; num <= end; num = num + 1 ) {
        //unsigned long long steps=0;
        //unsigned long long height=0;
        //unsigned __int128 height=0;
        //unsigned long long next_num=0;
        //unsigned long long curr_num = num;

        void *steps;
        void *height;
        void *next_num;
        void *curr_num;

        steps = intal_create("0");
        height = intal_create("0");
        next_num = intal_create("0");
        curr_num = intal_create(intal2str(num));

        printf("\r%s", intal2str(num));
        fflush(stdout);

        // iterate until we get back to 1
        /*
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
        if(height > max_height) {
            max_height = height;
            clock_t t2 = clock();
            clock_gettime(CLOCK_MONOTONIC, &t_now);
            printf("\r%llu %llu %llu %.1f %.f\n", num, height, steps, (double)(t2 - t)/CLOCKS_PER_SEC, (t_now.tv_sec - t_start.tv_sec) + 1e-9 * (t_now.tv_nsec - t_start.tv_nsec));
            fflush(stdout);
        }

    }

    return 0;

*/
}
