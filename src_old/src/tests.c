#include <check.h>

#include "parser.h"

START_TEST(Test1) {
    Model *A = getModel("test.obj");

    ck_assert_int_eq(A->vertex_count, 4);
    ck_assert_int_eq(A->face_count, 2 * 3);
    ck_assert_double_eq(A->vertexes[0], -0.1);
    ck_assert_double_eq(A->vertexes[1], -0.5);
    ck_assert_double_eq(A->vertexes[2], 0.5);

    ck_assert_int_eq(A->faces[0], 0);
    ck_assert_int_eq(A->faces[1], 1);
    ck_assert_int_eq(A->faces[2], 2);

    clearModel(A);
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, Test1);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
