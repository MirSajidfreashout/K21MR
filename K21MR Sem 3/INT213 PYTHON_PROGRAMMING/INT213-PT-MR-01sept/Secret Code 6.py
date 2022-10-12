# Rajesh is on a secret mission. His boss gave him a slip with a key number of a locker written on that. Locker has many secret documents which should be protected from spies who are chasing Rajesh to get that key. So that the key number does not get miss used by spies he decided to encrypt the number and converted it a new number by adding 1 in each digit. If digit is 9 them make it 0. Help Rajesh in finding this encrypted number.
t = int(input())
for i in range(t):
    code = input()
    for j in code:
        if j!='9': print(int(j)+1, end="")
        else: print(0, end="")
    print("", end="\n")