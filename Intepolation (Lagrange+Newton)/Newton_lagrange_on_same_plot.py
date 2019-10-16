import matplotlib.pyplot as plt
import numpy as np

def readfile(filename):
	coordinates = []
	with open(filename) as f:
		lines = f.readlines()
		for line in lines[1:]: 
			values = line.split()
			coordinate = (float(values[0]) ,
				 float(values[1]) )
			coordinates.append(coordinate)
	return coordinates
	
def lagrange(coordinates, x):
	n = len(coordinates)
	y = 0.0
	
	for i in range(n):
		fi = coordinates[i][1]
		prod = fi
		for j in range(n):
			if j !=i:
				xi = coordinates[i][0]
				xj = coordinates[j][0]
				prod = prod * ((x-xj)/(xi-xj))
		y+=prod
	return y
		

coordinates = readfile("data.txt")
X = [-7.0, -9.0, 0.0, 9.0, 8.0, 3.0, -3.0 ]
Y = [2.0, 8.0, 1.0, 9.0, 5.0, -3.0, -7.0]


xs = np.arange(-10,10,0.1)
ys = []
for x in xs:
	ys.append(lagrange(coordinates, x))
	
plt.plot(xs, ys)
plt.plot(X,Y,'o')
#plt.show()



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

x  = np.linspace(-10,10,1000)
y = f(x)
plt.plot(x, y)
plt.plot(X, Y, 'o')
plt.show()

