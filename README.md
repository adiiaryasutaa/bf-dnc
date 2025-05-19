# Algorithm Performance Comparison

This project demonstrates and compares different algorithmic approaches (Brute Force vs Divide & Conquer) for various computational problems. Each algorithm is implemented in C++ with performance measurements and detailed comments.

## Algorithms Implemented

### 1. Factorial Calculation
- **Brute Force Approach**
  - Time Complexity: O(n)
  - Space Complexity: O(1)
  - Implementation: Simple iterative multiplication from 1 to n
  - Best for: Small numbers, simple implementation

- **Divide & Conquer with Memoization**
  - Time Complexity: O(n)
  - Space Complexity: O(n)
  - Implementation: Recursive approach with caching
  - Best for: Repeated calculations of the same values

### 2. Matrix Multiplication
- **Brute Force Approach**
  - Time Complexity: O(n³)
  - Space Complexity: O(n²)
  - Implementation: Standard matrix multiplication using three nested loops
  - Best for: Small matrices, simple implementation

- **Strassen's Algorithm (Divide & Conquer)**
  - Time Complexity: O(n^2.807)
  - Space Complexity: O(n²)
  - Implementation: Divides matrices into quarters and uses seven recursive multiplications
  - Best for: Large matrices, better asymptotic complexity

### 3. Prime Number Generation
- **Brute Force Approach**
  - Time Complexity: O(n²)
  - Space Complexity: O(1)
  - Implementation: Checks each number up to n for primality
  - Best for: Small ranges, simple implementation

- **Divide & Conquer Approach**
  - Time Complexity: O(n√n)
  - Space Complexity: O(1)
  - Implementation: Uses mathematical optimization to check only up to √n
  - Best for: Medium-sized ranges, better performance

## Project Structure
```
.
├── factorial.cpp
├── matrix_multiply.cpp
├── prime_numbers.cpp
├── bin/
└── README.md
```

## Compilation Instructions

### Windows (using g++)
```bash
# Create bin directory if it doesn't exist
mkdir bin

# Compile factorial program
g++ factorial.cpp -o bin/factorial.exe

# Compile matrix multiplication program
g++ matrix_multiply.cpp -o bin/matrix_multiply.exe

# Compile prime numbers program
g++ prime_numbers.cpp -o bin/prime_numbers.exe
```

### Linux/macOS (using g++)
```bash
# Create bin directory if it doesn't exist
mkdir -p bin

# Compile factorial program
g++ factorial.cpp -o bin/factorial

# Compile matrix multiplication program
g++ matrix_multiply.cpp -o bin/matrix_multiply

# Compile prime numbers program
g++ prime_numbers.cpp -o bin/prime_numbers
```

## Running the Programs

### Windows
```bash
# Run factorial program
.\bin\factorial.exe

# Run matrix multiplication program
.\bin\matrix_multiply.exe

# Run prime numbers program
.\bin\prime_numbers.exe
```

### Linux/macOS
```bash
# Run factorial program
./bin/factorial

# Run matrix multiplication program
./bin/matrix_multiply

# Run prime numbers program
./bin/prime_numbers
```

## Performance Measurement

Each program includes:
- Multiple test cases with different input sizes
- Time measurements in nanoseconds
- Multiple iterations for accurate timing
- Result verification between algorithms
- Detailed output showing:
  - Input size
  - Execution time
  - Result correctness
  - Performance comparison

## Notes
- All timing measurements are in nanoseconds for precision
- Each test is run multiple times to get average performance
- Memory management is handled properly in all implementations
- Results are verified to ensure algorithm correctness

## Requirements
- C++ compiler (g++ recommended)
- Make or similar build tool (optional)
- Sufficient memory for matrix operations 