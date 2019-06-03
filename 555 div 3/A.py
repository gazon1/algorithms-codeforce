def f(x):
    s = str(x + 1)
    i = len(s) - 1

    while s[i] == '0':
        i -= 1

    return int(s[:i + 1])


def test_f():
    assert(6 == f(599))
    assert(8 == f(7))
    assert(1 == f(9))
    assert(f(10099) == 101)

if __name__ == "__main__":
    x = int(input())
    s = {x}
    while f(x) not in s:
        x = f(x)
        s.add(x)

    print(len(s))
    
