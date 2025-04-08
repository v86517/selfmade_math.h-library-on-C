#include "s21_tests.h"

int main(void) {
  int res = 0;
  res += test_atan();
  res += test_asin();
  res += test_acos();
  res += test_sqrt();
  res += test_ceil();
  res += test_floor();
  res += test_log();
  res += test_exp();
  res += test_pow();
  res += test_fmod();
  res += test_abs();
  res += test_sin();
  res += test_cos();
  res += test_tan();
  res += test_fabs();
  printf("Failed tests: %d\n", res);
  return 0;
}
