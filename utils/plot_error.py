import matplotlib.pyplot as plt
import numpy as np

#context manager to read from file and save the values into a list
with open('../output/gradient_error.txt','r') as file:
    output = file.readlines()

#clean output using list comprehension
output = [float(val.strip()) for val in output]

#save output into variables for plotting
steps = np.log(output[::3])
forward_error = np.log(output[1::3])
central_error = np.log(output[2::3])

#find slope of lines
forward_slope, f_intercept = np.polyfit(steps,forward_error,1)
central_slope, c_intercept = np.polyfit(steps,central_error,1)

print(forward_slope, central_slope)

#plot two types of error
plt.plot(steps,forward_error)
plt.plot(steps,central_error)
plt.xlabel("log of stepsize")
plt.ylabel("log of truncation error")
plt.legend(["forward error","central error"])

plt.annotate('slope: -0.007099',
             xy=(-6,-1.1))

plt.annotate('slope: 0.000278',
             xy=(-4,-1.087))

#plt.show()

plt.savefig('error_comparison.png')


#find way to correctly save figure
#find way to lavel slope

