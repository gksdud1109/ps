import java.util.*;
import java.io.*;

class Main{

  static void arrayCopy(){
    int[] a = {3,1,2};
    System.out.println(a.length);
    Arrays.fill(a, 7);
    Arrays.fill(a, 0, 2, 5);
    int[] b = Arrays.copyOf(a, a.length);
    b[0] = 99;
    int[] part = Arrays.copyOfRange(a, 1, 3);
    System.out.println(Arrays.toString(part));

    int[][] board = new int[2][3];
    for(int[] row : board) Arrays.fill(row, -1);
    int[][] copied = new int[board.length][];
    for(int i=0; i<board.length; i++){
      copied[i] = board[i].clone();
    }

    copied[0][0] = 10;
    System.out.println(board[0][0]);

    char[] row = "1010".toCharArray();
    int cell = row[0] - '0';
    long product = 1L * 100_000 * 100_000;
    System.out.println(cell + " " + product);
  }

  static void stringNStringBuilder(){
    String s = "hello";
    System.out.println(s.length());
    System.out.println(s.charAt(1));
    System.out.println(s.substring(1, 4)); // ell, 끝 인덱스 제외
    System.out.println(s.indexOf("ll"));
    System.out.println(s.contains("he"));
    System.out.println(s.startsWith("he"));
    System.out.println(s.endsWith("lo"));
    System.out.println(s.equals("hello"));
    
    System.out.println("a".compareTo("b")<0); // true
    System.out.println(s.replace("l", "x"));
    System.out.println("  hi  ".trim());
    System.out.println("".isEmpty());
    System.out.println(Integer.parseInt("25"));
    System.out.println(String.valueOf(25));
    System.out.println(Character.isDigit('2'));

    String[] words = "a.b.c".split("\\.");
    System.out.println(Arrays.toString(words));
    System.out.println(String.join("-", words));

    StringBuilder sb = new StringBuilder("abc");
    sb.append('d');
    sb.insert(1, 'X'); // aXbcd
    sb.setCharAt(0, 'A');
    sb.deleteCharAt(1);
    sb.reverse();
    System.out.println(sb.toString());
    sb.setLength(0);
    System.out.println(sb.length());
  }

  public static void main(String[] args) throws IOException{
    
  }
}