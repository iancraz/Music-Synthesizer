import matplotlib.pyplot as plt
import numpy as np

#Recibe parametros en la data del tipo
# Fs,NFFT,Window\n
#datos

f = open("data.ian","r")
name = f.readline()
name = name.strip()
f1 = f.readline()
f2 = f.readline()
time = []
timevec = []
y = f1.split(',')
fs = int(y[0])
nfft = int(y[1])
overlap = int(y[3])
save = int(y[4])
showTime = int(y[5])

if int(y[2]) == 0:
    window = None
elif int(y[2]) == 1:
    window = 'BALCKMAN'
elif int(y[2]) == 2:
    window = 'HAMMING'
elif int(y[2]) == 3:
    window = 'BARTLETT'



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

if showTime:
    fig, (ax1, ax2) = plt.subplots(2, 1)
    ax1.plot(timevec,time,'k')
    ax1.set_xlim(left=0,right=timevec[len(timevec)-1])
    ax1.set_ylabel("Amplitud")
    ax1.minorticks_on()
    ax1.grid(b=True, which='major', color='#666666', linestyle='-')
    ax1.grid(b=True, which='minor', color='#999999', linestyle='-', alpha=0.2)
else:
    fig, ax2 = plt.subplots(1, 1)
#ax1.grid(b=True,which='major')

if window == None:
    ax2.specgram(time,Fs=fs,NFFT=nfft,cmap='Greys',noverlap= overlap)
if window == 'BALCKMAN':
    ax2.specgram(time,Fs=fs,NFFT=nfft,window= np.blackman(nfft),cmap='Greys',noverlap= overlap)
elif window == 'HAMMING':
    ax2.specgram(time,Fs=fs,NFFT=nfft, window= np.hamming(nfft),cmap='Greys',noverlap= overlap)
elif window == 'BARTLETT':
    ax2.specgram(time,Fs=fs,NFFT=nfft, window= np.bartlett(nfft),cmap='Greys',noverlap= overlap)

ax2.set_ylabel("Frecuencias")
ax2.set_xlabel("tiempo")
ax2.set_ylim(0,20e3)
#ax2.grid(b=True,which='major')
##ax2.minorticks_on()
ax2.grid(b=True, which='major', color='#666666', linestyle='-', alpha = 0.5)
##ax2.grid(b=True, which='minor', color='#999999', linestyle='-', alpha=0.2)
if save:
    plt.savefig(name)
else:
    plt.show()
