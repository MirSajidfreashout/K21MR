n, head, total = int(input()),list(input().split()), 0
for _ in range(n):
    total += int(list(input().split())[head.index('MARKS')])
print(total/n)