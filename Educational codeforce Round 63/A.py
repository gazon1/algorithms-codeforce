if __name__ == "__main__":
    n = int(input())
    s = input()

    flag = False
    for i in range(n-1):
        if s[i] > s[i+1]:
            print("YES")
            print(i+1, i+2)
            flag = True
            break
    if not flag:
       print("NO")
