import numpy as np
import matplotlib.pylab as plt


Datos=np.genfromtxt("mapa.csv")

plt.imshow(Datos)
plt.savefig("mapa.png")

print(Datos.shape)