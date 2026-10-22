import java.io.*;

class Main{
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String t = br.readLine();
    String p = br.readLine();

    int cnt = 0;
    int f = t.indexOf(p);

    while(f != -1){
      cnt++;
      f = t.indexOf(p, f+p.length());
    }

    System.out.println(cnt);
  }
}