#include "lib.h"

#include <cstdlib>

int
matrix_create(Matrix* m, uint32_t rows, uint32_t cols) {
    auto items = (double*)calloc(rows * cols, sizeof(double));
    if (items == nullptr) {
        return -1;
    }
    m->rows = rows;
    m->cols = cols;
    m->items = new double[rows * cols];
    return 0;
}

void
matrix_free(Matrix* m) {
    free(m->items);
}

double
matrix_get(const Matrix* m, uint32_t row, uint32_t col) {
    return m->items[row * m->cols + col];
}

void
matrix_set(Matrix* m, uint32_t row, uint32_t col, double value) {
    m->items[row * m->cols + col] = value;
}

double
matrix_op(Matrix* m, Op op, double init) {
    double result = init;
    for (uint32_t i = 0; i < m->rows; i++) {
        for (uint32_t j = 0; j < m->cols; j++) {
            double value = m->items[i * m->cols + j];
            result = op(result, value);
        }
    }
    return result;
}
