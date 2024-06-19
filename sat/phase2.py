import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpli
from matplotlib.pyplot import MultipleLocator


plt.rcParams['font.sans-serif'] = 'NSimSun,Times New Roman'
data = np.loadtxt('final2.txt', delimiter=' ')
x = data[:, 0]
y = data[:, 1]
plt.scatter(x,y,color='black',marker='.')
ax=plt.gca()
ax.yaxis.set_major_locator(MultipleLocator(0.002))
plt.xlim(xmax=9.0, xmin=0)
plt.xlabel('Ratio of clauses to variables')
plt.ylabel('Average solution time')
plt.title('Average solution time of random 3-SAT instances with 50 variables')
plt.legend()
plt.savefig('2.png')
