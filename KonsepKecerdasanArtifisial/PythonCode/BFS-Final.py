# Implementasi BFS untuk rute Ponorogo -> Surabaya
# Alief Gilang Permana Putra
# 5025221193

from collections import defaultdict

class Graph:
    def __init__ (self):
        self.graph = defaultdict(list)

    def addEdge(self, u, v, weight):
        self.graph[u].append((v,int(weight)))

    def BFSToDest(self, s, dest):
        
        queue = []
        queue.append(s)
        visited = set() 
        visited.add(s) 

        while queue: 
            s = queue.pop(0)
            print (s,end="")  
            if s == dest:
                break
            else:
                print(" -> ", end="")

            for i,j in self.graph[s]:
                if i not in visited:
                    queue.append(i)
                    visited.add(i)
        
        if dest not in visited:
            print("\nDestination couldn't be reached")

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

print("BFS from Ponorogo to Surabaya:")
g.BFSToDest("Ponorogo", "Surabaya")