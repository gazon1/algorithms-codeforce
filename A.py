def sol(l:list):
    pos, neg, z = 0, 0, 0
    for i in l:
        if i > 0:
            pos += 1
        elif i == 0:
            z += 1
        else:
            neg += 1
    
    N = math.ceil(len(l) / 2)
    if pos >= N:
        return 1
    elif neg >= N:
        return -1
    else:
        return 0
    
#if __name__ == "__main__":
N = [int(x) for x in input().split()][0]
ar = [int(x) for x in input().split()]
print(sol(ar))
