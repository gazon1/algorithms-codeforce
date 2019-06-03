if __name__ == '__main__':
    N=int(input())
    n=list(map(int,input().split()))
    a,b=max(n),min(n)
    if (a-b)%2==0:
            D=(a-b)//2
            q=[a,b,a-D]
    else:
            D=(a-b)
            q=[a,b]
    for s in n:
            if s not in q:
                    D=-1
                    break
    print(D)
