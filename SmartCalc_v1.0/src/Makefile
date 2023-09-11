PROJECTNAME=SmartCalc_v1

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
TEST_DIR = ../unit_tests
REPORT_DIR = report

# Списки различных файлов
SOURCES:= *.c
TESTS:= $(TEST_DIR)/test*.c

# Указываем список каталогов, в которых make выполняет поиск
vpath %.c $(SOURCES) : $(TESTS)
vpath %.o $(OBJ_DIR)

# ЦЕЛИ СБОРКИ

# Цель по-умолчанию: проверка стилей, запуск тестов, отчет и библиотека
all: clean install

# Запуск всех проверок
check: style cppcheck 

# Проверка на Google-style
style:
	clang-format -n -style=Google *.c *.h *.cpp
	clang-format -n -style=Google $(TEST_DIR)/*.c $(TEST_DIR)/*.h

# Автоматическое форматирование по Google-style
format:
	clang-format -i -style=Google *.c *.h *.cpp 
	clang-format -i -style=Google $(TEST_DIR)/*.c $(TEST_DIR)/*.h

# Расширенная проверка статическим анализатором кода
cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem ./

# Проверка на утечки памяти для macOS
leaks: clean test
	leaks -atExit -- ./test
	
# Проверка памяти для Linux
valgrind: clean test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test

install:
	@mkdir -p ../build
	@cd SmartCalc_v1 && qmake && make && make clean && rm -rf Makefile && mv $(PROJECTNAME) ../../build/$(PROJECTNAME).app
	@cp -R ../build/$(PROJECTNAME).app ~/Desktop/$(PROJECTNAME).app
	@echo "Install completed"

uninstall:
	@rm -rf ~/Desktop/$(PROJECTNAME).app ../build
	@echo "Uninstall completed"

dvi:
	@open ../README_RUS.md

dist:
	@mkdir -p ../dist
	@cp -R ../build/$(PROJECTNAME).app ../dist
	@cp ../README_RUS.md ../dist && cp ../README.md ../dist
	@cd ../dist && tar cvzf $(PROJECTNAME).tgz *
	@cd ../dist && rm -rf $(PROJECTNAME).app README.md README_RUS.md
	@echo "The build was successfully archived"

# Сборка приложения для запуска тестов
test: clean $(OBJ_DIR)
	@cd SmartCalc_v1 && for f in $(SOURCES); do $(CC) $(CFLAGS) $(CHECK) -c $$f -o $(OBJ_DIR)/$$f.o; done;
	@cd SmartCalc_v1 && for f in $(TESTS); do $(CC) $(CFLAGS) -c $$f -o $(OBJ_DIR)/$$f.o; done;
	@cd SmartCalc_v1 &&  $(CC) $(CFLAGS) -o $@ $(OBJ_DIR)/*.o $(OBJ_DIR)/$(TEST_DIR)/test*.o $(CHECK)
	@cd SmartCalc_v1 &&  ./$@

# Подготовка отчетов через gcovr
gcov_report: test
	@lcov -o report.info -c -d .
	@genhtml -o $(REPORT_DIR) report.info
	@mv report.info $(REPORT_DIR)/report.info
	@open $(REPORT_DIR)/index.html

# Пересборка проекта (при этом не изменившиеся модули не пересобираются)
rebuild:
	make -B

# Создание временной папки для .o-файлов
$(OBJ_DIR):
	@cd SmartCalc_v1 &&  mkdir -p $(OBJ_DIR)/$(TEST_DIR)

# Удаление временных файлов и папок
clean:
	@cd SmartCalc_v1 && rm -rf $(OBJ_DIR) $(REPORT_DIR) test *.a *.o unit_tests *.gc* *.log 
	@rm -rf ../build ../dist report

 # Перечисление целей, которые не являются названиями файлов
.PHONY: all check style cppcheck leaks format valgrind install unistall dvi dist test gcov_report rebuild clean
