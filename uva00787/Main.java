import java.io.*;
import java.util.*;
import java.math.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (sc.hasNextInt()) {
      
      final int lowest = -999999;
      ArrayList<BigInteger> A = new ArrayList<BigInteger>();

      int n;
      while ((n=sc.nextInt()) != lowest) {
        A.add(new BigInteger(new Integer(n).toString()));
      }
      BigInteger ans = A.get(0);
      BigInteger high = BigInteger.ONE, low = BigInteger.ONE;
      for (BigInteger a : A) {
        BigInteger tmpHigh = high.multiply(a);
        BigInteger tmpLow = low.multiply(a);
        high = tmpHigh.max(a);
        high = tmpLow.max(high);

        low = tmpLow.min(a);
        low = tmpHigh.min(low);

        ans = high.max(ans);
      }
      System.out.println(ans);
    }
  }
}