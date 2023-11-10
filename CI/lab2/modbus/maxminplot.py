import matplotlib.pyplot as plt
import numpy as np

def get_dataset(path):
    path = path + ".txt"
    
    # Initialize an empty array to store the last column data
    last_column_data = []
    loop = 0
    # Open the text file for reading
    with open(path, 'r') as file:
        for line in file:
            if loop >= 100:
                return last_column_data
        
            # Split the line by commas to separate columns
            columns = line.strip().split( ', ')
            time = columns[-1].strip().split(' ')[0]
            
            # Extract the last column and convert it to the desired data type if needed
            last_column_value = int(time)/(10**3) # time in ms
        
            # Append the last column value to the array
            last_column_data.append(last_column_value)
        
            loop = loop + 1
            
        return last_column_data           

def plot_pct_line(pct):
    nct = ["10", "30", "50", "70"]

    max_values = []  # To store the maximum values
    min_values = []  # To store the minimum values
    
    # Calculate the maximum values and store them in max_values 
    for i in range(len(nct)):
        path = "NCT" + nct[i] + "PCT" + pct
        dataset_max = max(get_dataset(path))
        dataset_min = min(get_dataset(path))
        max_values.append(dataset_max)
        min_values.append(dataset_min)

    # Create labels for the datasets
    dataset_labels = ["NCT[10]", "NCT[30]", "NCT[50]", "NCT[70]"]

    # Plot points for the maximum values and unite them with lines
    axes[0].plot(dataset_labels, max_values, marker='o', linestyle='-', label = f"PCT[{pct}]")
    
    # Plot points for the maximum values and unite them with lines
    axes[1].plot(dataset_labels, min_values, marker='o', linestyle='-', label = f"PCT[{pct}]")

    # Add a legend to label the line
    axes[0].legend()
    
    # Add a legend to label the line
    axes[1].legend()

    # Set y-label for the subplot
    axes[0].set_ylabel("NRT Maximum Value (ms)")
    
    # Set y-label for the subplot
    axes[1].set_ylabel("NRT Minimum Value (ms)")
    
    # Set x-label for the subplot
    axes[0].set_xlabel("NCT Value (ms)")
    
    # Set x-label for the subplot
    axes[1].set_xlabel("NCT Value (ms)")

    return
            
# Create a figure and subplots
fig, axes = plt.subplots(1, 2, figsize=(15, 6), facecolor="grey")

pct = ["11", "33", "55", "77"]

for i in pct:
    plot_pct_line(i)

# Automatically adjust the layout to prevent overlapping
plt.tight_layout()

# Show the subplots
plt.show()









    
    