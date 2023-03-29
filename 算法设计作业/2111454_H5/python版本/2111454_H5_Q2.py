from typing import List
from queue import PriorityQueue

class Edge:
    def __init__(self, weight: int, dst: int) -> None:
        self.weight = weight
        self.dst = dst
    
class Graph:
    def __init__(self, vertex_cnt: int) -> None:
        self.vertex_cnt = vertex_cnt + 1
        self.graph: List[List[Edge]] = [[] for _ in range(self.vertex_cnt)]
        
    def add_edge(self, src, dst, weight) -> None:
        self.graph[src].append(Edge(weight, dst))
        
    def dijkstra(self, src) -> List[int]:
        dist = [float('inf')] * self.vertex_cnt
        dist[src] = 0
        
        visited = [False] * self.vertex_cnt
        
        pq = PriorityQueue()
        pq.put((0, src))
        
        while not pq.empty():
            curr_dist, curr = pq.get()
            
            # if visited before, the shortest path is determined.
            if visited[curr]:
                continue
            
            visited[curr] = True
            
            for edge in self.graph[curr]:
                new_dist = curr_dist + edge.weight
                if new_dist < dist[edge.dst]:
                    dist[edge.dst] = new_dist
                    pq.put((new_dist, edge.dst))
                    
        return dist
    
def main():
    n, e, s = map(int, input().strip().split())
    
    graph = Graph(n)
    
    for _ in range(e):
        src, dst, w = map(int, input().strip().split())
        graph.add_edge(src, dst, w)
        
    result = graph.dijkstra(s)
    
    for i in range(1, n + 1):
        print(result[i], end=' ')
        
if __name__ == '__main__':
    main()