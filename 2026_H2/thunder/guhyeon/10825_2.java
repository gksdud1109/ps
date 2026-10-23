import java.util.*;
import java.io.*;

class Main{

  static class Student{
    String name;
    int kor;
    int eng;
    int math;
    public Student(String n, int k, int e, int m){
      this.name = n;
      this.kor = k;
      this.eng = e;
      this.math = m;
    }
  }

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());

    List<Student> list = new ArrayList<>();

    for(int i=0; i<n; i++){
      StringTokenizer st = new StringTokenizer(br.readLine());
      String name = st.nextToken();
      int kor = Integer.parseInt(st.nextToken());
      int eng = Integer.parseInt(st.nextToken());
      int math = Integer.parseInt(st.nextToken());

      list.add(new Student(name, kor, eng, math));
    }

    list.sort((a,b) -> {
      if(a.kor == b.kor){
        if(a.eng == b.eng){
          if(a.math == b.math){
            return (a.name).compareTo(b.name);
          }
          return Integer.compare(b.math, a.math);
        }
        return Integer.compare(a.eng, b.eng);
      }
      return Integer.compare(b.kor, a.kor);
    });

    StringBuilder sb = new StringBuilder();
    for(Student s : list){
      sb.append(s.name).append('\n');
    }

    System.out.println(sb);
  }
}