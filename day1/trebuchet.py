total = 0
with open('trebuchet.txt', 'r') as f:
    for line in f:
        nums = []
        for c in line:
            if c.isnumeric():
                nums.append(int(c))
        total += nums[0] * 10 + nums[-1]

print(total)