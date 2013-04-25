import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		while (true) {
			int N = scanner.nextInt();
			int d = scanner.nextInt();
			int m = scanner.nextInt();
			int y = scanner.nextInt();
			if (N==0 && d==0 && m==0 && y==0) {
				break;
			}
			
			GregorianCalendar calendar = new GregorianCalendar(y, m-1, d);
			calendar.add(GregorianCalendar.DAY_OF_MONTH,N);
			System.out.println(calendar.get(GregorianCalendar.DAY_OF_MONTH)+" "
				+(calendar.get(GregorianCalendar.MONTH)+1)+" "+calendar.get(GregorianCalendar.YEAR));
		}
	}
}