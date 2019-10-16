import numpy as np
def b(X, Y, l, r):
	if l==r:
		return Y[l]
	return ( b(X, Y, l+1, r) - b(X, Y, l, r-1) )/(X[r]-X[l])

#coordinates = readfile("data.txt")
X = [-7.0, -9.0, 0.0, 9.0, 8.0, 3.0, -3.0 ]
Y = [2.0, 8.0, 1.0, 9.0, 5.0, -3.0, -7.0]

def f(x):
	sum_ = 0.
	for i in range(len(X)):
		print(i)
		mul = b(X, Y, 0, i)
		for j in range(i):
			mul *= (x-X[j])
		sum_ += mul
	return sum_
	


for i in range(len(X)):
	print(b(X,Y,0,i))

print(f(9))


import matplotlib.pyplot as plt

x  = np.linspace(-10,10)
y = f(x)
plt.plot(x, y)
plt.plot(X, Y, 'o')
plt.show()

