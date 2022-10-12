# A person opened McDonalds. He wants a computer program who generate the bill for his McDonalds including GST.

# The price of McVeggie is Rs 98 per piece. When it comes to GST, GST on burger is taxed at 18%.

# Input Format

# First line of input contains a single integer T denoting the number of test cases.

# The only line of each test case contains an integer Q denoting quantity of burger.
t = int(input())
for i in range(t):
    x = int(input())
    print(round(x*98*1.18,2))