import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
plt.rcParams['font.sans-serif'] = 'NSimSun,Times New Roman'
data = np.loadtxt('final1.txt', delimiter=' ')
x = data[:, 0]
y = data[:, 1]
plt.scatter(x,y,color='black',marker='.')
plt.xlim(xmax=9.0, xmin=0)
plt.xlabel('Ratio of clauses to variables')
plt.ylabel('Probability of satisfiability')
plt.title('Probability of satisfiability of random 3-SAT instances with 50 variables')
plt.legend()
plt.savefig('1.png')
