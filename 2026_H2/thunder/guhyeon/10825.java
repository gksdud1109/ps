import java.io.*;
import java.util.*;

class Main(){

  static class Student {
    String name;
    int kor, eng, math;

    Student(String name, int kor, int eng, int math){
      this.name = name;
      this.kor = kor;
      this.eng = eng;
      this.math = math;
    }
  }
  public static void main(String[] args){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    Student[] stu = new Student[n];

    for(int i=0; i<n; i++){
      StringTokenizer st = new StringTokenizer(br.readLine());

      String name = st.nextToken();
      int kor = Integer.parseInt(st.nextToken());
      int eng = Integer.parseInt(st.nextToken());
      int math = Integer.parseInt(st.nextToken());

      stu[i] = new Student(name, kor, eng, math);
    }

    Arrays.sort(stu, (a,b) -> {
      if(a.kor != b.kor){
        return Integer.compare(b.kor, a.kor);
      }
      if(a.eng != b.eng){
        return Integer.compare(a.eng, b.eng);
      }
      if(a.math != b.math){
        return Integer.compare(b.math, a.math);
      }

      return a.name.compareTo(b.name);
    });

    StringBuilder sb = new StringBuilder();

    for(Student s : stu){
      sb.append(s.name).append('\n');
    }

    System.out.print(sb);
  }
}