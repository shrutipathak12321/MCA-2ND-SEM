import java.util.Scanner;

public class ass2_01 {
	int cid;
	String cname;
	double cloan;
	int cphone;
	static double credit;
	static Scanner sc=new Scanner(System.in);

	void set()
	{
		System.out.println("Enter customer id: ");
		cid=sc.nextInt();
		System.out.println("Enter customer name: ");
		cname=sc.next();
		System.out.println("Enter customer phone no: ");
		cphone=sc.nextInt();
		System.out.println("Enter customer current loan amount: ");
		cloan=sc.nextDouble();
	}
	void view()
	{
		System.out.println("Customer Details:");
		System.out.println("Customer id: "+cid);
		System.out.println("Customer name: "+cname);
		System.out.println("Customer phone no: "+cphone);
		System.out.println("Customer current loan amount: "+cloan);
		
	}
	void set_credit()
	{
		System.out.println("Enter the credit limit: ");
		credit=sc.nextDouble();
	}
	void name_change()
	{
		System.out.println("Enter new customer name: ");
		cname=sc.next();		
	}
	void phoneno_change()
	{
		System.out.println("Enter new customer phone no: ");
		cphone=sc.nextInt();
	}
	void ask_loan()
	{
		System.out.println("Enter the loan amont: ");
		double loan=sc.nextDouble();
		if((loan+cloan)>credit)
			System.out.println("Exceed credit limit, loan cannot be sanctioned!!!");
		else
		{
			System.out.println("Loan is sanctioned!!!");
			cloan=cloan+loan;
			System.out.println("Your total loan amount is: "+cloan);
		}
	}	
	void check_credit()
	{
		System.out.println("Your credit value is: "+credit);
		System.out.println("Your current loan amount is: "+cloan);
		if(cloan>=credit)
			System.out.println("Credit limit reached, You can not seek more amount of loan!!!");
		else
			System.out.println("Amount of loan, you can seek: "+(credit-cloan));
	}

	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ass2_01 cust1=new ass2_01();
		cust1.set_credit();
		cust1.set();
		cust1.view();
		System.out.println("Do you want to change the name of the customer(TRUE or FALSE)?");
		boolean ch=sc.nextBoolean();
		if(ch)
			cust1.name_change();
		System.out.println("Do you want to change the phone no of the customer(TRUE or FALSE)?");
		ch=sc.nextBoolean();
		if(ch)
			cust1.phoneno_change();
		cust1.ask_loan();
		cust1.check_credit();
		
		System.out.println("\nFor privilleged customer!");
		privilleged cust2=new privilleged();
		cust2.set_credit();
		cust2.set();
		cust2.view();
		System.out.println("Do you want to change the name of the customer(TRUE or FALSE)?");
		ch=sc.nextBoolean();
		if(ch)
			cust2.name_change();
		System.out.println("Do you want to change the phone no of the customer(TRUE or FALSE)?");
		ch=sc.nextBoolean();
		if(ch)
			cust2.phoneno_change();
		cust2.ask_loan();
		cust2.check_credit();	

	}

}
class privilleged extends ass2_01
{
	static double credit;
	void set_credit()
	{
		System.out.println("Enter the credit limit for privilleged customer: ");
		credit=sc.nextDouble();
	}
	void ask_loan()
	{
		System.out.println("Enter the loan amont: ");
		double loan=sc.nextDouble();
		if((loan+cloan)>credit)
			System.out.println("Exceed credit limit, loan cannot be sanctioned!!!");
		else
		{
			System.out.println("Loan is sanctioned!!!");
			cloan=cloan+loan;
			System.out.println("Your total loan amount is: "+cloan);
		}
	}	
	void check_credit()
	{
		System.out.println("Your credit value is: "+credit);
		System.out.println("Your current loan amount is: "+cloan);
		if(cloan>=credit)
			System.out.println("Credit limit reached, You can not seek more amount of loan!!!");
		else
			System.out.println("Amount of loan, you can seek: "+(credit-cloan));
	}
}
