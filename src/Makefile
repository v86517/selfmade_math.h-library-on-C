CC = gcc
ifeq ($(shell uname), Darwin)
	LIBS = $(shell pkg-config --libs check)
else
	LIBS = -lcheck -lsubunit -lrt -lm -lpthread
endif

CFLAGS = -c -Wall -Werror -Wextra -std=c11 $(LIBS)

all: s21_math.a

test: gcov_s21_math.a
	$(CC) $(CFLAGS) test_*.c
	$(CC) --coverage *.o s21_math.a $(LIBS) -o s21_math_test
	./s21_math_test

clean:
	rm -rf *.o s21_*_test *.gcda *.gcno *.css *.html *.gcov *.a report

s21_math.a:
	$(CC) $(CFLAGS) s21_*.c
	ar rc s21_math.a s21_*.o
	ranlib s21_math.a

gcov_s21_math.a:
	rm -f s21_math.a
	$(CC) --coverage $(CFLAGS) s21_*.c
	ar rc s21_math.a s21_*.o
	ranlib s21_math.a

gcov_report: test
	mkdir -p report
	gcov s21_*.gcda
	gcovr -b --html-details -o ./report/report.html

	
rebuild: clean all

style_fix:
	cp ../materials/linters/.clang-format ../src/.clang-format; \
	clang-format -i *.c *.h --style=Google
	rm .clang-format

style:
	cp ../materials/linters/.clang-format ../src/.clang-format; \
	clang-format -style=Google -n *.c *.h; \
	rm .clang-format

.PHONY: all test clean gcov_report rebuild style style_fix