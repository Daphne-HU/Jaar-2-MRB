# -*- coding: utf-8 -*-
"""
Created on Thu Apr  1 09:12:08 2021

@author: bart.bozon
"""

import matplotlib.pyplot as plt
import numpy as np

maxarray=64
signaal =np.zeros((maxarray),dtype=float)
t=np.zeros((maxarray),dtype=float)
dt=0.64    # 1 sec


def DFT():
    for i in range (len(t)):
        t[i]=i*dt
    sinus=np.zeros((int(maxarray/2)),dtype=float)
    cosinus=np.zeros((int(maxarray/2)),dtype=float)
    ifft=np.zeros((maxarray),dtype=float)
    mag=np.zeros((int(maxarray/2)),dtype=float)
    f=np.zeros((int(maxarray/2)),dtype=float)
    for i in range(len(f)) :
        f[i]=i*1/(dt*maxarray)
    for k in range (int(maxarray/2)): 
        for i in range (len(t)):
            sinus[k]+=signaal[i]*np.sin(2*k*i*np.pi/len(t))/(maxarray/2)
            cosinus[k]+=signaal[i]*np.cos(2*np.pi*k*i/len(t))/(maxarray/2)
    cosinus[0]=cosinus[0]*0.5        
    for k in range (int(maxarray/2)): 
        mag[k]=(sinus[k]**2+cosinus[k]**2)**0.5
    fig,ax= plt.subplots()
    plt.scatter(t,signaal,s=4)
    plt.title ('Signaal')
    plt.xlabel('Tijd (s)')
    plt.ylabel('Amplitude ()')
    plt.show()   
    plt.scatter(f,mag,s=4)
    plt.title ('Fourier transformatie')
    plt.xlabel('Frequentie (Hz)')
    plt.ylabel('Amplitude ()')
    plt.show()    
    for k in range (int(maxarray/2)): 
        ifft =np.zeros((maxarray),dtype=float)
        for i in range (len(t)):
            ifft[i]+=sinus[k]*np.sin(2*k*i*np.pi/len(t))
            ifft[i]+=cosinus[k]*np.cos(2*np.pi*k*i/len(t))
        plt.plot(t,ifft)
    plt.title ('Inverse fourier transformatie')
    plt.xlabel('Tijd (s)')
    plt.ylabel('Amplitude ()')
    plt.show()   

# ===== vraag 1 ======
# for i in range (len(t)):
#     signaal[i]=np.sin(2*np.pi*i/64)
# DFT()        

# for i in range (len(t)):
#     signaal[i]=np.sin(2*np.pi*i/64) + np.sin(3*2*np.pi*i/64)
# DFT()        

# for i in range (len(t)):
#     signaal[i]=np.sin(2*np.pi*i/64) + 1/3*np.sin(3*2*np.pi*i/64)+ 1/5*np.sin(5*2*np.pi*i/64)
# DFT()        

# for i in range (len(t)):
#     if i % 64 <32 : 
#         signaal[i]=1
#     else:
#         signaal[i]=-1
# DFT()    

# ===== vraag 2 ======
# for i in range (len(t)):
#     signaal[i]=np.cos(2*np.pi*i/64)
# DFT() 


# for i in range (len(t)):
#     signaal[i]=np.cos(2*np.pi*i/66)
# DFT()     

# ===== vraag 3 ======
# for i in range (len(t)):
#     signaal[i]=np.sin(1*np.pi*i/64)**10*(np.sin(5*2*np.pi*i/64))
# DFT()


# for i in range (len(t)):
#     signaal[i]=(np.sin(5*2*np.pi*i/64))
# DFT()

# ===== vraag 4 ======
# for i in range (len(t)):
#     if i < 32:
#         signaal[i]= ((2/32)*i)-1
#     else:
#         signaal[i]= 3-((2/32)*i)
# DFT()

# ===== vraag 5 ======
# for i in range (len(t)):
#     if i >= 30 and i <= 34:
#         signaal[i] = 1
#     else:
#         signaal[i]= -1
# DFT()


# ===== Opdracht 2, vraag 1 ======
def moving_average( signal ):
    new_signal = np.zeros(len(signal+3),dtype=float)
    for i in range(len(signal)):
        new_signal[i] = signal[i]
    average = np.zeros(64,dtype=float)
    for i in range(len(signal)):
            average[i] = (signal[i] + signal[i-1] + signal[1-2] + signal[i-3]) / 4
    return average


# singaal = np.array([0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0])
# print(signaal)
# singaal = moving_average(singaal)
# print(singaal)


# ===== Opdacht 2, vraag 2 =====
# for i in range (len(t)):
#     signaal[i]=np.sin(2*np.pi*i/64)
# DFT()  
# signaal = moving_average(signaal)
# DFT()
# # een sinus doet niet zo veel

# for i in range (len(t)):
#     signaal[i]=np.sin(2*np.pi*i/64) + 1/3*np.sin(3*2*np.pi*i/64)+ 1/5*np.sin(5*2*np.pi*i/64)
# DFT()  
# signaal = moving_average(signaal)
# DFT()

# #bij de inverse fouire transformatie gaat een lijn consistent naar onder

# ===== Opdacht 2, vraag 3 =====
def FIR( signal ):
    new_signal = np.zeros(len(signal+1),dtype=float)
    for i in range(len(signal)):
        new_signal[i] = signal[i]
    FIR_signal = np.zeros(64,dtype=float)
    for i in range(len(signal)):
            FIR_signal[i] = (signal[i] - signal[i-1]) / 2
    return FIR_signal

# singaal = np.array([0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0])
# print(signaal)
# singaal = FIR(singaal)
# print(singaal)

# ===== Opdacht 2, vraag 4 =====
# for i in range (len(t)):
#     signaal[i]=np.sin(2*np.pi*i/64)
# DFT()  
# signaal = FIR(signaal)
# DFT()

# for i in range (len(t)):
#     signaal[i]=np.sin(2*np.pi*i/64) + 1/3*np.sin(3*2*np.pi*i/64)+ 1/5*np.sin(5*2*np.pi*i/64)
# DFT()  
# signaal = FIR(signaal)
# DFT()

# Het sinaal ziet er echt heel anders uit, de ampitude van de 3 frequenties zijn nu allemaal erg hoog ipv eentje hoog