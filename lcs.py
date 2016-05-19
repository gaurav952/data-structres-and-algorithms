import time
from collections import defaultdict
def lcs(x, y):
    if not (x and y): return # if strings are empty
    lcs = [''] #  longest common subsequence
    lcslen = 0 # length of longest common subsequence so far
    location = defaultdict(list)
    i = 0
    for k in y:
        location[k].append(i)
        i += 1
    for i in xrange(len(x)):
        cs = '' 
        index = -1
        reached_index = defaultdict(int)
        for item in x[i:]:
            for index_ in location[item][reached_index[item]:]:
                reached_index[item] += 1
                if index < index_:
                    cs += item # add item to the cs
                    index = index_
                    break
            if index == len(y) - 1: break

        if len(cs) > lcslen: lcs, lcslen = [cs], len(cs) 
        elif len(cs) == lcslen: lcs.append(cs)
    return lcs

f1 = open('/home/gaurav/f1')
f2 = open('/home/gaurav/f2')
x = f1.read()
y = f2.read()

start = time.time()
lcss = lcs(x, y)
elapsed = (time.time() - start)
print elapsed
