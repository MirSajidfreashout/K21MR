from itertools import combinations
n=int(input())
l=input().split()
k=int(input())
c = list(combinations(l,k))
f=filter(lambda c:'a' in c,c)
print("{0:.3}".format(len(list(f))/len(c)))