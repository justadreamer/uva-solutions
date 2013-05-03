import java.util.*;

public class Main {
	private class Sign {
		public String name;
		public GregorianCalendar start;
		public GregorianCalendar end;

		public Sign(String name, int start_month, int start_day, int end_month, int end_day) {
			this.name = name;
			start = new GregorianCalendar(1970,start_month-1,start_day);
			end = new GregorianCalendar(1970,end_month-1,end_day);
		}

		public boolean isDateWithinSign(GregorianCalendar d) {
			int year = d.get(Calendar.YEAR);
			start.set(Calendar.YEAR,year);
			end.set(Calendar.YEAR,year);
			return start.compareTo(d)<=0 && d.compareTo(end)<=0;
		}
	}

	private Sign [] signs = {
		new Sign("Aquarius",	1, 21, 2, 19),
		new Sign("Pisces",		2, 20, 3, 20),
		new Sign("Aries",		3, 21, 4, 20),
		new Sign("Taurus",		4, 21, 5, 21),
		new Sign("Gemini",	 	5, 22, 6, 21),
		new Sign("Cancer",	 	6, 22, 7, 22),
		new Sign("Leo",	 		7, 23, 8, 21),
		new Sign("Virgo", 		8, 22, 9, 23),
		new Sign("Libra",	 	9, 24, 10, 23),
		new Sign("Scorpio",	 	10,24, 11, 22),
		new Sign("Sagittarius",	11,23, 12, 22),
		new Sign("Capricorn",	12,23, 12, 31),
		new Sign("Capricorn",	 1, 1, 1, 20)
	};
	
	public static void main(String[] args) {
		Main mainObj = new Main();
		mainObj.calc();
	}

	public void calc() {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();

		for (int i=0;i<N;i++) {
			String dateString = scanner.next();
			int m = Integer.parseInt(dateString.substring(0,2));
			int d = Integer.parseInt(dateString.substring(2,4));
			int y = Integer.parseInt(dateString.substring(4));
			GregorianCalendar calendar = new GregorianCalendar(y,m-1,d);
			calendar.add(Calendar.DAY_OF_MONTH, 40*7);
			String signName = "";
			for (Sign sign : signs) {
				if (sign.isDateWithinSign(calendar)) {
					signName = sign.name.toLowerCase();
					break;
				}
			}

			System.out.println((i+1)+" "+
				(calendar.get(Calendar.MONTH)+1)+"/"+
				calendar.get(Calendar.DAY_OF_MONTH)
				+"/"+calendar.get(Calendar.YEAR)+
				" "+signName);
		}
	}
}