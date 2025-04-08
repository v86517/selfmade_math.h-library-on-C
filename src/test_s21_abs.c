#include <check.h>
#include <math.h>

#include "s21_math.h"
#include "s21_tests.h"

// Функция тестирования какой-либо задачи.
START_TEST(abs_test_1) {
  int x = 99999946;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_2) {
  int x = -54367685;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_3) {
  int x = 32200;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_4) {
  int x = 0;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_5) {
  int x = -3645.564;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_6) {
  int x = 5433;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_7) {
  int x = -5715652;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_8) {
  int x = 3254.24;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_9) {
  int x = -0.0;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_10) {
  int x = +0.0;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_11) {
  int x = -1;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_12) {
  int x = 1;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

// Функция создания набора тестов.
Suite *s21_abs_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_abs");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  tc = tcase_create("s21_abs_case");
  // Добавление теста в группу тестов.
  tcase_add_test(tc, abs_test_1);
  tcase_add_test(tc, abs_test_2);
  tcase_add_test(tc, abs_test_3);
  tcase_add_test(tc, abs_test_4);
  tcase_add_test(tc, abs_test_5);
  tcase_add_test(tc, abs_test_6);
  tcase_add_test(tc, abs_test_7);
  tcase_add_test(tc, abs_test_8);
  tcase_add_test(tc, abs_test_9);
  tcase_add_test(tc, abs_test_10);
  tcase_add_test(tc, abs_test_11);
  tcase_add_test(tc, abs_test_12);
  // Добавление теста в тестовый набор.
  suite_add_tcase(s, tc);
  return s;
}

int test_abs(void) {
  int failed_count;
  Suite *suite = s21_abs_suite();
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