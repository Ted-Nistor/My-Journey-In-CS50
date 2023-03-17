import networkx as nx
import matplotlib.pyplot as plt

# create the graph
G = nx.Graph()
G.add_weighted_edges_from([(1, 2, 1), (2, 3, 1),(1,3,1),(3, 4, 0.5),(3,6,0.5), (4,6, 1, 2), (2, 4, 0.5)])

# define edge colors based on weight
edge_colors = []
for u, v, d in G.edges(data=True):
    if d['weight'] < 0.5:
        edge_colors.append('red')
    elif d['weight'] == 0.5:
        edge_colors.append('yellow')
    elif d['weight'] == 1:
        edge_colors.append('lightblue')
    elif d['weight'] == 2:
        edge_colors.append('darkgreen')

# visualize the graph
pos = nx.spring_layout(G)
nx.draw_networkx_nodes(G, pos)
nx.draw_networkx_labels(G, pos)
nx.draw_networkx_edges(G, pos, edge_color=edge_colors)
plt.savefig("graph.png")
