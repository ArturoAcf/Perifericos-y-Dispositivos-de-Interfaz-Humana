# Realizado por: Arturo Alonso Carbonero
# Grupo: 4ºA - Curso: 21-22

# Práctica 5 - Sonido

# --------------------------------------------------------------- #

import numpy as np
from scipy.io import wavfile
import matplotlib.pyplot as plt
import wave
import scipy.signal as signal
import scipy.io.wavfile as wf

# --------------------------------------------------------------- #

# Ejercicio 1


# Cargar archivos .wav

Fs, sen=wavfile.read('./Arturo.wav') # Ruta del archivo con la señal
sen=sen.astype(float)
t=np.arange(0, len(sen)/Fs, 1/Fs)

Fs2, signal2=wavfile.read('./Alonso.wav') # Ruta del archivo con la señal
signal2=signal2.astype(float)
t2=np.arange(0, len(signal2)/Fs2, 1/Fs2)

# --------------------------------------------------------------- #

# Ejercicio 2


# Mostrar gráficas

plt.plot(t, sen, color='lightblue', label='Arturo')
plt.title('Nombre - Arturo')
plt.xlabel('Tiempo (s)')
plt.ylabel('Amplitud (Hz)')
plt.grid()

plt.figure()
plt.plot(t2, signal2, color='lightblue', label='Alonso')
plt.title('Apellido - Alonso')
plt.xlabel('Tiempo (s)')
plt.ylabel('Amplitud (Hz)')
plt.grid()

# --------------------------------------------------------------- #

# Ejercicio 3


# Obtener información de las cabeceras

signalAr=wave.open('./Arturo.wav' ,'r')

print("Arturo")
print("\n")
print("Número de canales -> ", signalAr.getnchannels())
print("Ancho -> ", signalAr.getsampwidth())
print("Frame rate -> ", signalAr.getframerate())
print("Número de frames -> ", signalAr.getnframes())
print("Parámetros -> ", signalAr.getparams())

print("\n")
print("------------------------------------------------------")
print("\n")

signalAl=wave.open('./Alonso.wav' ,'r')

print("Alonso")
print("\n")
print("Número de canales -> ", signalAr.getnchannels())
print("Ancho -> ", signalAr.getsampwidth())
print("Frame rate -> ", signalAr.getframerate())
print("Número de frames -> ", signalAr.getnframes())
print("Parámetros -> ", signalAr.getparams())

# --------------------------------------------------------------- #

# Ejercicio 4


# Unir ambos sonidos

infiles = ["Arturo.wav", "Alonso.wav"]
outfile = "ArturoAlonso.wav"

data=[]
for infile in infiles:
    w = wave.open(infile, 'rb')
    data.append( [w.getparams(), w.readframes(w.getnframes())] )
    w.close()

output = wave.open(outfile, 'wb')
output.setparams(data[0][0])
for i in range(len(data)):
    output.writeframes(data[i][1])
output.close()

# --------------------------------------------------------------- #

# Ejercicio 5


# Cargar archivo .wav

Fs3, signal3=wavfile.read('./ArturoAlonso.wav') # Ruta del archivo con la señal
signal3=signal3.astype(float)
t3=np.arange(0, len(signal3)/Fs3, 1/Fs3)


# Diubujar forma de onda

plt.figure()
plt.plot(t3, signal3, color='lightblue', label='Arturo')
plt.title('Nombre + Apellido')
plt.xlabel('Tiempo (s)')
plt.ylabel('Amplitud (Hz)')
plt.grid()

# --------------------------------------------------------------- #

# Ejercicio 6


umbral1=1
umbral2=10000
umbral3=20000

def butter_bandpass(umbral1, umbral2, fs, order=5):
    nyq=0.5*fs
    low=umbral1/nyq
    high=umbral2/nyq
    b, a=signal.butter(order, [low, high], btype='band')
    return b, a

def butter_bandpass_filter(data, umbral1, umbral2, fs, order=5):
    b, a=butter_bandpass(umbral1, umbral2, fs, order=order)
    y=signal.lfilter(b, a, data)
    return y

def bandpass_filter(buffer):
    return butter_bandpass_filter(buffer, umbral1, umbral2, 10000, order=6)

signal4=butter_bandpass_filter(signal3, umbral1, umbral2, Fs3)
signal5=butter_bandpass_filter(signal3, umbral2, umbral3, Fs3)
signal6=signal4+signal5


# Mostrar gráfica

plt.figure()
plt.plot(t3, signal6, color='lightblue', label='Arturo')
plt.title('Nombre + Apellido')
plt.xlabel('Tiempo (s)')
plt.ylabel('Amplitud (Hz)')
plt.grid()

# --------------------------------------------------------------- #

# Ejercicio 7


# Generar archivo de salida

nombreArchivo='mezcla.wav'
wf.write(nombreArchivo, Fs3, signal6.astype('int16'))

# --------------------------------------------------------------- #

# Ejercicio 8


# Delay e inversión

Fs4, signal7=wavfile.read('./mezcla.wav') # Ruta del archivo con la señal
# NOTA -> Probar con el fichero 'muneca.wav' si el actual no funciona
signal7=signal7.astype(float)
t4=np.arange(0, len(signal7)/Fs4, 1/Fs4)

signalDelay=np.zeros(len(signal7)+1800)

for i in range(0, len(signalDelay)):
    if i<1800:
        signalDelay[i]=signal7[i]
    elif i<len(signal7):
        signalDelay[i]=0.9*(signal7[i]+0.8*signalDelay[i-1800])
    else:
        signalDelay[i]=0.9*0.8*signalDelay[i-1800]

signalDelayCorte=signalDelay[1800:]

signalInvert=np.flip(signalDelayCorte)

# Mostrar gráfica

plt.figure()
plt.plot(t4, signalInvert, color='lightblue', label='Arturo')
plt.title('Nombre + Apellido')
plt.xlabel('Tiempo (s)')
plt.ylabel('Amplitud (Hz)')
plt.grid()

# Generar archivo de salida

nombreArchivo='alreves.wav'
wf.write(nombreArchivo, Fs4, signalInvert.astype('int16'))
