import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class BoggleShit {
    private static final String[] DICTIONARY = {"SET", "UNSET", "SETTER","ATERUXSETSTN","X","ARTS","FAKE"};

    private final HashSet<String> found = new HashSet<>();
    private int rows, cols;
    private boolean[][] visits;
    private char[][] matrix = {{'X','S','E','T'},{'U','N','T','S'},{'R','E','T','A'},{'P','Q','R','S'}};
    private TrieNode root = new TrieNode();

    public static void main(String args[]) {
        BoggleShit bg = new BoggleShit();
        for (String str : DICTIONARY) {
            bg.insertWord(str);
        }

        bg.mainIterationLogic();
        System.out.println(bg.found);
    }

    private void mainIterationLogic() {
        if (matrix == null || root == null) {
            return;
        }
        rows = matrix.length;
        if (rows == 0) {
            return;
        }

        cols = matrix[0].length;

        visits = new boolean[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                char c = matrix[i][j];
                if (root.children.containsKey(c)) {
                    // Words begin with this alphabet
                    recursiveWordSearch(root.children.get(c), "" + c, i, j);
                }
            }
        }
    }

    private void recursiveWordSearch(TrieNode tNode, String str, int i, int j) {
        if (tNode.wordEnd) {
            found.add(str);
        }

        visits[i][j] = true;
        for (Map.Entry<Character, TrieNode> entry : tNode.children.entrySet()) {
            Character letter = entry.getKey();
            lookHereAndThere(entry.getValue(), str, letter, i, j-1);
            lookHereAndThere(entry.getValue(), str, letter, i-1, j-1);
            lookHereAndThere(entry.getValue(), str, letter, i-1, j);
            lookHereAndThere(entry.getValue(), str, letter, i-1, j+1);
            lookHereAndThere(entry.getValue(), str, letter, i, j+1);
            lookHereAndThere(entry.getValue(), str, letter, i+1, j+1);
            lookHereAndThere(entry.getValue(), str, letter, i+1, j);
            lookHereAndThere(entry.getValue(), str, letter, i+1, j-1);
        }
        visits[i][j] = false;
    }

    private void lookHereAndThere(TrieNode tNode, String str, char charToLookFor, int x, int y) {
        if (shouldAccessIndex(x, y) && matrix[x][y] == charToLookFor) {
            recursiveWordSearch(tNode, str + charToLookFor, x, y);
        }
    }

    private boolean shouldAccessIndex(int x, int y) {
        return (x >= 0 && x < rows && y >= 0 && y < cols && !visits[x][y]);
    }

    class TrieNode {
        HashMap<Character, TrieNode> children = new HashMap<>();
        boolean wordEnd = false;
    }

    private void insertWord(String word) {
        if (root == null || word.length() == 0) {
            return;
        }

        TrieNode tNode = root;
        for (int i = 0; i< word.length(); i++) {
            char c = word.charAt(i);
            tNode.children.computeIfAbsent(c, ch -> new TrieNode());
            tNode = tNode.children.get(c);
        }
        tNode.wordEnd = true;
    }
}
