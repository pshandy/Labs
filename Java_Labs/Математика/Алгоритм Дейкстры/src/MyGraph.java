import java.util.ArrayList;
import java.util.List;

public class MyGraph {
	
	int v; // Количество вершин
	ArrayList<Integer>[] adjList; // Матрица смежности
	
	public MyGraph(int v) {
		this.v = v;
		adjList = new ArrayList[v];
		for (int i = 0; i < v; i++)
			adjList[i] = new ArrayList<Integer>();
	}
	
	// Добавление ребра в матрицу
	void addEdge(int from, int to) { 
		adjList[from].add(to);
	}
	
    public void printAllPaths(int s, int d)
    {
        boolean[] isVisited = new boolean[v];
        ArrayList<Integer> pathList = new ArrayList<>();
 
        pathList.add(s);
        printAllPathsUtil(s, d, isVisited, pathList);
    }
 
    private void printAllPathsUtil(Integer u, Integer d,
                                   boolean[] isVisited,
                                   List<Integer> localPathList)
    {
 
        if (u.equals(d)) {
            System.out.println(localPathList);
            return;
        }
 
        isVisited[u] = true;
 
        for (Integer i : adjList[u]) {
            if (!isVisited[i]) {
                localPathList.add(i);
                printAllPathsUtil(i, d, isVisited, localPathList);
                
                localPathList.remove(i);
            }
        }
 
        isVisited[u] = false;
    }

	public static void main(String[] args) {
		
		MyGraph g = new MyGraph(4);
		
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(0, 3);
        g.addEdge(2, 0);
        g.addEdge(2, 1);
        g.addEdge(1, 3);
        
        g.printAllPaths(2, 3);
        
	}
	
}
