nT = input()

def moves(a, b):
	m5 = (b - a) / 5
	d = (b - a) % 5
	m2 = d / 2
	m1 = d % 2
	return m5 + m2 + m1

for cs in range(T):
	N = input()
	ns = map(int, raw_input().strip().split())

	if len(ns) == 0:
		print 0
		continue
	
	m = min(ns)

	bmoves = 100000000

	for off in range(0, 5):
		nmoves = 0
		

		for n in ns:
			nmoves += moves(m, n)
		bmoves = min(nmoves, bmoves)
		m -= 1

	print bmoves
