###############################################################################
#
# Computes Collatz conjecture (3x + 1) for specified range of numbers
#
##############################################################################

import timeit
from datetime import datetime

start = 1
num = start
max_height = 0

print("\nnumber height steps time\n")

start = timeit.default_timer()

while (True):

    steps = 0
    height = 0
    next_num = 0
    curr_num = num

    #print(num, flush=True)
    print(num , end='\r')

    while True:

        if (curr_num > height):
            height = curr_num

        if (curr_num % 2 == 0):
            curr_num = curr_num / 2
        else:
            curr_num = 3 * curr_num + 1

        steps += 1

        if curr_num <= 1:
            break

    if (height > max_height):

        max_height = height

        stop = timeit.default_timer()

        print(str(num) + " " + str(height) + " " + str(steps) + " " + str(round(stop - start, 1)))

    num += 1