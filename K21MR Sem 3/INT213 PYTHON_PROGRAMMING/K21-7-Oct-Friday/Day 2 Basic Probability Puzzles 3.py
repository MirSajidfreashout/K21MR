from fractions import Fraction
from pickle import FRAME
p1 = ['r']*4 + ['b']*3
p2 = ['r']*5 + ['b']*4
p3 = ['r']*4 + ['b']*4

combo = []
visited = 0
for i in p1:
    for j in p2:
        for k in p3:
            temp = [i,j,k]
            count_r = temp.count('r')
            count_b = temp.count('b')
            if(count_r==2) and (count_b==1):
                combo.append(temp)

            visited += 1

print(Fraction(len(combo), visited))