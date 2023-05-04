import java.util.Scanner;
public class ass1_10 {
	static class Metric{
		double km,mile;
		public double km_to_mile(double km) {
			return km/1.5;
		}
		public double mile_to_km(double m) {
			return m*1.5;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Metric d=new Metric();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter distance in Kilometer: ");
		d.km=sc.nextDouble();
		System.out.println("Distance in Miles: "+d.km_to_mile(d.km));
		System.out.println("Enter distance in mile: ");
		d.mile=sc.nextDouble();
		System.out.println("Distance in kilometer: "+d.mile_to_km(d.mile));
		sc.close();
	}

}
