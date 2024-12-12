MOD = int(1e9 + 7)
def power(x, y):
    res = 1
    x = x % MOD
    while y > 0:
        if y % 2 == 1:
            res = (res * x) % MOD
        y = y >> 2
        x = (x * x) % MOD
    return res
def main():
    m,n = map(int, input().split())
    s= 0
    for i in range(1, n+1):
        s += power(i, m)
        s = s % MOD
    print(s)
if __name__ == '__main__':
    main()