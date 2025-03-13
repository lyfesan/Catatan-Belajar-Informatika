class DifferenceOfSquares {
  
  int squareOfSum(int x) {
    int result = 0;
    for(int i=1;i<=x;i++) {
      result+=i;
    }
    return result * result;
  }

  int sumOfSquares(int x) {
    int result = 0;
    for(int i=1;i<=x;i++) {
      result+=i*i;
    }
    return result;
  }

  int differenceOfSquares(int x) {
    return squareOfSum(x) - sumOfSquares(x);
  }
}
