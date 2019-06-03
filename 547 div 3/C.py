from collections import Counter

def add_int_to_list(l, i):
    for j in range(len(l)):
        l[j] += i
    return l

if __name__ == "__main__":
    n = int(input())
    ar = list(map(int, input().split()))

    for i in range(n - 2):
        ar[i + 1] += ar[i]


    counts_perm = Counter(range(1, n + 1))

    ans = False
    for i in range(1, n + 1):
        t = add_int_to_list(ar[:], i)
        t.append(i)

        if Counter(t) == counts_perm:
            print(" ".join(map(str, t)))
            ans = True
            break
    if not ans:
        print(-1)


    
