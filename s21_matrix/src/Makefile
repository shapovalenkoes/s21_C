PROJECTNAME=s21_matrix

# Определение операционной системы, имена программ и параметров
UNAME = $(shell uname -s)
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
# macOS
ifeq ($(UNAME),Darwin)
	CHECK=-lcheck -lm -lpthread -lgcov -fprofile-arcs -ftest-coverage
	OPEN = open
	MEMORY_TEST = leaks
# Ubuntu
else ifneq (,$(wildcard /etc/lsb-release))
	CHECK=-lcheck -lsubunit -lm -lrt -lpthread -lgcov -fprofile-arcs -ftest-coverage
	OPEN = xdg-open
	MEMORY_TEST = valgrind
# Other linux
else ifeq ($(UNAME),Linux)
	CHECK=-lcheck -lm -lpthread -lrt -lgcov -fprofile-arcs
	MEMORY_TEST = valgrind
endif

# Пути до используемых папок
OBJ_DIR = obj
TEST_DIR = unit_tests
REPORT_DIR = report

# Списки различных файлов
SOURCES:= s21_*.c
TESTS:= $(TEST_DIR)/test*.c
LIB = $(PROJECTNAME).a

# Указываем список каталогов, в которых make выполняет поиск
vpath %.c $(SOURCES) : $(TESTS)
vpath %.o $(OBJ_DIR)

# ЦЕЛИ СБОРКИ

# Цель по-умолчанию: проверка стилей, запуск тестов, отчет и библиотека
all: check test gcov_report $(LIB)

# Запуск всех проверок
check: style cppcheck $(MEMORY_TEST)

# Проверка на Google-style
style:
	clang-format -n -style=Google *.c *.h
	clang-format -n -style=Google unit_tests/*.c unit_tests/*.h

# Автоматическое форматирование по Google-style
format:
	clang-format -i -style=Google *.c *.h
	clang-format -i -style=Google unit_tests/*.c unit_tests/*.h

# Расширенная проверка статическим анализатором кода
cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem ./

# Проверка на утечки памяти для macOS
leaks: clean test
	leaks -atExit -- ./test
	
# Проверка памяти для Linux
valgrind: clean test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test

# Сборка библиотеки для вертера без тестов и покрытия кода
$(LIB): $(OBJ_DIR)
	@for f in $(SOURCES); do $(CC) $(CFLAGS) -c $$f -o $(OBJ_DIR)/$$f.o; done;
	@ar rcs $(LIB) $(addprefix $(OBJ_DIR)/, s21_*.o)

# Сборка приложения для запуска тестов
test: clean $(OBJ_DIR)
	@for f in $(SOURCES); do $(CC) $(CFLAGS) $(CHECK) -c $$f -o $(OBJ_DIR)/$$f.o; done;
	@for f in $(TESTS); do $(CC) $(CFLAGS) -c $$f -o $(OBJ_DIR)/$$f.o; done;
	@$(CC) $(CFLAGS) -o $@ $(OBJ_DIR)/s21_*.o $(OBJ_DIR)/$(TEST_DIR)/test*.o $(CHECK)
	@./$@

# Подготовка отчетов через gcovr
gcov_report: test 
	@lcov -o report.info -c -d .
	@genhtml -o $(REPORT_DIR) report.info
	@mv report.info $(REPORT_DIR)/report.info
	@open $(REPORT_DIR)/index.html


# Подготовка докера для его работы на goinfre
init_docker:
	rm -rf ~/Library/Containers/com.docker.docker
	mkdir -p ~/goinfre/Docker/Data
	ln -s ~/goinfre/Docker ~/Library/Containers/com.docker.docker

# Запуск мини-вертера (проверка на стили и корректность сборки Makefile)
docker: $(LIB)
	cd ../materials/build && sh run.sh

# Запуск докера с тестами и valgrind
docker_test: clean
	cd docker && sh run.sh

# Пересборка проекта (при этом не изменившиеся модули не пересобираются)
rebuild:
	make -B

# Создание временной папки для .o-файлов
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(TEST_DIR)

# Удаление временных файлов и папок
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(REPORT_DIR)
	@rm -f test
	@rm -f *.a
	@rm -f *.o
	@rm -f $(TEST_DIR)/*.o
	@rm -f *.gc*
	@rm -f *.log

 # Перечисление целей, которые не являются названиями файлов
.PHONY: all check style cppcheck leaks format valgrind test gcov_report init_docker docker docker_test rebuild clean