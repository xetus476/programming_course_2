import numpy as np
import matplotlib.pyplot as plt

with open("data.txt", "r") as f:
    line1 = list(map(float, f.readline().split()))
    line2 = list(map(float, f.readline().split()))
    point = list(map(float, f.readline().split()))

a1, b1, c1 = line1
a2, b2, c2 = line2
x0, y0 = point

x = np.linspace(-10, 10, 400)

y1 = (c1 - a1 * x) / b1
y2 = (c2 - a2 * x) / b2

plt.plot(x, y1, label='Prymay 1')
plt.plot(x, y2, label='Prymay 2')
plt.scatter(x0, y0)

plt.axhline(0)
plt.axvline(0)

plt.show()