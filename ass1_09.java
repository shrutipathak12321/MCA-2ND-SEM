
public class ass1_09 {
	static class BankAcct
	{
		int acn;
		double bal;
		static double rate;
		
		public static double initialize_rate(double r) {
			rate=r;
			return r;
		}
		public static double change_rate(double r) {
			rate=r;
			return r;
		}
		public static void display_rate() {
			System.out.println("The interest rate is: "+rate);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double a=BankAcct.initialize_rate(5.5);
		BankAcct.display_rate();
		BankAcct b1=new BankAcct();
		b1.acn=100;
		b1.bal=10000;
		double i=b1.bal*a/100;
		System.out.println("The interest is: "+i);
		a=BankAcct.change_rate(6.5);
		BankAcct.display_rate();
		i=b1.bal*a/100;
		System.out.println("After changing the interest rate, interest is: "+i);

	}

}
