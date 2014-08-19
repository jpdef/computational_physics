import numpy as np
import matplotlib.pyplot as plt
import sys
import re
import ast
import os
from scipy import stats
fig, ax1 = plt.subplots()
plt.ticklabel_format(style='sci', axis='x', scilimits=(0,0))

font = {'family' : 'serif',
        'color'  : 'black',
        'weight' : 'normal',
        'size'   : 16,
        }


def convertnum(s):
    try:
       return float(s)
    except ValueError:
       return
def convertlist(t):
    v = []
    for x in range(len(t)):
          xf = convertnum(t[x])
          if xf is not None:
             v.append(xf)
    return v 


filename = str(sys.argv[1])
f = open(filename, 'r')
data = []



for line in f:
    linearray = (re.split('\t|\n|',line))
    listF=[]
    for x in range(len(linearray)):
        if  linearray[x] is not '':
            listF.append(linearray[x])
    data.append(listF)  
f.close()

#Refromat data to List of Columns
data2 =[]
for x in range(len(data[0])):
    temp = []
    for y in range(len(data)):
        temp.append(data[y][x])
    data2.append(temp)   

#Ask for user input on variables to be plotted
strvariables = ""
num_of_plots = int(raw_input("How many plots: "))
for x in range(len(data2)):
      strvariables =  strvariables + "{"+str(x)+"}"+data2[x][0]+" "
print "Availible variables:\n" + strvariables
strvary = []
strvarx = []
vary = []
varx = []
for x in range(num_of_plots):
    strvary.append(raw_input("Y-Axis variable: "))
    strvarx.append(raw_input("X-Axis variable: "))
for x in range(num_of_plots):  
      vary.append(int(strvary[x]))
      varx.append(int(strvarx[x]))

stryvar = data2[vary[0]][0]
strxvar = data2[varx[0]][0]
ax1.set_ylabel(stryvar,fontdict=font)
ax1.set_xlabel(strxvar,fontdict=font)
for x in range(num_of_plots):  
    #var1list = convertlist(data2[var1])
    #var2list = convertlist(data2[var2])
    ax1.plot(convertlist(data2[varx[x]]),convertlist(data2[vary[x]]))
    #ax1.plot(var2list,var1list,'rD')
theta = np.linspace(0,2*np.pi,num=1000,endpoint=True)
a = (1.0/1.51)
b = a*np.sqrt(1-pow(.51,2.0))
zero = np.linspace(0,0,num=100,endpoint=True)
origin = np.linspace(1-a,1-a,num=100,endpoint=True)
a_line = np.linspace(1.0,1.0-a,num=100,endpoint=True)
b_line = np.linspace(0,b,num=100,endpoint=True)
r = a*(1-(pow(.51,2.0)))/(1.0-.51*np.cos(theta))
x_orb = r*np.cos(theta)
y_orb =r*np.sin(theta)
ax1.plot(x_orb,y_orb,'--r')
ax1.plot(a_line,zero)
ax1.plot(origin,b_line)
plt.grid()
plt.show()