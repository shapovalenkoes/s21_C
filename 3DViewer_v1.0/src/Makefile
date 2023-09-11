PROJECTNAME=3DViewer

# Определение операционной системы, имена программ и параметров
UNAME = $(shell uname -s)
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11

# Пути до используемых папок
OBJ_DIR = tmp
TEST_DIR = unit_tests
REPORT_DIR = report
PROJECT_DIR = viewer
BUILD_DIR = build

# macOS
ifeq ($(UNAME),Darwin)
	CHECK=-lcheck -lm -lpthread -lgcov -fprofile-arcs -ftest-coverage
	OPEN = open
	MEMORY_TEST = leaks
	APP_DIR = $(PROJECT_DIR)/$(PROJECTNAME).app/Contents/MacOS/
# Ubuntu
else ifneq (,$(wildcard /etc/lsb-release))
	CHECK=-lcheck -lsubunit -lm -lrt -lpthread -lgcov -fprofile-arcs -ftest-coverage
	OPEN = xdg-open
	MEMORY_TEST = valgrind
	APP_DIR = $(PROJECT_DIR)
# Other linux
else ifeq ($(UNAME),Linux)
	CHECK=-lcheck -lm -lpthread -lrt -lgcov -fprofile-arcs
	MEMORY_TEST = valgrind
	OPEN = open
	APP_DIR = $(PROJECT_DIR)
endif



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
	cd $(PROJECT_DIR) && clang-format -n -style=Google *.c *.h *.cpp 
	cd $(TEST_DIR) && clang-format -n -style=Google *.c *.h

# Автоматическое форматирование по Google-style
format:
	@cd $(PROJECT_DIR) && clang-format -i -style=Google *.c *.h *.cpp 
	@cd $(TEST_DIR) && clang-format -i -style=Google *.c *.h

# Расширенная проверка статическим анализатором кода
cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem ./

# Проверка на утечки памяти для macOS
leaks: clean test
	leaks -atExit -- ./test
	
# Проверка памяти для Linux
valgrind: clean test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test

# @mv ./$(PROJECT_DIR)/$(PROJECTNAME).app ../build
install:
	@cd $(PROJECT_DIR) && qmake && make
	@mkdir -p ../$(BUILD_DIR)/ && mv $(APP_DIR)/$(PROJECTNAME) ../$(BUILD_DIR)/
	@echo "Install completed"
	@../$(BUILD_DIR)/$(PROJECTNAME)

uninstall:
	@rm -rf ../$(BUILD_DIR)
	@echo "Uninstall completed"

dvi:
	@doxygen viewer/Doxyfile

dist:
	@cd $(PROJECT_DIR) && make dist

# Сборка приложения для запуска тестов
test: clean_tests $(OBJ_DIR)
	@cd $(PROJECT_DIR) && for f in $(SOURCES); do $(CC) $(CFLAGS) $(CHECK) -c $$f -o $(OBJ_DIR)/$$f.o; done;
	@for f in $(TESTS); do $(CC) $(CFLAGS) -c $$f -o $(PROJECT_DIR)/$(OBJ_DIR)/$$f.o; done;
	@cd $(PROJECT_DIR) &&  $(CC) $(CFLAGS) -o $@ $(OBJ_DIR)/*.o $(OBJ_DIR)/$(TEST_DIR)/test*.o $(CHECK)
	@cd $(PROJECT_DIR) &&  ./$@

# Подготовка отчетов через gcovr
gcov: test
	@lcov -o report.info -c -d .
	@genhtml -o $(REPORT_DIR) report.info
	@mv report.info $(REPORT_DIR)/report.info
	@open $(REPORT_DIR)/index.html

# Создание временной папки для .o-файлов
$(OBJ_DIR):
	@mkdir -p $(PROJECT_DIR)/$(OBJ_DIR)/$(TEST_DIR)

# Удаление временных файлов и папок
clean:clean_tests
	@cd $(PROJECT_DIR) && make clean 
	@rm -rf ../$(BUILD_DIR)
	@cd $(PROJECT_DIR) && rm -rf docs

debug_help:
	$(CC) -g debug/main.c viewer/transformations.c viewer/load_model.c

clean_tests:
	@cd $(PROJECT_DIR) && rm -rf $(OBJ_DIR) test
	@rm -rf $(REPORT_DIR)

 # Перечисление целей, которые не являются названиями файлов
.PHONY: all check style cppcheck leaks format valgrind install unistall dvi dist test gcov clean clean_tests
