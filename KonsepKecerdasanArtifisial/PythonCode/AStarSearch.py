# Implementasi A* Search Algorithm untuk rute Ponorogo -> Surabaya
# Alief Gilang Permana Putra
# 5025221193

from collections import defaultdict

class Graph:
    def __init__ (self):
        self.graph = defaultdict(list)
        self.hx = defaultdict()

    def addEdge(self, u, v, weight):
        self.graph[u].append((v,int(weight)))
    
    def addHeuristic(self, city, dist):
        self.hx[city] = dist
    
    def aStarSearch(self ,s ,dest):
        queue = []
        queue.append(s)
        visited = set() 
        visited.add(s) 
        y = False
        cost = 0

        while queue: 
            
            s = queue.pop(0)
            print (s,end="")  
            
            if s == dest or y:
                break
            else:
                print(" -> ", end="")
            
            costTmp = ("",100,100000)

            #Evaluasi rute dengan f(x) = (cost+j) + h(x)
            for i,j in self.graph[s]:
                if cost+j+self.hx[i] < cost+costTmp[1]+costTmp[2]:
                    costTmp = (i,j,self.hx[i])
            
            if costTmp[0] in visited:
                y = True
                        
            cost += costTmp[1]
            queue.append(costTmp[0])
            visited.add(costTmp[0])
        
        if dest not in visited:
            print("\nDestination couldn't be reached")
        else:
            print(f"\nCost : {cost}")

#Menambahkan edge List
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

#Menambahkan jarak euclidean
g.addHeuristic("Magetan", 162)
g.addHeuristic("Surabaya", 0)
g.addHeuristic("Ngawi", 130)
g.addHeuristic("Ponorogo", 128)
g.addHeuristic("Madiun", 126)
g.addHeuristic("Bojonegoro", 60)
g.addHeuristic("Nganjuk", 70)
g.addHeuristic("Jombang", 36)
g.addHeuristic("Lamongan", 36)
g.addHeuristic("Gresik", 12)
g.addHeuristic("Sidoarjo", 22)
g.addHeuristic("Probolinggo", 70)
g.addHeuristic("Situbondo", 146)
g.addHeuristic("Bangkalan", 140)
g.addHeuristic("Sampang", 90)
g.addHeuristic("Pamekasan", 104)
g.addHeuristic("Sumenep", 150)

print("A* Search Algorithm from Ponorogo to Surabaya:")
g.aStarSearch("Ponorogo", "Surabaya")