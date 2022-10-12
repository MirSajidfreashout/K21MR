from fractions import Fraction


def main():
    total = 6*6
    count = 0

    for i in range(1, 7, 1):
        for j in range(1, 7, 1):
            if (i+j) <= 9:
                count += 1
    return Fraction(count, total)

print(main())
