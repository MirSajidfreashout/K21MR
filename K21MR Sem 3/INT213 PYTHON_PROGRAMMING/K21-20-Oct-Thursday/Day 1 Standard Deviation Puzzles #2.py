__author__ = 'namii'

mean = 0.675
sd = 0.065

height = 0.9025

result = abs(height - mean) / sd

print("{:.1f}".format(result))