CC = gcc
FL = -Wall -Werror -Wextra -std=c11
FL_O = -o
FL_C = -c
FL_T = -t
FL_D = -d
FUN = ./s21_functions/
OS := $(shell uname)

ifeq ($(OS),Linux)
FLAGS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
OPENF = xdg-open
else
FLAGS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
OPENF = open
endif

all: clean s21_matrix.a test gcov_report
	@mkdir spare_files
	@mv *.o *.a *.info spare_files
	-rm -rf ./spare_files/*.o

test: clean s21_matrix.a
	$(CC) $(FL) s21_test.c $(FUN)*.c s21_matrix.a s21_tests/*.c $(FLAGS) $(FL_O) unit_test
	./unit_test

s21_matrix.a:
	$(CC) $(FL) $(FL_C) $(FUN)s21_*.c
	ar -crs s21_matrix.a s21_*.o
	ranlib s21_matrix.a

gcov_report: clean test
	lcov $(FL_T) "./unit_test"  $(FL_O) report.info --no-external $(FL_C) $(FL_D) .
	genhtml $(FL_O) report report.info
	$(OPENF) ./report/index.html
	-rm -rf *.gcno *gcda *.gco

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt *.gch unit_test
	-rm -rf tests
	-rm -rf report
	-rm -rf spare_files
	-rm -rf .clang-format
	find . -type d -name 'tests.dSYM' -exec rm -r {} +

check:
	cp ../materials/linters/.clang-format ./
	clang-format -style=Google -n *.c *.h ./*/*.c

reform:
	cp ../materials/linters/.clang-format ./
	clang-format -style=Google -i *.c *.h ./*/*.c

rebuild: clean all