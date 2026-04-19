class CircuitBreaker {

  public void run(Runnable<Void> aa){

  }
}

public void main(){
  CircuitBreaker cb = new CircuitBreaker();

  run(new RuntimeException("error"));
  run(new RuntimeException("error"));
  run(new RuntimeException("error"));
  run(System.out.println("try"));
  run(System.out.println("try"));
  run(System.out.println("success"));
}