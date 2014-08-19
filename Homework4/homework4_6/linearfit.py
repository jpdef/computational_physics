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
def printlatex(data):
    latstr = ""
    for y in range(len(data[0])):
        for x in range(len(data)):
            latstr = latstr + data[x][y] 
	    if(len(data)-1!=x ):
              latstr = latstr+ " & " 
        latstr = latstr + "\\\ \n"
    return latstr
    
filename = str(sys.argv[1])
f = open(filename, 'r')
data = []

#Format data so that all values accepted
#Placed in list of lists by column and row
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
#Fit test
slope, intercept, r_value, p_value, std_err = stats.linregress(convertlist(data2[var2]),convertlist(data2[var1]))

strlinefit = ""
strlinefit = "Slope:" + str(slope) +  "\nIntercept:" + str(intercept)+ "\nP_value " + str(p_value) + "\nR_value: " + str(r_value) + "\nStd_err:"+ str(std_err)
print strlinefit





