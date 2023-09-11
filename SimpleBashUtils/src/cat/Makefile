CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: s21_cat

s21_cat:
	$(CC) $(CFLAGS) s21_cat.c -o s21_cat

clean:
	rm -rf *.o *.out *.a s21_cat

check:
	cppcheck --enable=all --suppress=missingIncludeSystem ../cat
	valgrind --tool=memcheck --leak-check=yes -s ./s21_cat s21_cat.c 
	
format:
	clang-format -i *.c *.h

rebuild: clean all
