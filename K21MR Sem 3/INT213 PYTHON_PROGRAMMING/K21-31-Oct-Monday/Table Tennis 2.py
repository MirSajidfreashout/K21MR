t = int(input())
for i in range(t):
    s = str(input())
    count = 0
    count1 = 0
    for i in range(len(s)):
        if s[i]=="0":
            count1+=1
        else:
            count+=1
    if count > count1:
        print("WIN")
    else:
        print("LOSE")