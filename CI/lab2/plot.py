import matplotlib.pyplot as plt

# Sample data
data = [34, 45, 54, 63, 73, 85, 92, 105, 120, 135, 150]

# Create a box plot
plt.boxplot(data)

# Add labels and a title
plt.title('Box Plot Example')
plt.xlabel('Data')
plt.ylabel('Values')

# Show the plot
plt.show()
