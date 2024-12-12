package main

import (
  "fmt"
	"lectureFifth/Graph"
)

// * 1 Реализуйте обход графа в ширину
// 2 Реализуйте обход графа в глубину
// 3 Реализуйте построение каркаса графа в процессе обхода в ширину
// 4 Реализуйте построение каркаса графа в процессе обхода в глубину
// 5
// Дополнительное задание 1 Реализуйте визуализацию работы этих
// алгоритмов, чтобы граф отображался на экране, а процесс работы
// демонстрировался различными цветами и другими эффектами
// 6
// Дополнительное задание 2 Реализуйте генерацию случайного
// графа, чтобы не вводить матрицу/список смежности вручную
// Требования к реализациям
//  Граф можно представить на свое усмотрение в виде матрицы
// смежности или списка смежности
//  Программа должна позволять изменять вершину, с которой
// начинается обход
//  После обработки очередной вершины программа должна выводить
// текущее состояние стека/очереди

func main() {
	graph := Graph.New()
  
  for {
    fmt.Println("Меню:")
    fmt.Println("1. Добавить вершину")
    fmt.Println("2. Добавить ребро")
    fmt.Println("3. Отобразить граф")
    fmt.Println("4. Поиск в ширину")
    fmt.Println("5. Поиск в глубину")
    fmt.Println("6. Выход")

    var choice int
    fmt.Print("Выберите пункт меню: ")
    fmt.Scanln(&choice)

    switch choice {
    case 1:
            var vertex int
            fmt.Print("Введите номер вершины: ")
            fmt.Scanln(&vertex)
            graph.AddVertex(vertex)
    case 2:
            var from, to int
            fmt.Print("Введите номер вершины 'from': ")
            fmt.Scanln(&from)
            fmt.Print("Введите номер вершины 'to': ")
            fmt.Scanln(&to)
            graph.AddEdge(from, to)
    case 3:
            graph.DisplayGraph()
    case 4:
            var start int
            fmt.Print("Введите номер вершины для поиска в ширину: ")
            fmt.Scanln(&start)
            graph.BreadthFirstSearch(start)
    case 5:
            var start int
            fmt.Print("Введите номер вершины для поиска в глубину: ")
            fmt.Scanln(&start)
            graph.DepthFirstSearch(start)
    case 6:
            return
    default:
            fmt.Println("Неправильный выбор пункта меню")
    }
}
}