#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "sorting.h"

#define ARRAY_SIZE 10

// Тест для FillInc
static void test_FillInc(void **state) {
    int A[ARRAY_SIZE];
    FillInc(ARRAY_SIZE, A);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        assert_int_equal(A[i], i);
    }
}

// Тест для FillDec
static void test_FillDec(void **state) {
    int A[ARRAY_SIZE];
    FillDec(ARRAY_SIZE, A);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        assert_int_equal(A[i], ARRAY_SIZE - i - 1);
    }
}

// Тест для CheckSum
static void test_CheckSum(void **state) {
    int A[] = {1, 2, 3, 4, 5};
    assert_int_equal(CheckSum(5, A), 15);
}

// Тест для RunNumber
static void test_RunNumber(void **state) {
    int A[] = {1, 2, 3, 2, 1};
    assert_int_equal(RunNumber(5, A), 3);
}

// Тест для insertSort
static void test_insertSort(void **state) {
    int A[] = {5, 3, 1, 2, 4};
    int expected[] = {1, 2, 3, 4, 5};
    insertSort(5, A, 0);
    for (int i = 0; i < 5; i++) {
        assert_int_equal(A[i], expected[i]);
    }
}

// Тест для shellSort
static void test_shellSort(void **state) {
    int A[] = {5, 3, 1, 2, 4};
    int expected[] = {1, 2, 3, 4, 5};
    shellSort(5, A, 0);
    for (int i = 0; i < 5; i++) {
        assert_int_equal(A[i], expected[i]);
    }
}

// Тест для shellSortBetter
static void test_shellSortBetter(void **state) {
    int A[] = {5, 3, 1, 2, 4};
    int expected[] = {1, 2, 3, 4, 5};
    shellSortBetter(5, A, 0);
    for (int i = 0; i < 5; i++) {
        assert_int_equal(A[i], expected[i]);
    }
}

// Тест для generateShellSequenceAsString
static void test_generateShellSequenceAsString(void **state) {
    char buffer[100];
    generateShellSequenceAsString(10, buffer);
    assert_string_equal(buffer, "7 3 1 ");
}

// Тест для generateCiuraSequenceAsString
static void test_generateCiuraSequenceAsString(void **state) {
    char buffer[100];
    generateCiuraSequenceAsString(10, buffer);
    assert_string_equal(buffer, "10 4 1");
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_FillInc),
        cmocka_unit_test(test_FillDec),
        cmocka_unit_test(test_CheckSum),
        cmocka_unit_test(test_RunNumber),
        cmocka_unit_test(test_insertSort),
        cmocka_unit_test(test_shellSort),
        cmocka_unit_test(test_shellSortBetter),
        cmocka_unit_test(test_generateShellSequenceAsString),
        cmocka_unit_test(test_generateCiuraSequenceAsString),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
