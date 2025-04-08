#include <check.h>
#include <math.h>

#include "s21_math.h"
#include "s21_tests.h"

// Функция тестирования какой-либо задачи.
START_TEST(pow_test_0) {
  double x = 0.0 / 0.0;
  double exp = x;
  ck_assert_int_eq(isnan(s21_pow(x, exp)), isnan(pow(x, exp)));
}
END_TEST

START_TEST(pow_test_1) {
  double x = 1, exp = INFINITY;
  ck_assert_ldouble_eq_tol(s21_pow(x, exp), pow(x, exp), 0.000001);
}
END_TEST

START_TEST(pow_test_2) {
  double x = -1, exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(x, exp), pow(x, exp), 0.000001);
}
END_TEST

START_TEST(pow_test_3) {
  double x = 9999999999.999999, exp = 0.41424;
  ck_assert_int_eq(isinf(s21_pow(x, exp)), isinf(pow(x, exp)));
}
END_TEST

START_TEST(pow_test_4) {
  double x = 1150382508.34634, exp = -23.1241;
  ck_assert_int_eq(isinf(s21_pow(x, exp)), isinf(pow(x, exp)));
}
END_TEST

START_TEST(pow_test_5) {
  double x = 0.000001, exp = -0.3142;
  ck_assert_ldouble_eq_tol(s21_pow(x, exp), pow(x, exp), 0.000001);
}
END_TEST

START_TEST(pow_test_6) {
  double x = -12431410066457456767687680.5231, exp = 0.14313443;
  ck_assert_int_eq(s21_pow(x, exp), pow(x, exp));
}
END_TEST

START_TEST(pow_test_7) {
  double x = -INFINITY, exp = 0;
  ck_assert_int_eq(s21_pow(x, exp), pow(x, exp));
}
END_TEST

START_TEST(pow_test_8) {
  double x = INFINITY, exp = 0;
  ck_assert_int_eq(isinf(s21_pow(x, exp)), isinf(pow(x, exp)));
}
END_TEST

START_TEST(pow_test_9) {
  double x = -0.0, exp = INFINITY;
  ck_assert_ldouble_eq_tol(s21_pow(x, exp), pow(x, exp), 0.000001);
}
END_TEST

START_TEST(pow_test_10) {
  double x = +0.0, exp = 12312431;
  ck_assert_ldouble_eq_tol(s21_pow(x, exp), pow(x, exp), 0.000001);
}
END_TEST

START_TEST(pow_test_11) {
  double x = 1234567890123456, exp = -1;
  ck_assert_int_eq(isinf(s21_pow(x, exp)), isinf(pow(x, exp)));
}
END_TEST

START_TEST(pow_test_12) {
  double x = -INFINITY, exp = -3.5;
  ck_assert_int_eq(s21_pow(x, exp), pow(x, exp));
}
END_TEST

START_TEST(pow_test_13) {
  double x = -INFINITY, exp = -3;
  ck_assert_int_eq(s21_pow(x, exp), pow(x, exp));
}
END_TEST

START_TEST(pow_test_14) {
  double x = -INFINITY, exp = 2.5;
  ck_assert_int_eq(isinf(s21_pow(x, exp)), isinf(pow(x, exp)));
}
END_TEST

START_TEST(pow_test_15) {
  double x = -INFINITY, exp = 3.5;
  ck_assert_int_eq(isinf(s21_pow(x, exp)), isinf(pow(x, exp)));
}
END_TEST

START_TEST(pow_test_16) {
  double x = -INFINITY, exp = 3;
  ck_assert_int_eq(isinf(s21_pow(x, exp)), isinf(pow(x, exp)));
}
END_TEST

START_TEST(pow_test_17) {
  double x = INFINITY, exp = -3.5;
  ck_assert_int_eq(s21_pow(x, exp), pow(x, exp));
}
END_TEST

START_TEST(pow_test_18) {
  double x = INFINITY, exp = 3;
  ck_assert_int_eq(isinf(s21_pow(x, exp)), isinf(pow(x, exp)));
}
END_TEST

START_TEST(pow_test_19) {
  double x = -3.5, exp = INFINITY;
  ck_assert_int_eq(isinf(s21_pow(x, exp)), isinf(pow(x, exp)));
}
END_TEST

START_TEST(pow_test_20) {
  double x = -1, exp = INFINITY;
  ck_assert_int_eq(s21_pow(x, exp), pow(x, exp));
}
END_TEST

START_TEST(pow_test_21) {
  double x = -3.5, exp = -INFINITY;
  ck_assert_int_eq(s21_pow(x, exp), pow(x, exp));
}
END_TEST

START_TEST(pow_test_22) {
  double x = -1, exp = -INFINITY;
  ck_assert_int_eq(s21_pow(x, exp), pow(x, exp));
}
END_TEST

START_TEST(pow_test_23) {
  double x = 1, exp = -INFINITY;
  ck_assert_int_eq(s21_pow(x, exp), pow(x, exp));
}
END_TEST

START_TEST(pow_test_24) {
  double x = 3.5, exp = -INFINITY;
  ck_assert_int_eq(s21_pow(x, exp), pow(x, exp));
}
END_TEST

START_TEST(pow_test_25) {
  double x = -0.5, exp = -INFINITY;
  ck_assert_int_eq(isinf(s21_pow(x, exp)), isinf(pow(x, exp)));
}
END_TEST

START_TEST(pow_test_26) {
  double x = 0.5, exp = -INFINITY;
  ck_assert_int_eq(isinf(s21_pow(x, exp)), isinf(pow(x, exp)));
}
END_TEST

START_TEST(pow_test_27) {
  double x = 0, exp = -INFINITY;
  ck_assert_int_eq(isinf(s21_pow(x, exp)), isinf(pow(x, exp)));
}
END_TEST

// Функция создания набора тестов.
Suite *s21_pow_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_pow");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  tc = tcase_create("s21_pow_case");
  // Добавление теста в группу тестов.
  tcase_add_test(tc, pow_test_0);
  tcase_add_test(tc, pow_test_1);
  tcase_add_test(tc, pow_test_2);
  tcase_add_test(tc, pow_test_3);
  tcase_add_test(tc, pow_test_4);
  tcase_add_test(tc, pow_test_5);
  tcase_add_test(tc, pow_test_6);
  tcase_add_test(tc, pow_test_7);
  tcase_add_test(tc, pow_test_8);
  tcase_add_test(tc, pow_test_9);
  tcase_add_test(tc, pow_test_10);
  tcase_add_test(tc, pow_test_11);
  tcase_add_test(tc, pow_test_12);
  tcase_add_test(tc, pow_test_13);
  tcase_add_test(tc, pow_test_14);
  tcase_add_test(tc, pow_test_15);
  tcase_add_test(tc, pow_test_16);
  tcase_add_test(tc, pow_test_17);
  tcase_add_test(tc, pow_test_18);
  tcase_add_test(tc, pow_test_19);
  tcase_add_test(tc, pow_test_20);
  tcase_add_test(tc, pow_test_21);
  tcase_add_test(tc, pow_test_22);
  tcase_add_test(tc, pow_test_23);
  tcase_add_test(tc, pow_test_24);
  tcase_add_test(tc, pow_test_25);
  tcase_add_test(tc, pow_test_26);
  tcase_add_test(tc, pow_test_27);
  // Добавление теста в тестовый набор.
  suite_add_tcase(s, tc);
  return s;
}

int test_pow(void) {
  int failed_count;
  Suite *suite = s21_pow_suite();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  // Получаем количество проваленных тестов.
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  if (failed_count != 0) {
    // Сигнализируем о том, что тестирование прошло неудачно.
    failed_count = 1;
  }

  return failed_count;
}
