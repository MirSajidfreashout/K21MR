import collections

shoeNum = int(input())
shoes = collections.Counter(map(int, input().split()))
custNum = int(input())

income = 0

for i in range(custNum):
    size, price = map(int, input().split())
    if shoes[size]:
        income += price
        shoes[size] -= 1

print(income)