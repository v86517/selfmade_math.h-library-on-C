#ifndef S21_MATH_H
#define S21_MATH_H

// возвращает inf (бесконечность)
#define S21_INFINITY (1.0 / 0.0)
// #define S21_IS_INFINITY(x) (x == S21_INF_NEG || x == S21_INF_POS)

// возвращает nan (не число - не равно ничему и даже самому себе)
#define S21_NAN (0.0 / 0.0)
// #define S21_IS_NAN(x) (x != x)

// Эпсилон - точность численного типа данных
// (наименьшее положительное значение eps, для которого будет
// соблюдаться неравенство 1 + eps > 1).
#define S21_EPS 1e-9

// число e (число Эйлера)
#define S21_EXP 2.71828182845904523536028747

// число пи
#define S21_PI 3.1415926535897932384626433832795

// значение по модулю для аргумента типа int
int s21_abs(int x);
long double s21_fabs(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_sqrt(double x);
long double s21_pow(double base, double exp);
long double s21_factorial(long long int x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_atan(double x);
long double s21_tan(double x);
long double s21_acos(double x);
long double s21_asin(double x);

#endif