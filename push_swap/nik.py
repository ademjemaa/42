import random
import subprocess
import time
import sys
is_exited = 0
try:
    stack_size = int(sys.argv[1]) 
    if (stack_size < 1):
        print("You must choose a bigger number")
        is_exited = 1
        exit()
except:
    if (not is_exited):
        print("You must send a number as an argument")
    exit()
arg = list(range(stack_size))
REPEAT = 50
total_operations = 0
ok_count = 0
for loop in range (REPEAT):
    random.shuffle(arg)
    print(arg)
    arg_str = ""
    for number in arg:
        arg_str += str(number)
        if (number != arg[stack_size - 1]):
            arg_str += " "
    try:
        push_swap_output = subprocess.check_output("./push_swap " + arg_str, shell=True)
    except:
        print("Push_swap returned 1, why ?")
        exit()
    if (push_swap_output == ""):
        count = 0
    else:
        splited = push_swap_output.split("\n")
        count = len(splited)
    print("count : " + str(count))
    try:
        f = open("tester_temp", "w")
        f.write(push_swap_output)
        f.close()
    except:
        print("Temp file couldn't be created, you might not have any space left on your device")
        exit()
    try:
        checker_output = subprocess.check_output("cat tester_temp | ./checker " + arg_str, shell=True)
    except:
        print("Checker returned 1, why ?")
        exit()
    print checker_output,
    if (checker_output == "OK\n"):
        ok_count += 1
    total_operations += count
subprocess.check_output("rm tester_temp", shell=True)
if (ok_count != REPEAT):
    print("Either the checker or push_swap isn't working properly, " + str(ok_count) + "/" + str(REPEAT))
else:
    print("Everything went well, all ok (keep in mind that if checker doesn't work well, it could print \"OK\" even if it doesn't work)")
print("Longueur moyenne de : " + str(total_operations / 50))
