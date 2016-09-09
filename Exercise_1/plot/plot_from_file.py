from pylab import*
from scipy.integrate import quad
import numpy as np
import os

#paths
my_path = os.path.abspath(r"C:\Users\Heine\Desktop\Skole\FYS4150_Comp_Fys\FYS4150\Exercise_1\plot")
os.chdir(r"C:\Users\Heine\Desktop\Skole\FYS4150_Comp_Fys\FYS4150\Exercise_1\plot")

file = np.loadtxt("my_file.txt", dtype = 'float', skiprows = 1, usecols = (0,1,2))

print(file)

#Plotting
fig = figure()
grid(True, which = 'both')#, ls= '-')
grid('on')

plot(file[:,0],file[:,1],'r-', label = '$approx. solutin$ ') 
plot(file[:,0],file[:,2],'b-', label = '$exact solution$ ') 

xlabel(r'$x$', size = 20,labelpad= 5 )
ylabel(r'$f(x)$',size = 20, labelpad = 5)
title( r'Plot with 10 iteations' )
legend(loc='smart')
fig.savefig('my_plot.png')
show()
