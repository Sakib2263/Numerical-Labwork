import numpy as np


#read points from file
file = open('b.txt', 'r')
lines = file.readlines()
count = int(lines[0])

print("Number of Points : ")
print(count)

x = []
f = []

for i in range(1, count+1):
	x_, f_ = (float(val) for val in lines[i].split())
	x.append(x_)
	f.append(f_)


n = len(x) - 1
h = [0.]
for i in range(1, n+1):
    h.append(x[i]-x[i-1])
A = np.zeros((n+1,n+1))
B = np.zeros((n+1, 1))
for i in range(0, n+1):
    if i == 0:
        A[i][i] = 1.
    elif i == n:
        A[i][i] = 1.
    else:
        A[i][i] = 2.*(h[i] + h[i+1])
        A[i][i-1] = h[i]
        A[i][i+1] = h[i+1]

for i in range(0, n+1):
    if i == 0:
        B[i][0] = 0 # natural boundary
    elif i == n:
        B[i][0] = 0 # natural boundary
    else:
        B[i][0] = 6.*(
            (f[i+1]-f[i])/h[i+1] - (f[i]-f[i-1])/h[i]
        )
        
print("Matrix of A")
print(A)
print("Matrix of D")
print(B)
#solving [A]x=[b]  for the value of x , x = inv[A].[B]
sol = np.matmul(np.linalg.inv(A), B)

print("values of a0,a1,...,an -- a0=an=0" )
print(sol)

f0 = np.zeros((n,4))
for i in range(0, n):
	f0[i][0] = (sol[i+1][0] - sol[i][0]) / (6.*h[i+1])
	f0[i][1] = sol[i][0]/2.
	f0[i][2] = (f[i+1]-f[i])/h[i+1] - ((2.*h[i+1]*sol[i][0] + h[i+1]*sol[i+1][0]))/6.
	f0[i][3] = f[i]
print(f0)

import matplotlib.pyplot as plt
for i in range(n):
    X = np.linspace(x[i],x[i+1])  #new x for plot
    Y = f0[i][3] + f0[i][2]*(X-x[i]) + f0[i][1]*(X-x[i])**2 + f0[i][0]*(X-x[i])**3   #y values for plot
    plt.plot(X,Y)

plt.scatter(x,f)
plt.plot(X,Y)
plt.show()
