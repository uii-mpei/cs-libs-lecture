#pragma once

#include <cstdint>

struct Matrix {
    uint32_t rows;
    uint32_t cols;
    double* items;
};

// typedef void (*Op)(double acc, double value);
using Op = double(double acc, double x);

int matrix_create(Matrix* m, uint32_t rows, uint32_t cols);
void matrix_free(Matrix* m);

double matrix_op(Matrix* m, Op op, double init);

double matrix_get(const Matrix* m, uint32_t row, uint32_t col);
void matrix_set(Matrix* m, uint32_t row, uint32_t col, double value);
