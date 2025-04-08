#include "s21_math.h"

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
int s21_abs(int x) { return (x > 0) ? x : -x; }

// значение по модулю для аргумента типа double
long double s21_fabs(double x) {
  x = x >= 0 ? x : -x;
  return (long double)x;
}


// округление в большую сторону. возвращает ближайшее к аргументу целое
// значение, но это значение будет не меньше самого аргумента (1.2->2, 5.7->6,
// -1.2->-1, -5.7->-5)
long double s21_ceil(double x) {
  long double result =
      (long long int)x;  // lli меньше чем double, если поставить число больше
                         // 19 символов которое не помещается в lli, но
                         // помещается в double, то функция сломается
  if (s21_fabs(x) == S21_INFINITY || (x - (long long int)x) == 0) {
    result = x;
  } else if (x != x) {
    result = S21_NAN;
  } else if (x > 0) {
    result = result + 1;
  }
  return result;
}

// округление в меньшую сторону. возвращает ближайшее к аргументу целое
// значение, но это значение будет не больше самого аргумента (2.3->2, 3.8->3,
// -2.3->-3, -3.8->-4)
long double s21_floor(double x) {
  long double result = (long long int)x;
  if (s21_fabs(x) == S21_INFINITY || (x - (long long int)x) == 0) {
    result = x;
  } else if (x != x) {
    result = S21_NAN;
  } else if (x < 0) {
    result = result - 1;
  }
  return result;
}

// вычисляет остаток от деления и возвращает значение с плавающей точкой,
// оставшуюся часть от целочисленного деления аргументов x/y
long double s21_fmod(double x, double y) {
  long double int_part = 0.0, result = 0.0;
  if (y == 0 || x != x || y != y || x == S21_INFINITY || x == -S21_INFINITY) {
    result = S21_NAN;
  } else if (y == S21_INFINITY || y == -S21_INFINITY) {
    result = x;
  } else {
    int_part = (int)(x / y);
    result = x - int_part * y;  //  fractional part
  }
  return result;
}

// возвращает значение e, возведенное в заданную степень x. Ряд Тейлора ехр(х)=
// 1+х+(х^2)/2+(x^3)/6+(x^4)/24
long double s21_exp(double x) {
  int i = 1;
  long double next = 1.0;
  long double result = 1.0;
  double exp = x;
  if (exp != exp)
    result = S21_NAN;
  else if (exp < 0) {
    exp = -exp;
  }
  while (s21_fabs(next) > 1e-16) {
    next = next * (s21_fabs(exp) / i);
    i++;
    result += next;
    if (result > 1.7e+308) {  // 1.7e-308 максимум типа double(8 байт)
      result = S21_INFINITY;
      break;
    }
  }
  if (x < 0) {
    if (result > 1.7e+308) {
      result = 0;
    } else {
      result = 1.0 / result;
    }
  }

  return result;
}

// натуральный логарифм (функция обратная возведению в степень). Метод Галея
// y_n+1 =y_n + 2 *(x - exp(y_n))/(x + exp(y_n))
long double s21_log(double x) {
  if (x == S21_INFINITY) return x;
  if (x == 0) return -S21_INFINITY;
  if (x < 0) return S21_NAN;
  long double result = 0, previos = 0;
  int e_exp_number = 0;  // счетчик степеней - сколько раз можно поделить х на е
  for (; x >= S21_EXP; e_exp_number++) x = x / S21_EXP;
  for (int i = 0; i < 100; i++) {  // дальше подставляем х в формулу
    previos = result;
    result = previos + 2 * (x - s21_exp(previos)) / (x + s21_exp(previos));
  }
  result = result + e_exp_number;
  return result;
}

// вычисляет квадратный корень. Метод половинного деления
long double s21_sqrt(double x) {
  long double left = 0, right, mid;
  if (x != x || x == 0.0 || x == 1.0) return x;
  if (x < 0) return S21_NAN;
  right = x > 1 ? x : 1;  // определяем правый край больше или меньше 1
  while ((right - left) > S21_EPS) {  // пока отрезок больше заданной точности
    mid = (left + right) / 2;  // определяем середину отрезка
    if (mid * mid > x) {  // сдвигаем границы отрезка
      right = mid;
    } else {
      left = mid;
    }
  }
  mid = (left + right) / 2;
  return mid;
}

// возведение числа base в степень exp. Формула result = e ^ (exp * log(base))
////список проверок////
/*
Пусть a > 0 и а может быть четным или нечетным числом
pow(0, +-a)
pow(0, +-NAN)
pow(NAN, NAN)
pow(0, 0)
pow(0, -INF)
pow(-1, +-INF)
pow(1, exp), где exp = NAN/INF/0/a
pow(base, 0), где base = NAN/INF/a
pow(base, +-INF), где |base| < 1 или |base| > 1
pow(+-INF, exp), где exp = 0/a/INF/NAN
 */
long double s21_pow(double base, double exp) {
  long double result;
  long double pow_unsigned_exp = 1;
  long double rest_exp_part;
  unsigned int int_exp_part, i;
  if (base == 0.0) {
    if (exp < 0) result = S21_INFINITY;
    if (exp > 0) result = 0.0;
    if (exp == 0) result = 1.0;
  } else if (base == 1.0) {
    result = 1.0;
  } else if (exp == 0.0) {
    result = 1.0;
  } else if (base < 0 && base != -S21_INFINITY && s21_fmod(exp, 1) != 0 &&
             exp != S21_INFINITY && exp != -S21_INFINITY) {
    result = S21_NAN;
  } else if (base != base && exp != exp) {
    result = S21_NAN;
  } else if (exp == S21_INFINITY) {
    if (base == -1.0) result = 1.0;
    if (s21_fabs(base) < 1.0 && exp < 0) result = S21_INFINITY;
    if (s21_fabs(base) > 1.0 && exp > 0) result = S21_INFINITY;
    if (s21_fabs(base) < 1.0 && exp > 0) result = 0.0;
    if (s21_fabs(base) > 1.0 && exp < 0) result = 0.0;
  } else if (base == S21_INFINITY || base == -S21_INFINITY) {
    if (base < 0 && exp < 0) result = +0.0;
    if (base < 0 && exp < 0 && s21_fabs(s21_fmod(exp, 2)) == 1) result = -0.0;
    if (base < 0 && exp > 0) result = S21_INFINITY;
    if (base < 0 && exp > 0 && s21_fmod(exp, 2) == 1) result = -S21_INFINITY;
    if (base > 0 && exp < 0) result = +0.0;
    if (base > 0 && exp > 0) result = S21_INFINITY;
  } else if (exp == -S21_INFINITY) {
    if (base < 0) result = 0.0;
    if (base == -1.0) result = 1.0;
    if (base > -1.0) result = S21_INFINITY;
    if (base > 1.0) result = 0.0;
  } else {
    double copy_exp = exp;
    if (exp < 0) copy_exp = -exp;
    int_exp_part = (unsigned int)s21_floor(copy_exp);
    rest_exp_part = copy_exp - (long double)int_exp_part;
    for (i = 0; i < int_exp_part; i++)
      pow_unsigned_exp = pow_unsigned_exp * base;
    if (base > 0) pow_unsigned_exp *= s21_exp(rest_exp_part * s21_log(base));

    if (exp > 0) result = pow_unsigned_exp;
    if (exp < 0) result = 1 / pow_unsigned_exp;
  }
  return result;
}
/*
long double s21_factorial(long long int x) {
  long double result;
  if (x == 1 || x == 0)
    result = 1;
  else if (x < 0)
    result = S21_INFINITY;
  else
    result = x * s21_factorial(x - 1);
  return result;
}
*/
long double s21_sin(double x) {
  long double result;
  if (x == S21_INFINITY || x == -S21_INFINITY || x != x) {
    result = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    while (x > S21_PI) {
      x = x - 2 * S21_PI;
    }

    while (x < -S21_PI) {
      x = x + 2 * S21_PI;
    }
    result = x;
    int fact = 1;
    long double temp = x;
    while (s21_fabs(temp) > S21_EPS) {
      temp = (-temp * x * x) / ((2 * fact + 1) * (2 * fact));
      result = result + temp;
      fact++;
    }
  }
  return result;
}

long double s21_cos(double x) {
  long double result = 0;  //  cos(x) = sin(pi/2 + x)
  x = s21_fabs(x);         //  cos(-x) = cos(x)
  result = s21_sin(S21_PI / 2 + x);
  return result;
}

long double s21_atan(double x) {
  long double result = 0.0;
  if (x != x)
    result = S21_NAN;
  else if (s21_fabs(x) == S21_INFINITY)
    result = x > 0 ? S21_PI / 2 : -S21_PI / 2;
  else if (s21_fabs(x) == 1.0)
    result = x > 0 ? S21_PI / 4 : -S21_PI / 4;
  else if (x > 1.0) {
    result = (S21_PI / 2) - s21_atan(1 / x);
  } else if (x < -1.0) {
    result = -(S21_PI / 2) - s21_atan(1 / x);
  } else {
    result = 0;
    for (int i = 1; i < 50; i++) {
      result =
          result + (s21_pow(-1, i - 1) * s21_pow(x, 2 * i - 1) / (2 * i - 1));
    }
  }
  return result;
}

long double s21_tan(double x) {
  long double result = 0.0;
  if (x != x || x == 0.0)
    result = x;
  else if (x == S21_INFINITY)
    result = S21_NAN;
  else
    result = s21_sin(x) / s21_cos(x);
  return result;
}

long double s21_acos(double x) {
  long double result = 0.0;

  if (x != x || x == S21_INFINITY || s21_fabs(x) > 1.0)
    result = S21_NAN;
  else if (x == 1.0)
    result = 0.0;
  else if (x == 0.0)
    result = S21_PI / 2;
  else if (s21_fabs(x) > 1.0) {
    result = S21_NAN;
  } else if (x > 0) {
    result = s21_atan(s21_pow(1 - s21_pow(x, 2), 0.5) / x);
  } else {
    result = S21_PI + s21_atan(s21_pow(1 - s21_pow(x, 2), 0.5) / x);
  }
  return result;
}

long double s21_asin(double x) {
  long double result;

  if (x != x || x == S21_INFINITY || s21_fabs(x) > 1.0)
    result = S21_NAN;
  else if (x == 0)
    result = x;
  else if (x == 1.0)
    result = S21_PI / 2;
  else if (x == -1.0)
    result = -S21_PI / 2;
  else if (s21_fabs(x) < 1.0) {
    result = s21_atan(x / s21_pow(1 - s21_pow(x, 2), 0.5));
  } else {
    result = S21_NAN;
  }
  return result;
}
