import random


# Initialize a grid
grid_size = 10
grid = [[0 for x in range(grid_size)] for y in range(grid_size)]

# initialize the grid with random open and blocked cells
for row in range(grid_size):
    for col in range(grid_size):
        if random.random() < 0.35: # set 35% of cells as blocked
            grid[row][col] = 0
        else:
            grid[row][col] = 1

# Choose a random starting cell
start_row = random.randint(0,grid_size - 1)
start_col = random.randint(0,grid_size - 1)

# Choose a random neighbor cell
def get_random_neighbor(row, col):
    neighbors = []
    if row > 0:
        neighbors.append((row - 1, col))
    if row < grid_size - 1:
        neighbors.append((row + 1, col))
    if col > 0:
        neighbors.append((row, col - 1))
    if col < grid_size - 1:
        neighbors.append((row, col + 1))
    if len(neighbors) == 0:
        return None
    return random.choice(neighbors)

# Recursive Backtracking algorithm
def recursive_backtracking(row, col):
    grid[row][col] = 2 # mark cell as visited
    neighbors = get_unvisited_neighbors(row, col)
    while len(neighbors) > 0:
        # Choose a random unvisited neighbor cell
        neighbor_row, neighbor_col = random.choice(neighbors)
        grid[(row + neighbor_row) // 2][(col + neighbor_col) // 2] = 2 # mark cell as visited
        recursive_backtracking(neighbor_row, neighbor_col)
        neighbors = get_unvisited_neighbors(row, col)

# Get unvisited neighbor cells
def get_unvisited_neighbors(row, col):
    neighbors = []
    if row > 1 and grid[row - 2][col] == 1:
        neighbors.append((row - 2, col))
    if row < grid_size - 2 and grid[row + 2][col] == 1:
        neighbors.append((row + 2, col))
    if col > 1 and grid[row][col - 2] == 1:
        neighbors.append((row, col - 2))
    if col < grid_size - 2 and grid[row][col + 2] == 1:
        neighbors.append((row, col + 2))
    return neighbors

recursive_backtracking(start_row, start_col)
# Print the grid
for row in grid:
    print(row)
