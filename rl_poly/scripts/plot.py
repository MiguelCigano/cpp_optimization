# import numpy as np
# import matplotlib.pyplot as plt

# data = np.loadtxt("../build/trajectory.csv", delimiter=",")

# x1 = data[:,0]
# x2 = data[:,1]

# plt.figure()
# plt.plot(x1, label="x1 (position)")
# plt.plot(x2, label="x2 (velocity)")
# plt.legend()
# plt.title("RL MRA - using polinomios")
# plt.grid();
# plt.show()

# plt.figure()
# plt.plot(x1, x2)
# plt.xlabel("x1")
# plt.ylabel("x2")
# plt.title("States space")
# plt.grid();
# plt.show()

import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("../build/trajectory.csv", delimiter=",")
x1 = data[:, 0]
x2 = data[:, 1]

fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(7, 8))

# Graphic 1: Dynamic behavior
ax1.plot(x1, label="x1 (position)", color='orange')
ax1.plot(x2, label="x2 (velocity)", color='green')
ax1.set_title("RL Iteration value on MRA")
ax1.set_xlabel("Samples (t)")
ax1.set_ylabel("Amplitude")
ax1.legend()
ax1.grid(True)

# Graphic 2: Portrait Phase
ax2.plot(x1, x2, color='blue')
ax2.set_title("Phase Portrait")
ax2.set_xlabel("x1: position")
ax2.set_ylabel("x2: velocity")
ax2.grid(True)

plt.tight_layout() # Set margin automatic 
plt.show()