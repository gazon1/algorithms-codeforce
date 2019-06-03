if __name__ == '__main__':
    ar = list(map(int, input().split(' ')))
    answer = []
    for i in ar:
        if max(ar) - i > 0:
            answer.append(max(ar) - i)
    print(' '.join(list(map(str, answer))))
