public class DijkstraExample {  
	static final int totalVertex = 7;

	//Возвращает индекс вершины с минимальным расстоянием до неё среди непосещённых
	int minimumDistance(int distance[], Boolean spSet[]) {
		
		int m = Integer.MAX_VALUE;
		int	m_index = -1;

		for (int vx = 0; vx < totalVertex; vx++) {
			if (spSet[vx] == false && distance[vx] <= m) {
				m = distance[vx];
				m_index = vx;
			}
		}
		return m_index;

	}

	void printSolution(int distance[], int n) {
		System.out.println("The shortest Distance from source 0th node to all other nodes are: ");
		for (int j = 0; j < n; j++)
			System.out.println("To " + j + " the shortest distance is: " + distance[j]);
	}

	void dijkstra(int graph[][], int s) {
		int distance[] = new int[totalVertex];
		Boolean spSet[] = new Boolean[totalVertex];
		
		for (int j = 0; j < totalVertex; j++) {
			distance[j] = Integer.MAX_VALUE;
			spSet[j] = false;
		}
		
		distance[s] = 0;

		for (int cnt = 0; cnt < totalVertex - 1; cnt++) {
			
			int ux = minimumDistance(distance, spSet);
			
			spSet[ux] = true;
			for (int vx = 0; vx < totalVertex; vx++)
				if (!spSet[vx] && graph[ux][vx] != 0 && distance[ux] != Integer.MAX_VALUE
						&& distance[ux] + graph[ux][vx] < distance[vx]) {
					distance[vx] = distance[ux] + graph[ux][vx];
				}
		}
		printSolution(distance, totalVertex);
	}

	public static void main(String argvs[]) { 
		
		int[][] matrix = {
				/*    0  1  2  3  4  5  6
				/*0*/{0, 1, 0, 0, 0, 0, 0},
				/*1*/{1, 0, 1, 0, 0, 1, 0},
				/*2*/{0, 1, 0, 1, 0, 0, 0},
				/*3*/{0, 0, 1, 0, 1, 0, 1},
				/*4*/{0, 0, 0, 1, 0, 1, 0},
				/*5*/{0, 1, 0, 0, 1, 0, 0},
				/*6*/{0, 0, 0, 1, 0, 0, 0}};
		DijkstraExample obj = new DijkstraExample();
		obj.dijkstra(matrix, 0);
	}
}