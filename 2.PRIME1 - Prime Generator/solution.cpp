#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const int MAX_TESTCASE_NUMBER=10;
const int MIN_FLOOR_NUMBER=1;
const int MAX_CEILING_NUMBER=1000000000;
const int MAX_SUBTRACTION_NUMBER=100000;

/**
 * Print all prime numbers between some interval.
 */
void printPrimes(int min, int max) {
    bool isPrime;
    for (int prime=min; prime<=max; prime++) {
        if (prime == 1 || prime == 0) {
            continue; // lower bound for non natural primes
        }

        isPrime = true;
        // Look just on lesser half part of numbers
        for (int divider=2; divider <= prime/2; ++divider) {
            if (prime % divider == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << prime << endl;
        }
    }
}

/**
 * Validate all inputs defined on challenge.
 */
void validateInputs(int min, int max) {
    if (MIN_FLOOR_NUMBER > min || MIN_FLOOR_NUMBER > max ) {
        throw std::invalid_argument("Input lesser than minimun value.");
    }

    if (MAX_CEILING_NUMBER < min || MAX_CEILING_NUMBER < max ) {
        throw std::invalid_argument("Input greater than minimun value.");
    }

    if (min > max) {
        throw std::invalid_argument("Minimum value is greater than maximun value.");
    }

    if ( (max - min) > MAX_SUBTRACTION_NUMBER) {
        throw std::invalid_argument("n-m subtraction is greater that threshold.");
    }
}

/**
 * Find all prime numbers between some interval.
 */
int main() {
    int testcaseNumber, min, max;
    vector<pair<int, int>> testCases;
    string numbers;
    char * pch;

    cin >> testcaseNumber;
    if (testcaseNumber > MAX_TESTCASE_NUMBER) {
        throw std::invalid_argument("Received invalid testcase number.");
    }

    for (int i=0; i < testcaseNumber; i++) {
        cin >> min >> max;
        validateInputs(min, max);

        // Fill the test case list
        pair<int, int> testPair (min, max);
        testCases.push_back(testPair);
    }

    for (auto it : testCases) {
        printPrimes(it.first, it.second);
        cout << endl;
    }

    return 0;
}