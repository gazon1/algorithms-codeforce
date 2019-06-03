
if __name__ == "__main__":    
    n = input()
    l = ''.join(input().split())
    l += l
    l = l.split('0')
    print(max(len(i) for i in l))
