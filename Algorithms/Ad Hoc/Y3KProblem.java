import java.util.GregorianCalendar;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(true){
            int delta = sc.nextInt();
            int day = sc.nextInt();
            int month = sc.nextInt();
            int year = sc.nextInt();

            if (day == 0) break;

            GregorianCalendar cal = new GregorianCalendar(year, --month, day);
            cal.add(GregorianCalendar.DAY_OF_MONTH, delta);

            System.out.print(cal.get(cal.DAY_OF_MONTH) + " ");
            System.out.print((cal.get(cal.MONTH)+1) + " ");
            System.out.println(cal.get(cal.YEAR));
        }
    }
}