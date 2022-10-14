t = int(input())
for i in range(t):
    vals=[int(i) for i in input().split()]
    px=vals[0]
    py=vals[1]
    qx=vals[2]
    qy=vals[3]
    rx = 2*qx-px
    ry = 2*qy-py
    print(rx,ry)