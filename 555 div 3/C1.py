class mystr:
    def __init__(self):
        self.s = ''
        
    def __add__(self, o: str):
        self.s += o
        return self.s
    def __str__(self):
        return self.s
    def __len__(self):
        return len(self.s)

    
def left_move(ar, moves):
    moves += 'L'
    return ar.pop(0)

    
def right_move(ar, moves):
    moves += 'R'
    return ar.pop(-1)

if __name__ == "__main__":
    n = int(input())
    ar = list(map(int, input().split()))

    n = len(ar)
    moves = ''
    last_el = None
    i = 0
    j = n - 1
    
    if ar[i] < ar[j]:
        last_el = ar[i]
        i += 1
        moves += 'L'
    else:
        last_el = ar[j]
        j -= 1
        moves += 'R'



    while i <= j and max(ar[i], ar[j]) > last_el:
        if last_el < ar[i] < ar[j] or ar[j] < last_el < ar[i]:
            last_el = ar[i]
            moves += 'L'
            i += 1
        elif last_el < ar[j] < ar[i] or ar[i] < last_el < ar[j]:
            last_el = ar[j]
            moves += 'R'
            j -= 1
        elif (ar[j] == ar[i]) and last_el < ar[i]:
            last_el = ar[j]
            moves += 'L'
            i += 1

    print(len(moves))
    print(moves)	  last_el = ar[j]
						     moves += 'R'
						     j -= 1

