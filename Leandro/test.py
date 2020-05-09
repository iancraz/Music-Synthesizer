import numpy as np
import matplotlib.pyplot as plt
import math
from scipy.io import wavfile

with open('debug.txt') as data:
    y = data.readlines()
    y = [10*float(i) for i in y]

t = np.arange(0, len(y))/44100
y = np.array(y, dtype=np.float32)
wavfile.write('data2.wav', 44100, y)
plt.plot(t,y)
plt.show()