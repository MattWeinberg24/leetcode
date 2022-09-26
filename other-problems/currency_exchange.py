"""
Given
    A list of foreign exchange rates
    A selected curreny
    A target currency
Goal is to calculate the max amount of the target currency to
1 unit of the selected currency through the FX transactions.
Assume all transations are free and done immediately.
If you cannot finish the exchange, return -1.0.
"""

import sys
# import numpy as np
# import pandas as pd
# from sklearn import ...


def parse_exchange(rates: str) -> dict:
    d = {}
    for r in rates.split(';'):
        x = r.split(',')
        d[(x[0], x[1])] = float(x[2])
    return d


def exchange(d, origin, target, val):
    # positive base case
    if origin == target:
        return val
    best = -1.0
    # try each recursively
    for t in d:
        if t[0] == origin or t[1] == origin:
            # create d copy with only entries not containing origin
            temp = {}
            for t2 in d:
                if origin not in t2:
                    temp[t2] = d[t2]
            if t[0] == origin:
                n = exchange(temp, t[1], target, val * d[t])
            if t[1] == origin:
                n = exchange(temp, t[0], target, val * (1/d[t]))
            if n > best:
                best = n
    return best


d = None
origin = None
target = None

# parse input
for (i, l) in enumerate(sys.stdin):
    # exchange rates
    if i == 0:
        d = parse_exchange(l)
    elif i == 1:
        origin = l.strip()
    else:
        target = l.strip()

print(exchange(d, origin, target, 1), end="")
