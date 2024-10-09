// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/roman-to-integer/

    Given a roman numeral, convert it to an integer.
*/

#include <stdio.h>
#include <string.h>

int romanToInt(char* s) {
    // Map of Roman numeral values
    int romanValue[256] = {0}; // Array to hold values, using ASCII values as indices
    romanValue['I'] = 1;
    romanValue['V'] = 5;
    romanValue['X'] = 10;
    romanValue['L'] = 50;
    romanValue['C'] = 100;
    romanValue['D'] = 500;
    romanValue['M'] = 1000;

    int total = 0;
    int prevValue = 0; // To hold the value of the previous numeral

    // Iterate through each character in the Roman numeral string
    for (int i = 0; i < strlen(s); i++) {
        int currentValue = romanValue[s[i]]; // Get the value of the current numeral

        // If the current value is greater than the previous one, we need to subtract twice the previous
        if (currentValue > prevValue) {
            total += currentValue - 2 * prevValue; // Adjust the total by subtracting the previous value
        } else {
            total += currentValue; // Otherwise, just add the current value
        }

        prevValue = currentValue; // Update the previous value
    }

    return total; // Return the total integer value
}