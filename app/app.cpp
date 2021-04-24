#include <lib.h>

#include <cassert>

using namespace std;

double
sum(double x, double y) {
    return x + y;
}

double
multiply(double x, double y) {
    return x * y;
}

int
main(int argc, char* argv[]) {
    Matrix m;
    assert(matrix_create(&m, 3, 4) == 0);
    
    matrix_set(&m, 1, 2, 3);
    matrix_set(&m, 2, 1, 4);
    assert(matrix_get(&m, 1, 2) == 3);
    assert(matrix_get(&m, 2, 1) == 4);

    assert(matrix_op(&m, sum, 0) == 7);
    assert(matrix_op(&m, multiply, 0) == 12);

    matrix_free(&m);
}
