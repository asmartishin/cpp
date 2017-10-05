#!/usr/bin/env python3

import sys


if __name__ == '__main__':
    h, m, s, t1, t2 = map(lambda x: int(x), sys.stdin.read().split())

    h = h if h != 12 else 0
    m == m if m != 60 else 0

    t1 = t1 if t1 != 12 else 0
    t2 = t2 if t2 != 12 else 0

    ha = 30 * h + 0.5 * m + s / 120;
    ma = 6 * m + 0.1 * s;
    sa = 6 * s;

    t1a = 30 * t1;
    t2a = 30 * t2;

    tmin = min(t1a, t2a)
    tmax = max(t1a, t2a)

    result = False

    if all(tmin < x < tmax for x in (ha, ma, sa)):
        result = True
    elif all(x < tmin or x > tmax for x in (ha, ma, sa)):
        result = True

    if result:
        print('YES')
    else:
        print('NO')
