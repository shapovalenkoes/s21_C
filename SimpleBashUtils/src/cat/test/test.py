import os
from filecmp import cmp

success = 0
fail = 0
counter = 0

flags = ("b", "e", "n", "s", "t", "v")

s21_cat = "./s21_cat"
cat = "cat"
s21_cat_log = "s21cat.log"
cat_log = "cat.log" 

tests = (
"s21_cat.c",
"s21_cat.h Makefile",
"test/1.txt test/2.txt",
"no_file.txt"
)

gnu = (
"-T test/2.txt",
"-E test/2.txt",
"-vT test/2.txt",
"--number test/2.txt",
"--squeeze-blank test/1.txt",
"--number-nonblank test/2.txt",
"test/1.txt --number --number",
"-bnvste test/2.txt"
)
           
def run_tests():
    global success, fail, counter   
    counter += 1        
    os.system(f"{cat} {params} > {cat_log}")
    os.system(f"{s21_cat} {params} > {s21_cat_log}")
    if(cmp(cat_log, s21_cat_log)):
        success += 1
        print(f"{counter} - Success {params}")
    else:
        print(f" {counter} - Fail {params}")
        fail+= 1
    os.remove(s21_cat_log)
    os.remove(cat_log)


for params in gnu:
    run_tests()

for flag in flags:
    for test in tests:
        params = f"-{flag} {test}"
        run_tests()

for flag1 in flags:
    for flag2 in flags:
        if ((flag1 != flag2)):
            for test in tests:
                params = f"-{flag1}{flag2} {test}"
                run_tests()

for flag1 in flags:
        for flag2 in flags:
            if ((flag1 != flag2)):
                for flag3 in flags:
                    if ((flag1 != flag2) & (flag2 != flag3) & ( flag1 != flag3 )):                  
                        for test in tests:
                            params = f"-{flag1}{flag2}{flag3} {test}"
                            run_tests()

for flag1 in flags:
        for flag2 in flags:
            if ((flag1 != flag2)):
                for flag3 in flags:
                    if ((flag1 != flag2) & (flag2 != flag3) & ( flag1 != flag3 )):
                        for flag4 in flags:
                            if ((flag1 != flag2) & (flag2 != flag3) & ( flag1 != flag3 ) & ( flag1 != flag4 ) & ( flag2 != flag4 ) & ( flag3 != flag4 )):
                                for test in tests:
                                    params = f"-{flag1} -{flag2} -{flag3} -{flag4} {test}"
                                    run_tests()

print()
print(f"SUCCESS: {success}")
print(f"FAIL: {fail}")