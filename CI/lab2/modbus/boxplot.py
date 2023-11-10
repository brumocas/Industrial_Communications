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
            
            
def get_box_plot(pct, x ,y, axes):
    nct = ["10", "30", "50", "70"]
    
    path = "NCT" + nct[0] + "PCT" + pct 
    dataset1 = get_dataset(path)
    
    path = "NCT" + nct[1] + "PCT" + pct 
    dataset2 = get_dataset(path)
    
    path = "NCT" + nct[2] + "PCT" + pct
    dataset3 = get_dataset(path)
    
    path = "NCT" + nct[3] + "PCT" + pct
    dataset4 = get_dataset(path)

    # Create a list of named datasets
    datasets = [dataset1, dataset2, dataset3, dataset4]

    # Create labels for the datasets
    dataset_labels = ["NCT[10]", "NCT[30]", "NCT[50]", "NCT[70]"]

    # Set custom colors for the box plot elements
    boxprops = dict(color='black', linewidth=2)
    whiskerprops = dict(color='black', linewidth=2)
    capprops = dict(color='black', linewidth=2)

    # Create a box plot of the datasets with custom colors
    axes[x, y].boxplot(datasets, labels=dataset_labels, showfliers=False, boxprops=boxprops, whiskerprops=whiskerprops, capprops=capprops)
  
    axes[x , y].set_title(f"PCT[{pct}]")
    
    axes[x , y].grid(True)
    
    # Set y-label for the subplot
    axes[x ,y].set_ylabel("NRT Value (ms)")
        
    # Set x-label for the subplot
    axes[x , y].set_xlabel("NCT Value (ms)")

    return 

if __name__ == "__main__":
    pct = ["11", "33", "55", "77"]
    
    fig, axes = plt.subplots(2, 2, figsize=(15, 10), facecolor = "grey")
    
    get_box_plot(pct[0], 0, 0, axes)
    get_box_plot(pct[1], 0, 1, axes)
    get_box_plot(pct[2], 1, 0, axes)
    get_box_plot(pct[3], 1, 1, axes)
    
    # Automatically adjust the layout to prevent overlapping
    plt.tight_layout()
    
    # Show the subplots
    plt.show()







    
    