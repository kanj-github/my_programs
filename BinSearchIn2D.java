// Find an element in two dimensional array all rows and columns of an array are sorted in ascending order respectively
//
// Input: A two dimensional sorted array, arrA[][].
// Example: 
//                      1  2  3  4
//                      6  7  8  9
//                      13 14 15 16
//                      17 18 19 20
//                      22 23 24 26
//
//
// Output: Index(i, j) - index of element in 2 dimentions if element exists or null.
// log (R*C)

public class BinSearchIn2D {
	static int getValueAt(int[][] mat, int i, int R, int C) {
		int row = i/C;
		int col = i%C;
		return mat[row][col];
	}

	static int doBinSearch(int[][] mat, int start, int end, int N, int R, int C) {
		if (start == end) {
			return (getValueAt(mat, start, R, C) == N)? start : -1;
		}

		int mid = start + (end - start)/2;
		int midVal = getValueAt(mat, mid, R, C);
		
		if (N == midVal) {
			return mid;
		} else if (N < midVal) {
			return doBinSearch(mat, start, mid-1, N, R, C);
		} else {
			return doBinSearch(mat, mid+1, end, N, R, C);
		}
	}

	static Index findElement(int[][] arrA, int number) {
		// put your solution here
		int R = arrA.length;
		int C = arrA[0].length;

		int idx = doBinSearch(arrA, 0, R*C - 1, number, R, C);
		if (idx == -1) {
			return null;
		} else {
			return new Index(idx/C, idx%C);
		}
	}

	public static void main(String args[]) {
		int[][] mat = new int[5][4];
		mat[0][0] = 1;
		mat[0][1] = 2;
		mat[0][2] = 3;
		mat[0][3] = 4;
		mat[1][0] = 6;
		mat[1][1] = 7;
		mat[1][2] = 8;
		mat[1][3] = 9;
		mat[2][0] = 13;
		mat[2][1] = 14;
		mat[2][2] = 15;
		mat[2][3] = 16;
		mat[3][0] = 17;
		mat[3][1] = 18;
		mat[3][2] = 19;
		mat[3][3] = 20;
		mat[4][0] = 22;
		mat[4][1] = 23;
		mat[4][2] = 24;
		mat[4][3] = 26;
		
		int n = 7;
		if (args.length == 1) {
			n = Integer.parseInt(args[0]);
		}

		Index i = findElement(mat, n);
		if (i != null) {
			System.out.println(""+ i.i + "," + i.j);
		} else {
			System.out.println("Not Found");
		}
	}

	static class Index {
		int i;
		int j;
		
		Index(int i, int j) {
			this.i = i;
			this.j = j;
		}
	}
}
