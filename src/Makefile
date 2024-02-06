CC = gcc
OS = $(shell uname)
CFLAGS = -Wall -Werror -Wextra -g -std=c11

STRING_FUNC = $(wildcard ./string_functions/*.c)
SPRINTF_FUNC = $(wildcard ./sprintf_functions/*.c)
SCANF_FUNC = $(wildcard ./sscanf_functions/*.c)
PROCESSING_FUNC = $(wildcard ./processing_functions/*.c)
ALL_FUNC = $(STRING_FUNC) $(SPRINTF_FUNC) $(SCANF_FUNC) $(PROCESSING_FUNC)

SOURCE_TESTS_FUNC = $(wildcard ./tests/*.c)

ifeq ($(OS), Darwin)
	det_OS = -lcheck
	GCOV_FLAGS = -fprofile-arcs -ftest-coverage
else
	det_OS = -lcheck -lsubunit -lm -pthread -lrt
endif

all: s21_string.a

test:
	@$(CC) $(CFLAGS) $(det_OS) --coverage $(SOURCE_TESTS_FUNC) s21_string.a -o s21_test_string
	./s21_test_string

s21_string.a:
	@$(CC) $(CFLAGS) $(ALL_FUNC) $(GCOV_FLAGS) -c
	ar rc s21_string.a *.o
	ranlib s21_string.a

gcov_report:
	@lcov -t "s21_test_string" -o test.info --no-external -c -d .
	@genhtml -o report test.info
	open report/index.html
	rm -rf *.gcno *gcda *.gco

clean:
	rm -rf test *.gcda *.gcno *.o *.info *.a *.h.gch tests/*.gcno report 
	rm -rf s21_test_string.dSYM s21_test_string
	rm -rf tests/*.h.gch 

style:
	clang-format -n -style=google *.h $(ALL_FUNC) $(SOURCE_TESTS_FUNC)
	@rm -rf .clang-format

style_repair:
	@cp ../materials/linters/.clang-format ../src  
	@clang-format -i -style=google *.h $(ALL_FUNC) $(SOURCE_TESTS_FUNC)

leaks:
	leaks -atExit -- ./s21_test_string

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov
