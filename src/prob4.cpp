// // Project Euler    #4
// A palindromic number reads the same both ways.
// The largest palindrome made from the product of two 2-digit
// numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two
// 3-digit numbers.

#include<iostream>

bool isPalindrome(int num) {
    int buff = num, rev = 0;
    while(buff > 0) {
        int d = buff % 10;
        rev = rev * 10 + d;
        buff = buff / 10;
    }

    //std::cout << rev << " and " << num << std::endl;
    return rev == num;
}

int main(int argc, char **argv) {

    // One could transform into a string and check. Smarter way:
    // This palindrome can be written like
    // XYZZYX = X*10^5 + Y*10^4 + Z*10^3 + Z*10^2 + Y*10 + X
    //        = 100001*X + 10010*Y + 1001*Z = 11(991*X + 910*Y + 100*Z)
    // now we can reduce the searching time
    unsigned int greatest = 0;
    for(int i = 999; i > 100; i--)
        for(int j = 990; j > 100; j -= 11) {
            unsigned int prod = j * i;
            if(isPalindrome(prod) && prod > greatest)
                greatest = prod;
        }
    
    std::cout << "Greatest palindrome: " << greatest << std::endl;

    return 0;
}