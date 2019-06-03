def sol(n, skills):
    assert n == len(skills)
    skills.sort()
    max_team = 1
    j = 1
    for i in range(n):
        while j < n and abs(skills[i] - skills[j]) <= 5:
            j += 1
        max_team = max(max_team, j - i)
    print(max_team)

def test1():
    n = 6
    skills = [1, 10, 17, 12, 15, 2]
    sol(n, skills)

def test2():
    n = 10

    skills = list(map(int, "1337 1337 1337 1337 1337 1337 1337 1337 1337 1337".split()))
    sol(n, skills)

if __name__ == "__main__":
    n = int(input())
    skills = list(map(int, input().split()))
     # test1()
    sol(n ,skills)
    # test2()
