#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'solve' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY a as parameter.
#

def solve(a):
    res = list()
    sum_a = list()
    n = 0
    for i in a:
        n += i
        sum_a.append(n)
    sum_a = set(sum_a)
    res.append(n)
    for i in range(2, n//max(a)+1):
        if n % i == 0:
            m = n // i
            sum_m = list()
            for j in range(1, i+1):
                sum_m.append(j*m)
            sum_m = set(sum_m)
            if sum_m.issubset(sum_a):
                res.append(m)
    return sorted(res)
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a_count = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = solve(a)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
