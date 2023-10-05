import networkx as nx
import matplotlib.pyplot as plt
from collections import defaultdict

class Graph:
    def __init__ (self):
        self.graph = defaultdict(list)

    def addEdge(self, u, v, weight):
        self.graph[u].append((v,int(weight)))
        #self.graph[v].append((u,weight))
    '''
    def printGraph(self):
        for v in self.graph:
            print(f"Vertex {v}:")
            for neighbour, weight in self.graph[v]:
                print(f" -> {neighbour} ({weight})")
            print()
        pair = self.graph[v][0][1]
        #print(pair)
    '''

    def BFSToDest(self, s, dest):
        
        queue = []
        queue.append(s)
        visited = set() 
        visited.add(s) 
        cost = 0

        while queue: 
            s = queue.pop(0)
            print (s,end="")  
            if s == dest:
                #print(f"\nCost: {cost}")
                break
            else:
                print(" -> ", end="")

            for i,j in self.graph[s]:
                if i not in visited:
                    queue.append(i)
                    visited.add(i)
                    cost += j

class Graf:
    def __init__ (self):
        self.graph = defaultdict(list)

    def addEdge(self, u, v, weight):
        self.graph[u].append(v)
        #self.graph[v].append((u,weight))

g = Graph()
g.addEdge("Ponorogo", "Madiun", 29)
g.addEdge("Ponorogo", "Magetan", 34)
g.addEdge("Magetan", "Ponorogo", 34)
g.addEdge("Magetan", "Madiun", 22)
g.addEdge("Magetan", "Ngawi", 32)
g.addEdge("Madiun", "Magetan", 22)
g.addEdge("Madiun", "Ponorogo", 29)
g.addEdge("Madiun", "Ngawi", 30)
g.addEdge("Madiun", "Nganjuk", 48)
g.addEdge("Ngawi", "Magetan", 32)
g.addEdge("Ngawi", "Madiun", 30)
g.addEdge("Ngawi", "Bojonegoro", 44)
g.addEdge("Bojonegoro", "Ngawi", 44)
g.addEdge("Bojonegoro", "Nganjuk", 33)
g.addEdge("Bojonegoro", "Lamongan", 42)
g.addEdge("Bojonegoro", "Jombang", 70)
g.addEdge("Nganjuk", "Madiun", 48)
g.addEdge("Nganjuk", "Bojonegoro", 33)
g.addEdge("Nganjuk", "Jombang", 40)
g.addEdge("Jombang", "Nganjuk", 40)
g.addEdge("Jombang", "Bojonegoro", 70)
g.addEdge("Jombang", "Surabaya", 72)
g.addEdge("Lamongan", "Bojonegoro", 42)
g.addEdge("Lamongan", "Gresik", 14)
g.addEdge("Gresik", "Lamongan", 14)
g.addEdge("Gresik", "Surabaya", 12)
g.addEdge("Surabaya", "Gresik", 12)
g.addEdge("Surabaya", "Jombang", 72)
g.addEdge("Surabaya", "Bangkalan", 44)
g.addEdge("Surabaya", "Sidoarjo", 25)
g.addEdge("Bangkalan", "Surabaya", 44)
g.addEdge("Bangkalan", "Sampang", 52)
g.addEdge("Sidoarjo", "Surabaya", 25)
g.addEdge("Sidoarjo", "Probolinggo", 78)
g.addEdge("Sampang", "Bangkalan", 52)
g.addEdge("Sampang", "Pamekasan", 31)
g.addEdge("Probolinggo", "Sidoarjo", 78)
g.addEdge("Probolinggo", "Situbondo", 99)
g.addEdge("Pamekasan", "Sampang", 31)
g.addEdge("Pamekasan", "Sumenep", 52)
g.addEdge("Situbondo", "Probolinggo", 99)
g.addEdge("Sumenep", "Pamekasan", 54)


'''
gr = nx.DiGraph()
gr.add_weighted_edges_from([("Ponorogo", "Madiun", 29), ("Ponorogo", "Magetan", 34)])
#gr.add_edge("Ponorogo", "Madiun")
#gr.add_edge("Ponorogo", "Magetan")
#gr.add_edge("Magetan", "Ponorogo")
#gr.add_edge("Magetan", "Madiun")
#gr.add_edge("Magetan", "Ngawi")
#gr.add_edge("Madiun", "Magetan")
#gr.add_edge("Madiun", "Ponorogo")
#gr.add_edge("Madiun", "Ngawi")

nx.draw(gr, with_labels=True)
plt.show()
'''
#print ("Following is Breadth First Traversal (starting from vertex 2)")
#print(g.graph, min(g.graph))
g.BFSToDest("Ponorogo", "Ngawi")
#g.printGraph()