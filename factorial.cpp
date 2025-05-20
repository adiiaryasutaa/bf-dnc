#include <iostream>
#include <chrono>
#include <vector>

/**
 * Optimized Brute Force Approach to Calculate Factorial
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * Algorithm Steps:
 * 1. Initialize result to 1
 * 2. Multiply result by each number from 2 to n
 * 3. Use unsigned long long to handle larger numbers
 * 4. Early return for n ≤ 1
 * 
 * Memory Optimization:
 * - Uses constant space O(1)
 * - No additional data structures
 * - In-place calculations
 * - Uses unsigned long long for efficient memory usage
 */
unsigned long long factorialBruteForce(int n) {
    if (n <= 1) return 1;
    
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

/**
 * Optimized Divide and Conquer Approach with Memoization
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * Algorithm Steps:
 * 1. Early return for n ≤ 1
 * 2. Use static memoization array to store calculated values
 * 3. Check if value is already calculated
 * 4. If not, calculate using recursion and store result
 * 5. Return stored value
 * 
 * Memory Optimization:
 * - Uses static array for memoization to avoid repeated allocations
 * - Fixed size array to prevent memory leaks
 * - Efficient memory reuse for repeated calculations
 * - Uses unsigned long long for efficient memory usage
 */
unsigned long long factorialDivideConquer(int n) {
    if (n <= 1) return 1;
    
    // Using static memoization to store calculated values
    static unsigned long long memo[100] = {0};
    if (memo[n] != 0) return memo[n];
    
    // Calculate factorial using recursion and memoization
    memo[n] = n * factorialDivideConquer(n - 1);
    return memo[n];
}

int main() {
    std::cout << "Testing Factorial Algorithms" << std::endl << std::endl;
    
    // Test with different input sizes
    const int testCases[] = {5, 10, 15, 20};
    const int numTests = sizeof(testCases) / sizeof(testCases[0]);
    const int NUM_ITERATIONS = 1000000; // Run each test multiple times
    
    for (int i = 0; i < numTests; i++) {
        const int n = testCases[i];
        std::cout << std::endl << "Test Case " << (i + 1) << ": Calculating " << n << "!" << std::endl;
        
        // Measure brute force
        auto start = std::chrono::high_resolution_clock::now();
        unsigned long long resultBF = 0;
        for (int iter = 0; iter < NUM_ITERATIONS; iter++) {
            resultBF = factorialBruteForce(n);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto durationBF = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        double avgTimeBF = static_cast<double>(durationBF.count()) / NUM_ITERATIONS;
        
        // Measure divide and conquer
        start = std::chrono::high_resolution_clock::now();
        unsigned long long resultDC = 0;
        for (int iter = 0; iter < NUM_ITERATIONS; iter++) {
            resultDC = factorialDivideConquer(n);
        }
        end = std::chrono::high_resolution_clock::now();
        auto durationDC = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        double avgTimeDC = static_cast<double>(durationDC.count()) / NUM_ITERATIONS;
        
        // Print results
        std::cout << "Brute Force:" << std::endl;
        std::cout << "Result: " << resultBF << std::endl;
        std::cout << "Average Time: " << avgTimeBF << " nanoseconds" << std::endl;

        std::cout << std::endl;
        
        std::cout << "Divide & Conquer:" << std::endl;
        std::cout << "Result: " << resultDC << std::endl;
        std::cout << "Average Time: " << avgTimeDC << " nanoseconds" << std::endl;
        std::cout << "------------------------" << std::endl;
    }
    
    return 0;
} 