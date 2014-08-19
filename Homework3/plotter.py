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
for x in range(len(data2)):
      strvariables =  strvariables + "{"+str(x)+"}"+data2[x][0]+" "
print "Availible variables:\n" + strvariables
strvar1 = raw_input("Y-Axis variable: ")
strvar2 = raw_input("X-Axis variable: ")
var1 = int(strvar1)
var2 = int(strvar2)
stryvar = data2[var1][0]
strxvar = data2[var2][0]
var1list = convertlist(data2[var1])
var2list = convertlist(data2[var2])

ax1.set_ylabel(stryvar,fontdict=font)
ax1.set_xlabel(strxvar,fontdict=font)
ax1.plot(var2list,var1list,'rD')
#ax1.plot(x,linear_fit,'c')
plt.grid()
plt.show()