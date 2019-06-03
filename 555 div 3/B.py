def sol(n, s, f):
    f = {k:v for k, v in zip(range(1, 11), f)}
    i = 0
    while i < n and f[s[i]] < s[i]:
        i += 1
    t = i
    while i < n and f[s[i]] >= s[i]:
        i += 1


    for j in range(t, i):
        s[j] = f[s[j]]

    return "".join([str(i) for i in s])


def test():
    assert("1557" == sol(4,
                         [1, 3, 3, 7],
                         [1, 2, 5, 4, 6, 6, 3, 1, 9]))

    result = sol(5,
                         [1, 1, 1, 1, 1],
                         [9, 8, 7, 6, 5, 4, 3, 2, 1])

    assert "99999" == result, result


    result = sol(4,
                 [9, 4, 5, 3],
                 [8, 8, 8, 8, 8, 8, 8, 8, 1])

    assert "9888" == result, result
                         

if __name__ == "__main__":
#    n = int(input())
#    s = [int(i) for i in input()]
#    f = list(map(int, input().split()))


#    print(sol(n, s, f))
    test()
