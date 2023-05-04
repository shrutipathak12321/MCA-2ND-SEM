import java.util.Scanner;
public class ass1_04 {
	public static void main(String args[]) {
		final double pi=3.14;
		double r,area;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter radius of the circle: ");
		r=sc.nextDouble();
		area=pi*r*r;
		sc.close();
		System.out.println("Area of the circle is: "+area);
		
	}
	
}
