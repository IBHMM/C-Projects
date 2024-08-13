import matplotlib.pyplot as plt
import sys

# Given x and y values for the vector (can be negative)
if len(sys.argv) != 3:
    print("Usage: python your_script.py x y")
    sys.exit(1)

x = float(sys.argv[1])
y = float(sys.argv[2])
# Create a figure and axis
fig, ax = plt.subplots()

# Extend the view to include a larger area
ax.set_xlim(-abs(x) - 2, abs(x) + 2)
ax.set_ylim(-abs(y) - 2, abs(y) + 2)

# Plot the vector as an arrow centered on the screen
ax.quiver(0, 0, x, y, angles='xy', scale_units='xy', scale=1)

# Add labels and title
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_title('Vector Plot')

# Show the plot
plt.grid()
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.show()
