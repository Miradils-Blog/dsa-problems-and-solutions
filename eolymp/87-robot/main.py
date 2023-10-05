seq = input()

lefmost = rightmost = ind = 0

for cmd in seq:
    if cmd == 'R':
        ind += 1
        rightmost = max(rightmost, ind)
    elif cmd == 'L':
        ind -= 1
        lefmost = min(lefmost, ind)
    
print(rightmost - lefmost + 1)