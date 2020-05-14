import matplotlib.pyplot as plt
import numpy as np
f = open("fft.ian","r")
l1 = f.readline()
l2 = f.readline()
inp = []
out = []

x = l2.split(',')
for i in x:
    try:
        a = float(i)
        out.append(a)
    except:
        pass




######################################

from scipy.fft import fft
# Number of sample points
N = 4096
# sample spacing
T = 1.0 / 800.0
x = np.linspace(0.0, N*T, N)
y = 10 * np.sin(100.0 * 2.0*np.pi*x) + 5*np.sin(200.0 * 2.0*np.pi*x) + 2.5*np.sin(300.0 * 2.0*np.pi*x)

yf = fft(y)
xf = np.linspace(0.0, 1.0/(2.0*T), N//2)
temp = []
for i in range(len(out)//2):
    temp.append(out[i] * 2.0 / N)

fig, (ax1, ax2) = plt.subplots(2, 1)
ax1.plot(xf, 2.0/N * np.abs(yf[0:N//2]),'k')
ax1.grid()
ax1.set_ylabel("FFT Python")

ax2.plot(xf, temp, 'k')
ax2.grid()
ax2.set_ylabel("FFT Cooley-Tukey")

plt.xlabel("Frecuencias")
plt.show()

#import matplotlib.pyplot as plt
#plt.plot(xf, 2.0/N * np.abs(yf[0:N//2]))
#plt.grid()
#plt.show()

#plt.plot(xf, temp)
#plt.grid()
#plt.show()