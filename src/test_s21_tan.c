#include <check.h>
#include <math.h>

#include "s21_math.h"
#include "s21_tests.h"

// Функция тестирования какой-либо задачи.
START_TEST(tan_test_0) {
  double x = 0.0 / 0.0;
  ck_assert_int_eq(isnan(s21_tan(x)), isnan(tan(x)));
}
END_TEST

START_TEST(tan_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
}
END_TEST

START_TEST(tan_test_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
}
END_TEST

START_TEST(tan_test_3) {
  double x = 9999999999.999999;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
}
END_TEST

START_TEST(tan_test_4) {
  double x = 1150382508.34634;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
}
END_TEST

START_TEST(tan_test_5) {
  double x = 0.000001;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
}
END_TEST

START_TEST(tan_test_6) {
  double x = -1243141.5231;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
}
END_TEST

START_TEST(tan_test_7) {
  double x = -INFINITY;
  ck_assert_int_eq(isnan(s21_tan(x)), isnan(tan(x)));
}
END_TEST

START_TEST(tan_test_8) {
  double x = INFINITY;
  ck_assert_int_eq(isnan(s21_tan(x)), isnan(tan(x)));
}
END_TEST

START_TEST(tan_test_9) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
}
END_TEST

START_TEST(tan_test_10) {
  double x = +0.0;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
}
END_TEST

START_TEST(tan_test_11) {
  double x = 12345678901;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
}
END_TEST

START_TEST(tan_test_12) {
  double x = -12345678901;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 0.000001);
}
END_TEST
// Функция создания набора тестов.
Suite *s21_tan_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_tan");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  tc = tcase_create("s21_tan_case");
  // Добавление теста в группу тестов.
  tcase_add_test(tc, tan_test_0);
  tcase_add_test(tc, tan_test_1);
  tcase_add_test(tc, tan_test_2);
  tcase_add_test(tc, tan_test_3);
  tcase_add_test(tc, tan_test_4);
  tcase_add_test(tc, tan_test_5);
  tcase_add_test(tc, tan_test_6);
  tcase_add_test(tc, tan_test_7);
  tcase_add_test(tc, tan_test_8);
  tcase_add_test(tc, tan_test_9);
  tcase_add_test(tc, tan_test_10);
  tcase_add_test(tc, tan_test_11);
  tcase_add_test(tc, tan_test_12);
  // Добавление теста в тестовый набор.
  suite_add_tcase(s, tc);
  return s;
}

int test_tan(void) {
  int failed_count;
  Suite *suite = s21_tan_suite();
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
