_ = list(map(int, input().split()))
n, m = _
if m % n == 0:
    m = m // n
    counter = 0
    while m % 2 == 0:
        m = m // 2
        counter += 1

    while m % 3 == 0:
        m = m // 3
        counter += 1
    if m == 1:
        print(counter)
    else:
        print(-1)
else:
    print(-1)
    
