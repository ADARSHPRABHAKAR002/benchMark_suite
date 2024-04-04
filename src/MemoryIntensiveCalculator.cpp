#include "MemoryIntensiveCalculator.h"

std::vector<std::vector<int>> MemoryIntensiveCalculator::generateLargeMatrix(int rows, int cols) {
    // Create a 2D vector to represent the matrix
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    // Fill the matrix with some data (for demonstration purpose)
    int value = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = value++;
        }
    }

    return matrix;
}