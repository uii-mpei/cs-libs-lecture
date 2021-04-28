#pragma once

#include <cstdint>

struct Matrix {
    uint32_t rows;
    uint32_t cols;
    double* items;
};

// typedef void (*Op)(uint32_t i, uint32_t j);
using Op = void(Matrix* m, uint32_t i, uint32_t j);

int matrix_create(Matrix* m, uint32_t rows, uint32_t cols);
void matrix_free(Matrix* m);

void matrix_op(Matrix* m, Op op);

double matrix_get(const Matrix* m, uint32_t row, uint32_t col);
void matrix_set(Matrix* m, uint32_t row, uint32_t col, double value);
