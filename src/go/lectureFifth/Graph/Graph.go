package Graph

import (
	"fmt"
  "container/list"
)

type Graph struct {
  Vertices map[int][]int
  AdjacencyList map[int]*list.List
}

func New() *Graph {
	return &Graph{
    Vertices:      make(map[int][]int),
    AdjacencyList: make(map[int]*list.List),
  }
}

func (g *Graph) AddVertex(vertex int) {
  g.Vertices[vertex] = make([]int, 0)
  g.AdjacencyList[vertex] = list.New()
}

func (g *Graph) AddEdge(from, to int) {
  g.Vertices[from] = append(g.Vertices[from], to)
  g.AdjacencyList[from].PushBack(to)
  g.Vertices[to] = append(g.Vertices[to], from)
  g.AdjacencyList[to].PushBack(from)
}

func (g *Graph) DisplayGraph() {
	fmt.Println("Vertices:", g.Vertices)
  fmt.Println("Adjacency List:")
  for vertex, neighbors := range g.AdjacencyList {
    fmt.Printf("%d -> ", vertex)
    for e := neighbors.Front(); e!= nil; e = e.Next() {
      fmt.Print(e.Value.(int), " ")
    }
    fmt.Println()
  }
  fmt.Println()
}

// Поиск в ширину
func (g *Graph) BreadthFirstSearch(startVertex int) {
	visited := make(map[int]bool)
  queue := list.New()
  result := make([]int, 0)

  queue.PushBack(startVertex)
  visited[startVertex] = true

  for queue.Len() > 0 {
    fmt.Println(queue.Front().Value.(int))
    currentVertex := queue.Front().Value.(int)
    queue.Remove(queue.Front())
    result = append(result, currentVertex)

    for _, neighbor := range g.Vertices[currentVertex] {
      if!visited[neighbor] {
        visited[neighbor] = true
        queue.PushBack(neighbor)
      }
    }
  }

  fmt.Println("Breadth-first search:", result)
	fmt.Println("Visited vertices:", visited)
	fmt.Println("Remaining vertices:", len(g.Vertices) - len(visited))
	fmt.Println("Remaining edges:", len(g.AdjacencyList) - len(visited))
}

// Поиск в глубину
func (g *Graph) DepthFirstSearch(startVertex int) {
  visited := make(map[int]bool)
  result := make([]int, 0)
  stack := list.New()
  stack.PushBack(startVertex)
  visited[startVertex] = true

  for stack.Len() > 0 {
    fmt.Println(stack.Back().Value.(int))
    currentVertex := stack.Back().Value.(int)
    stack.Remove(stack.Back())
    result = append(result, currentVertex)

    for i := len(g.Vertices[currentVertex]) - 1; i >= 0; i-- {
      neighbor := g.Vertices[currentVertex][i]
      if!visited[neighbor] {
        visited[neighbor] = true
        stack.PushBack(neighbor)
      }
    }
  }

  fmt.Println("Depth-first search:", result)
  fmt.Println("Visited vertices:", visited)
  fmt.Println("Remaining vertices:", len(g.Vertices) - len(visited))
  fmt.Println("Remaining edges:", len(g.AdjacencyList) - len(visited))
}

