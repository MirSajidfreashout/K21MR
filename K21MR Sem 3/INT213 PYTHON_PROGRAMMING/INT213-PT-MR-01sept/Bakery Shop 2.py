# A person opened a bakery shop. He wants a computer program who generate the bill for his shop including. The price of pastry is Rs 45 per piece. When it comes to GST on bakery items, GST on pastries is taxed at 18%.

# Input Format

# First line of input contains a single integer T denoting the number of test cases.

# The only line of each test case contains an integer Q denoting quantity of pastries.
t = int(input())
for i in range(t):
    q = int(input())
    print(round(q*45*1.18,2))