if __name__ == "__main__":
    n = int(input())
    s = list(map(int, input().split()))

    
    i = 0
    j = n - 1

    ar = []
    if s[i] > s[j]:
        ar.append(s[j])
        j -= 1
    else:
        ar.append(s[i])
        i += 1

    for t in range(n):
        if s[i] > s[j]:
            if s[j] > ar[-1]:
                ar.append(s[j])
                j -= 1
            else:
                ar.append(s[i])
                i += 1
        else:
            if s[i] > ar[-1]:
                ar.append(s[i])
                i += 1
            else:
                ar.append(s[j])
                j -= 1
            
