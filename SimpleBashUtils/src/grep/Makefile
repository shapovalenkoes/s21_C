CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: s21_grep

s21_grep:
	$(CC) $(CFLAGS) s21_grep.c -o s21_grep

clean:
	rm -rf *.o  *.out *.a s21_grep

check:
	cppcheck --enable=all --suppress=missingIncludeSystem ../grep
	valgrind --tool=memcheck --leak-check=yes -s  ./s21_grep  -f test/patterns.txt s21_grep.c

format:
	clang-format -i *.c *.h

rebuild: clean all
