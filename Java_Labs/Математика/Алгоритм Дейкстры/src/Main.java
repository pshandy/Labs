import java.util.ArrayList;

public class Main {

	public static void solve(int current, int end, 
			boolean isVisited[], ArrayList<Integer> path, int matrix[][], 
			boolean isCustomLen) {
		
		//Если текущая вершина = конечной и путь до неё 4, выход из функции
		if (current == end) {
			if (path.size() == 5 && isCustomLen)
				System.out.println(path);
			return ;
		}
		
		isVisited[current] = true;
		
		//Рекурсивный обход графа, если есть путь в другую непосещенную вершину,
		//происходит повторная обработка вершины
		for (Integer i = 0; i < matrix.length; i++)
			if (matrix[current][i] == 1 && !isVisited[i]) {
				path.add(i);
				solve(i, end, isVisited, path, matrix, isCustomLen);
				path.remove(i);
			}
		
		isVisited[current] = false;
	}
	
	public static void main(String[] args) {
		
		int[][] matrix = {
				/*    0  1  2  3  4  5  6
				/*0*/{0, 1, 0, 0, 0, 0, 0},
				/*1*/{1, 0, 1, 1, 0, 0, 0},
				/*2*/{0, 1, 0, 0, 0, 1, 0},
				/*3*/{0, 1, 0, 0, 1, 1, 0},
				/*4*/{0, 0, 0, 1, 0, 1, 0},
				/*5*/{0, 0, 1, 1, 1, 0, 1},
				/*6*/{0, 0, 0, 0, 0, 1, 0}};
		
		ArrayList<Integer> path = new ArrayList<Integer>(); // Буффер для записи текущего путя
		boolean[] isVisited = new boolean[matrix.length];	// Массив с пометками о пройденных вершинах
		
		int start	= 3;
		int end		= 6;
		
		path.add(start); //Добавление начальной вершины в путь
		System.out.println("Все пути между " + start + " и " + end + " вершинами длиной 4:");
		solve(start, end, isVisited, path, matrix, true);
		
	}
	
}
