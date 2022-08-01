// Project Euler    #1
// If we list all the natural numbers below 10
// that are multiples of 3 or 5, we get 3, 5, 6 and 9.
// The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>
#include <chrono>

int main(int argc, char **argv) {
    unsigned int sum1 = 0, sum2 = 0;
    int threshold = 100;

    auto start = std::chrono::high_resolution_clock::now();
    // version 1 - standard
    for(int i = 0; i < threshold; i++)
        if(i % 3 == 0 || i % 5 == 0)
            sum1 += i;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time for first method: " << duration.count() << " nanoseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    // version 2 - faster
    for(int i = 0; i < threshold; i += 3)
        sum2 += i;
    for(int i = 0; i < threshold; i += 5)
        if(i % 3 != 0)
            sum2 += i;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time for second method: " << duration.count() << " nanoseconds" << std::endl;

    std::cout << sum2 << std::endl;
    return 0;
}