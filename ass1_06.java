import java.util.Scanner;
public class ass1_06 {
	static void show(int n)
	{
		System.out.println(n);
	}
	static void show(double n)
	{
		System.out.println(n);
	}
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter a short value: ");
		short a=sc.nextShort();
		System.out.println("Enter a double value: ");
		double b=sc.nextDouble();
		show(a); 
		show(b);
		sc.close();
	}

}
