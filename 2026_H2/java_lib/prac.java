import java.util.*;
import java.io.*;

class Main{
  public static void main(String[] args) throws IOException{
    int[] a = {3, 1, 2};
    System.out.println(a.length);
    Arrays.fill(a, 7);
    Arrays.fill(a, 0, 2, 5);

    int[] b = Arrays.copyOf(a, a.length);
    b[0] = 99;
    int[] part = Arrays.copyOfRange(a, 1, 3);
    System.out.println(Arrays.toString(part));
  }
}