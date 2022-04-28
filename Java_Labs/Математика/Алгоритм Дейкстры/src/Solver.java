
public class Solver {
	
	//Дополнительная функция, возвращает максимальный элемент
	//массива
	public static int getMaxValue(int[] array) {
	    int maxValue = array[0];
	    for (int i = 1; i < array.length; i++) {
	        if (array[i] > maxValue) {
	            maxValue = array[i];
	        }
	    }
	    return maxValue;
	}

	//Возвращает индекс вершины с минимальным расстоянием до неё среди непосещённых 
	public static int getVertex(int pathLen[], boolean isVisited[], int totalVertex) {
		int minLen = Integer.MAX_VALUE;
		int	minIndex = -1;
		for (int i = 0; i < totalVertex; i++)
			if (isVisited[i] == false && pathLen[i] <= minLen) {
				minLen = pathLen[i];
				minIndex = i;
			}
		return minIndex;
	}
	
	public static void dijkstra(int[][] matrix, int start) {
		
		int		totalVertex = matrix.length; // Общее количество вершин
		int		pathLen[] 	= new int[totalVertex]; // Массив с минимальными расстояниями 
													// до вершины от вершины "start"
		boolean isVisited[] = new boolean[totalVertex]; // Массив с посещенными вершинами
		
		// Предварительное заполнение массива условно бесконечными числами,
		// проставление меток о не посещении
		for (int i = 0; i < totalVertex; i++) {
			isVisited[i] = false;
			pathLen[i] = Integer.MAX_VALUE;
		}
		
		// Расстояние до начальной точки
		pathLen[start] = 0;
		
		for (int step = 0; step < totalVertex - 1; step++) {
			
			// Получение номера ещё не посещённой вершины
			int vertex = getVertex(pathLen, isVisited, totalVertex);
			isVisited[vertex] = true;
			
			// Обновление длины пути pathLen[i], если есть путь из vertex в i и 
			// если сумма пути до vertex и расстояния между vertex и i меньше пути до i
			for (int i = 0; i < totalVertex; i++) {
				if (!isVisited[i] && matrix[vertex][i] != 0 && pathLen[vertex] != Integer.MAX_VALUE
						&& pathLen[vertex] + matrix[vertex][i] < pathLen[i]) {
					pathLen[i] = pathLen[vertex] + matrix[vertex][i];
				}
			}
		}
		
		// Вывод данных на экран
		System.out.println("Эксцентриситет вершины "+ start + ": " + getMaxValue(pathLen));
	}
	
	public static void main(String[] args) {
		
		int[][] matrix = {
		{0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{1,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	1,	0,	1,	1,	1,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	0,	1,	1,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1,	1,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	1},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0}};

		for (int i = 0; i < matrix.length; i++)
			dijkstra(matrix, i);
	}
	
}
