#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

/**
 * Optimized Brute Force Prime Number Check
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * Algorithm Steps:
 * 1. Early return for numbers ≤ 1 (not prime)
 * 2. Early return for 2 and 3 (prime)
 * 3. Check divisibility by 2 and 3 first
 * 4. Only check odd numbers from 5 onwards
 * 5. Use early termination when a divisor is found
 * 
 * Memory Optimization:
 * - Uses constant space O(1)
 * - No additional data structures
 * - In-place calculations
 */
bool isPrimeBruteForce(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i < n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

/**
 * Optimized Divide and Conquer Prime Number Check
 * Time Complexity: O(√n)
 * Space Complexity: O(1)
 * 
 * Algorithm Steps:
 * 1. Early return for numbers ≤ 1 (not prime)
 * 2. Early return for 2 and 3 (prime)
 * 3. Check divisibility by 2 and 3 first
 * 4. Use mathematical optimization to check only up to √n
 * 5. Use 6k ± 1 optimization (all primes > 3 are of form 6k ± 1)
 * 6. Early termination when a divisor is found
 * 
 * Memory Optimization:
 * - Uses constant space O(1)
 * - No additional data structures
 * - In-place calculations
 * - Uses static_cast for efficient type conversion
 */
bool isPrimeDivideConquer(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    int sqrtN = static_cast<int>(std::sqrt(n));
    for (int i = 5; i <= sqrtN; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

/**
 * Optimized Prime Counting using Brute Force
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * 
 * Algorithm Steps:
 * 1. Initialize counter to 0
 * 2. Iterate through numbers from 2 to n
 * 3. For each number, check if it's prime using brute force
 * 4. Increment counter for each prime found
 * 
 * Memory Optimization:
 * - Uses constant space O(1)
 * - No additional data structures
 * - In-place counting
 */
int countPrimesBruteForce(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrimeBruteForce(i)) {
            count++;
        }
    }
    return count;
}

/**
 * Optimized Prime Counting using Divide and Conquer
 * Time Complexity: O(n√n)
 * Space Complexity: O(1)
 * 
 * Algorithm Steps:
 * 1. Initialize counter to 0
 * 2. Iterate through numbers from 2 to n
 * 3. For each number, check if it's prime using optimized divide and conquer
 * 4. Increment counter for each prime found
 * 
 * Memory Optimization:
 * - Uses constant space O(1)
 * - No additional data structures
 * - In-place counting
 */
int countPrimesDivideConquer(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrimeDivideConquer(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    std::cout << "Testing Prime Number Algorithms\n" << std::endl;
    
    // Test with different ranges
    const int testRanges[] = {1000, 5000, 10000};
    const int numTests = sizeof(testRanges) / sizeof(testRanges[0]);
    const int NUM_ITERATIONS = 10; // Run each test multiple times
    
    for (int i = 0; i < numTests; i++) {
        const int range = testRanges[i];
        std::cout << "\nTest Case " << (i + 1) << ": Range = 1 to " << range << std::endl;
        
        // Measure Brute Force
        auto start = std::chrono::high_resolution_clock::now();
        int countBF = 0;
        for (int iter = 0; iter < NUM_ITERATIONS; iter++) {
            countBF = countPrimesBruteForce(range);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto durationBF = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        double avgTimeBF = static_cast<double>(durationBF.count()) / NUM_ITERATIONS;
        
        // Measure Divide and Conquer
        start = std::chrono::high_resolution_clock::now();
        int countDC = 0;
        for (int iter = 0; iter < NUM_ITERATIONS; iter++) {
            countDC = countPrimesDivideConquer(range);
        }
        end = std::chrono::high_resolution_clock::now();
        auto durationDC = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        double avgTimeDC = static_cast<double>(durationDC.count()) / NUM_ITERATIONS;
        
        // Print results
        std::cout << "Brute Force:" << std::endl;
        std::cout << "Number of Primes: " << countBF << std::endl;
        std::cout << "Average Time: " << avgTimeBF << " nanoseconds" << std::endl;
        
        std::cout << "\nDivide and Conquer:" << std::endl;
        std::cout << "Number of Primes: " << countDC << std::endl;
        std::cout << "Average Time: " << avgTimeDC << " nanoseconds" << std::endl;
        std::cout << "------------------------" << std::endl;
    }
    
    return 0;
} 