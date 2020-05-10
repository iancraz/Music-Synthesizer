import matplotlib.pyplot as plt
import numpy

#Recibe parametros en la data del tipo
# Fs,NFFT,Window\n
#datos

f = open("data.ian","r")
f1 = f.readline()
f2 = f.readline()
time = []
timevec = []
y = f1.split(',')
fs = int(y[0])
nfft = int(y[1])
window = int(y[2])
save = int(y[3])



y = f2.split(',')
for i in y:
    try:
        a = float(i)
        time.append(a)
    except:
        time.pop()
        pass

for i in range(len(time)):
    timevec.append(i)
timevec = [x * 1/fs for x in timevec]
fig, (ax1, ax2) = plt.subplots(2, 1)
ax1.plot(timevec,time)
ax1.set_xlim(left=0,right=timevec[len(timevec)-1])
ax1.set_ylabel("Amplitud")
ax1.grid(b=True,which='major')


ax2.specgram(time,Fs=fs,NFFT=nfft)
ax2.set_ylabel("Frecuencias")
ax2.set_xlabel("tiempo")
ax2.set_ylim(0,20e3)
ax2.grid(b=True,which='major')
if save:
    plt.savefig('Spectrogram.png')
else:
    plt.show()
