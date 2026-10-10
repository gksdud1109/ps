class CircuitBreaker {

  public void run(Runnable aa) {
    try {
      aa.run();
    } catch (Exception e) {
      // handle error
    }
  }

  public static void main(String[] args) {
    CircuitBreaker cb = new CircuitBreaker();

    cb.run(() -> { throw new RuntimeException("error"); });
    cb.run(() -> { throw new RuntimeException("error"); });
    cb.run(() -> { throw new RuntimeException("error"); });
    cb.run(() -> System.out.println("try"));
    cb.run(() -> System.out.println("try"));
    cb.run(() -> System.out.println("success"));
  }
}