a,b = int(input()),input().split()
print(all([int(i)>0 for i in b]) and any([j == j[::-1] for j in b]))