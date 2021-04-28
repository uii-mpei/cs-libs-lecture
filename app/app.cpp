#include <lib.h>

#include <cassert>
#include <iostream>

using namespace std;

void
print(Matrix* m, uint32_t i, uint32_t j) {
    cout << "m[" << i << ", " << j << "] = " << matrix_get(m, i, j) << "\n";
}

void
randomize(Matrix* m, uint32_t i, uint32_t j) {
    matrix_set(m, i, j, rand() % 10);
}

int
main(int argc, char* argv[]) {
    Matrix m;
    assert(matrix_create(&m, 3, 4) == 0);
    matrix_op(&m, randomize);
    matrix_op(&m, print);
    matrix_free(&m);
}
