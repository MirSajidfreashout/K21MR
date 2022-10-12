import math
t = int(input())
for i in range(t):
    x,y=map(int,input().split())
    if(y>=x):
        print(0)
    else:
        print(math.ceil((x-y)/4))