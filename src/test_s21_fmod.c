#include <check.h>
#include <math.h>

#include "s21_math.h"
#include "s21_tests.h"
START_TEST(fmod_test_0) {
  double x = 0.0 / 0.0;
  double y = x;
  ck_assert_int_eq(isnan(s21_fmod(x, y)), isnan(fmod(x, y)));
}
END_TEST

START_TEST(fmod_test_1) {
  double x = 1.0;
  double y = 1.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.000001);
}
END_TEST

START_TEST(fmod_test_2) {
  double x = 1.000001;
  double y = 1.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.000001);
}
END_TEST

START_TEST(fmod_test_3) {
  double x = -1.000001;
  double y = 1.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.000001);
}
END_TEST

START_TEST(fmod_test_4) {
  double x = 9999999999.999999;
  double y = 343.3425;
  ck_assert_int_eq(isnan(s21_fmod(x, y)), isnan(fmod(x, y)));
}
END_TEST

START_TEST(fmod_test_5) {
  double x = 1150382508.34634;
  double y = 343345.342521;
  ck_assert_int_eq(isnan(s21_fmod(x, y)), isnan(fmod(x, y)));
}
END_TEST

START_TEST(fmod_test_6) {
  double x = 0.000001;
  double y = 0.0000001;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.000001);
}
END_TEST

START_TEST(fmod_test_7) {
  double x = -1243141.5231;
  double y = -0.000001;
  ck_assert_ldouble_eq(isnan(s21_fmod(x, y)), isnan(fmod(x, y)));
}
END_TEST

START_TEST(fmod_test_8) {
  double x = -INFINITY;
  double y = INFINITY;
  ck_assert_ldouble_eq(isnan(s21_fmod(x, y)), isnan(fmod(x, y)));
}
END_TEST

START_TEST(fmod_test_9) {
  double x = INFINITY;
  double y = -INFINITY;
  ck_assert_ldouble_eq(isnan(s21_fmod(x, y)), isnan(fmod(x, y)));
}
END_TEST

START_TEST(fmod_test_10) {
  double x = -0.0;
  double y = -0.0;
  ck_assert_ldouble_eq(isnan(s21_fmod(x, y)), isnan(fmod(x, y)));
}
END_TEST

START_TEST(fmod_test_11) {
  double x = +0.0;
  double y = 0.0;
  ck_assert_ldouble_eq(isnan(s21_fmod(x, y)), isnan(fmod(x, y)));
}
END_TEST

START_TEST(fmod_test_12) {
  double x = -3724653189365712;
  double y = 0.0;
  ck_assert_ldouble_eq(isnan(s21_fmod(x, y)), isnan(fmod(x, y)));
}
END_TEST

START_TEST(fmod_test_13) {
  double x = 0.0;
  double y = 3724653189365712;
  ck_assert_ldouble_eq(isnan(s21_fmod(x, y)), isnan(fmod(x, y)));
}
END_TEST

// Функция создания набора тестов.
Suite *s21_fmod_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_fmod");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  tc = tcase_create("s21_fmod_case");
  // Добавление теста в группу тестов.
  tcase_add_test(tc, fmod_test_0);
  tcase_add_test(tc, fmod_test_1);
  tcase_add_test(tc, fmod_test_2);
  tcase_add_test(tc, fmod_test_3);
  tcase_add_test(tc, fmod_test_4);
  tcase_add_test(tc, fmod_test_5);
  tcase_add_test(tc, fmod_test_6);
  tcase_add_test(tc, fmod_test_7);
  tcase_add_test(tc, fmod_test_8);
  tcase_add_test(tc, fmod_test_9);
  tcase_add_test(tc, fmod_test_10);
  tcase_add_test(tc, fmod_test_11);
  tcase_add_test(tc, fmod_test_12);
  tcase_add_test(tc, fmod_test_13);
  // Добавление теста в тестовый набор.
  suite_add_tcase(s, tc);
  return s;
}

int test_fmod(void) {
  int failed_count;
  Suite *suite = s21_fmod_suite();
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
