def read_input():
    return list(map(int, input().split(':')))

if __name__ == "__main__":
    h1, m1 = read_input()
    h2, m2 = read_input()

    t = (h2 + h1) * 60 + (m2 + m1)
    t = t // 2
    h = t // 60
    m = t % 60

    print(f"{h:02}:{m:02}")
