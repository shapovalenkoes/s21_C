import os
from filecmp import cmp

success = 0
fail = 0
counter = 0

flags = ("v", "c", "l", "n", "h", "o")

s21_grep = "./s21_grep"
grep = "grep"
s21_grep_log = "s21grep.log"
grep_log = "grep.log" 

tests = (
"inc s21_grep.c",
"-e params s21_grep.h -e for Makefile",
"-e for -e ^int s21_grep.c s21_grep.h Makefile",
"-e regex -e ^print s21_grep.c -f test/patterns.txt",
"-e while -e void s21_grep.c Makefile -f test/patterns.txt",
"-e include -e inc s21_grep.c",
"-e inc -e include s21_grep.c"
)
           
def run_tests():
    global success, fail, counter   
    counter += 1        
    os.system(f"{grep} {params} > {grep_log}")
    os.system(f"{s21_grep} {params} > {s21_grep_log}")
    if(cmp(grep_log, s21_grep_log)):
        success += 1
        print(f"{counter} - Success {params}")
    else:
        print(f" {counter} - Fail {params}")
        fail+= 1
    os.remove(s21_grep_log)
    os.remove(grep_log)

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