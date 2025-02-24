#include <stdio.h>

typedef long long (*long_func_ptr)(int param);

// Provider
long_func_ptr fibonacci_provider;

// Recursive function to calculate fibonacci sequence
// Input-   int num: number to find the fibonacci sequence for
// Output-  long long representing the "num" element of the fibonacci sequence
long long fibonacci(int num) {
    if (num == 0) 
        return 0;

    if (num == 1) 
        return 1;

    return (*fibonacci_provider)(num - 1) + (*fibonacci_provider)(num - 2);
}

// Cache
#define MAX_MEMOIZED 92
#define ARRAY_SIZE (MAX_MEMOIZED + 1)
#define NO_VALUE -1
long_func_ptr original_provider;
long long memoized[ARRAY_SIZE];

// Cache function that checks if the result of fibonacci() has already been
// calculated and memoized. If yes, the result is returned from the memoized
// array. If no, the function is called and the result is memoized for future
// use.
// Input-   int num: number to find the fibonacci sequence for
// Output-  long long representing the "num" element of the fibonacci sequence
long long memoized_fibonacci(int num) {

    if (num > MAX_MEMOIZED) {
        return (*original_provider)(num);
    }

    if (memoized[num] == NO_VALUE) {
        memoized[num] = (*original_provider)(num);
    }
    return memoized[num];
}

// Initializes the cache, and assigns the provider function to the original
// provider pointer
// Input-   long_func_ptr provider: Function pointer to the provider of the
//                                  fibonacci calculations
// Output-  long_func_ptr to the memoized_fibonacci function
long_func_ptr init_cache(long_func_ptr provider) {
    for (int ix = 0; ix < ARRAY_SIZE; ix++) {
        memoized[ix] = NO_VALUE;
    }

    original_provider = provider;

    return memoized_fibonacci;
}

int main(int argc, char *argv[]) {

    int num = 0;

    // Checks if no arguments were passed
    if (argc < 2 || 1 != sscanf_s(argv[1], "%d", &num)) {
        printf("Please enter an input\n");
        return 1;
    }
    else if (argc > 2) {    // Checks if more than one argument was passed
        printf("Too many inputs. Please enter ONE input");
        return 1;
    }

    // Checks if num is in the acceptable range of inputs
    if (num < 0 || num > MAX_MEMOIZED) {
        printf("Please enter a number between 0 and 92\n");
        return 1;
    }

    fibonacci_provider = init_cache(fibonacci);

    //for (int ix = num; ix >= 0; ix--)
    printf("Fibonacci(%d) = %lld\n", num, (*fibonacci_provider)(num));

    printf("\nReplaying the same Fibonacci sequence to test memoization\n");
    printf("Press enter to continue\n");
    getchar();

    //for (int ix = 0; ix <= num; ix++)
    printf("Fibonacci(%d) = %lld\n", num, (*fibonacci_provider)(num));

    return 0;
}