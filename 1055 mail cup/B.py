def time_to_cut(ar, l):
    counter = 0
    flag = False

    for i in ar:
        if i > l:
            if not flag:
                counter += 1
                flag = True
        else:
            if flag:
                flag = False
    return counter


if __name__ == '__main__':
    n, m, l = list(map(int, input().split()))
    ar = list(map(int, input().split()))

    for i in range(m):
        query = list(map(int, input().split()))
        if query[0] == 0:
            print(time_to_cut(ar, l))
        else:
            ar[query[1] - 1] += query[2]
