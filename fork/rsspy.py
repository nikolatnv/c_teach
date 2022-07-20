import os
lines = []

with open(os.path.dirname("test.txt"), 'r') as f:
    lines = f.readlines()


for line in lines:
    print(line)


