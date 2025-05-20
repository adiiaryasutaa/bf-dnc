#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <iomanip>

/**
 * Optimized Brute Force Matrix Multiplication
 * Time Complexity: O(n³)
 * Space Complexity: O(n²)
 * 
 * Algorithm Steps:
 * 1. Initialize result matrix C with zeros
 * 2. For each element in C:
 *    a. Calculate dot product of row i from A and column j from B
 *    b. Store result in C[i][j]
 * 3. Use early termination for zero elements
 * 
 * Memory Optimization:
 * - In-place matrix multiplication
 * - No temporary arrays
 * - Efficient memory access patterns
 * - Direct array indexing
 */
void matrixMultiplyBruteForce(long long** A, long long** B, long long** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                if (A[i][k] != 0 && B[k][j] != 0) {  // Skip multiplication if either element is 0
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
}

/**
 * Optimized Matrix Addition
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * 
 * Algorithm Steps:
 * 1. For each element in matrices:
 *    a. Add corresponding elements from A and B
 *    b. Store result in C
 * 
 * Memory Optimization:
 * - In-place addition
 * - No temporary arrays
 * - Efficient memory access patterns
 */
void addMatrix(long long** A, long long** B, long long** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

/**
 * Optimized Matrix Subtraction
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * 
 * Algorithm Steps:
 * 1. For each element in matrices:
 *    a. Subtract corresponding elements (A - B)
 *    b. Store result in C
 * 
 * Memory Optimization:
 * - In-place subtraction
 * - No temporary arrays
 * - Efficient memory access patterns
 */
void subtractMatrix(long long** A, long long** B, long long** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

/**
 * Initialize matrix with random values
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * 
 * Algorithm Steps:
 * 1. Create random number generator with seed
 * 2. Create uniform distribution for random numbers
 * 3. Fill matrix with random values in range [1, 10] to prevent overflow
 * 
 * Memory Optimization:
 * - In-place initialization
 * - No temporary arrays
 * - Efficient random number generation
 */
void initializeRandomMatrix(long long** matrix, int n) {
    // Create random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);  // Reduced range to prevent overflow
    
    // Fill matrix with random values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = dis(gen);
        }
    }
}

/**
 * Optimized Divide and Conquer Matrix Multiplication (Strassen's Algorithm)
 * Time Complexity: O(n^log₂7) ≈ O(n^2.807)
 * Space Complexity: O(n²)
 * 
 * Algorithm Steps:
 * 1. Base case: Use brute force for small matrices (n ≤ 2)
 * 2. Divide matrices into quarters
 * 3. Calculate seven products using Strassen's formulas
 * 4. Combine results to form final matrix
 * 
 * Memory Optimization:
 * - Efficient memory allocation for submatrices
 * - Reuse of temporary matrices
 * - Proper cleanup of allocated memory
 * - Static allocation for small matrices
 */
void matrixMultiplyDivideConquer(long long** A, long long** B, long long** C, int n) {
    if (n <= 2) {
        matrixMultiplyBruteForce(A, B, C, n);
        return;
    }
    
    int half = n / 2;
    
    // Allocate submatrices
    long long** A11 = new long long*[half];
    long long** A12 = new long long*[half];
    long long** A21 = new long long*[half];
    long long** A22 = new long long*[half];
    long long** B11 = new long long*[half];
    long long** B12 = new long long*[half];
    long long** B21 = new long long*[half];
    long long** B22 = new long long*[half];
    
    for (int i = 0; i < half; i++) {
        A11[i] = new long long[half];
        A12[i] = new long long[half];
        A21[i] = new long long[half];
        A22[i] = new long long[half];
        B11[i] = new long long[half];
        B12[i] = new long long[half];
        B21[i] = new long long[half];
        B22[i] = new long long[half];
    }
    
    // Split matrices
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }
    
    // Allocate temporary matrices for Strassen's formulas
    long long** temp1 = new long long*[half];
    long long** temp2 = new long long*[half];
    long long** P1 = new long long*[half];
    long long** P2 = new long long*[half];
    long long** P3 = new long long*[half];
    long long** P4 = new long long*[half];
    long long** P5 = new long long*[half];
    long long** P6 = new long long*[half];
    long long** P7 = new long long*[half];
    
    for (int i = 0; i < half; i++) {
        temp1[i] = new long long[half];
        temp2[i] = new long long[half];
        P1[i] = new long long[half];
        P2[i] = new long long[half];
        P3[i] = new long long[half];
        P4[i] = new long long[half];
        P5[i] = new long long[half];
        P6[i] = new long long[half];
        P7[i] = new long long[half];
    }
    
    // Calculate P1 to P7 using Strassen's formulas
    subtractMatrix(B12, B22, temp1, half);
    matrixMultiplyDivideConquer(A11, temp1, P1, half);
    
    addMatrix(A11, A12, temp1, half);
    matrixMultiplyDivideConquer(temp1, B22, P2, half);
    
    addMatrix(A21, A22, temp1, half);
    matrixMultiplyDivideConquer(temp1, B11, P3, half);
    
    subtractMatrix(B21, B11, temp1, half);
    matrixMultiplyDivideConquer(A22, temp1, P4, half);
    
    addMatrix(A11, A22, temp1, half);
    addMatrix(B11, B22, temp2, half);
    matrixMultiplyDivideConquer(temp1, temp2, P5, half);
    
    subtractMatrix(A12, A22, temp1, half);
    addMatrix(B21, B22, temp2, half);
    matrixMultiplyDivideConquer(temp1, temp2, P6, half);
    
    subtractMatrix(A11, A21, temp1, half);
    addMatrix(B11, B12, temp2, half);
    matrixMultiplyDivideConquer(temp1, temp2, P7, half);
    
    // Combine results
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            C[i][j + half] = P1[i][j] + P2[i][j];
            C[i + half][j] = P3[i][j] + P4[i][j];
            C[i + half][j + half] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
        }
    }
    
    // Clean up allocated memory
    for (int i = 0; i < half; i++) {
        delete[] A11[i]; delete[] A12[i]; delete[] A21[i]; delete[] A22[i];
        delete[] B11[i]; delete[] B12[i]; delete[] B21[i]; delete[] B22[i];
        delete[] temp1[i]; delete[] temp2[i];
        delete[] P1[i]; delete[] P2[i]; delete[] P3[i]; delete[] P4[i];
        delete[] P5[i]; delete[] P6[i]; delete[] P7[i];
    }
    delete[] A11; delete[] A12; delete[] A21; delete[] A22;
    delete[] B11; delete[] B12; delete[] B21; delete[] B22;
    delete[] temp1; delete[] temp2;
    delete[] P1; delete[] P2; delete[] P3; delete[] P4;
    delete[] P5; delete[] P6; delete[] P7;
}

/**
 * Optimized Matrix Equality Check
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * 
 * Algorithm Steps:
 * 1. Compare each element of matrices A and B
 * 2. Return false on first mismatch
 * 3. Return true if all elements match
 * 
 * Memory Optimization:
 * - In-place comparison
 * - No temporary arrays
 * - Early termination on mismatch
 */
bool verifyMatrices(long long** A, long long** B, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Testing Matrix Multiplication Algorithms" << std::endl << std::endl;
    
    // Test with different matrix sizes
    const int testSizes[] = {2, 4, 8, 128};
    const int numTests = sizeof(testSizes) / sizeof(testSizes[0]);
    const int NUM_ITERATIONS = 10; // Run each test multiple times
    
    for (int i = 0; i < numTests; i++) {
        const int n = testSizes[i];
        std::cout << std::endl << "Test Case " << (i + 1) << ": " << n << "x" << n << " matrices" << std::endl;
        
        // Allocate matrices
        long long** A = new long long*[n];
        long long** B = new long long*[n];
        long long** C1 = new long long*[n];
        long long** C2 = new long long*[n];
        
        for (int j = 0; j < n; j++) {
            A[j] = new long long[n];
            B[j] = new long long[n];
            C1[j] = new long long[n];
            C2[j] = new long long[n];
        }
        
        // Initialize test matrices with random values
        initializeRandomMatrix(A, n);
        initializeRandomMatrix(B, n);
        
        // Measure brute force
        auto start = std::chrono::high_resolution_clock::now();
        for (int iter = 0; iter < NUM_ITERATIONS; iter++) {
            matrixMultiplyBruteForce(A, B, C1, n);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto durationBF = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        double avgTimeBF = static_cast<double>(durationBF.count()) / NUM_ITERATIONS;
        
        // Measure divide and conquer
        start = std::chrono::high_resolution_clock::now();
        for (int iter = 0; iter < NUM_ITERATIONS; iter++) {
            matrixMultiplyDivideConquer(A, B, C2, n);
        }
        end = std::chrono::high_resolution_clock::now();
        auto durationDC = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        double avgTimeDC = static_cast<double>(durationDC.count()) / NUM_ITERATIONS;
        
        // Verify results
        bool resultsMatch = verifyMatrices(C1, C2, n);
        
        // Print results
        std::cout << "Brute Force:" << std::endl;
        std::cout << "Average Time: " << avgTimeBF << " nanoseconds" << std::endl;
        
        std::cout << std::endl;

        std::cout << "Divide & Conquer:" << std::endl;
        std::cout << "Average Time: " << avgTimeDC << " nanoseconds" << std::endl;

        std::cout << std::endl;

        std::cout << "Results Match: " << (resultsMatch ? "Yes" : "No") << std::endl;
        std::cout << "------------------------" << std::endl;
        
        // Clean up
        for (int j = 0; j < n; j++) {
            delete[] A[j];
            delete[] B[j];
            delete[] C1[j];
            delete[] C2[j];
        }
        delete[] A;
        delete[] B;
        delete[] C1;
        delete[] C2;
    }
    
    return 0;
}