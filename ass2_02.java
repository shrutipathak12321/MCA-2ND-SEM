import java.util.Scanner;

public class ass2_02 {
	String name;
	int pno;
	String street;
	String city;
	int pin;
	String state;
	int phone;
	String email;
	
	Scanner sc=new Scanner(System.in);
	void set()
	{
		System.out.println("Enter name: ");
		name=sc.next();
		System.out.println("Enter Address: ");
		System.out.println("Enter premises no: ");
		pno=sc.nextInt();
		System.out.println("Enter street name: ");
		street=sc.next();
		System.out.println("Enter city: ");
		city=sc.next();
		System.out.println("Enter pin no: ");
		pin=sc.nextInt();
		System.out.println("Enter state: ");
		state=sc.next();
		System.out.println("Enter phone no: ");
		phone=sc.nextInt();
		System.out.println("Enter email id: ");
		email=sc.next();
	}
	
	void view()
	{
		System.out.println("Name: "+name);
		System.out.println("Address: ");
		System.out.println("Premises no: "+pno);
		System.out.println("Street: "+street);
		System.out.println("City: "+city);
		System.out.println("Pin no: "+pin);
		System.out.println("State: "+state);	
		System.out.println("phone no: "+phone);
		System.out.println("email: "+email);

	}
	void change_address()
	{
		System.out.println("Do you want to change the address?(TRUE or FALSE): ");
		boolean ch=sc.nextBoolean();
		if(ch)
		{
			System.out.println("Do you want to change the premises no?(TRUE or FALSE): ");
			ch=sc.nextBoolean();
			if(ch)
			{
				System.out.println("Enter new premises no: ");
				pno=sc.nextInt();
			}
			System.out.println("Do you want to change the street name?(TRUE or FALSE): ");
			ch=sc.nextBoolean();
			if(ch)
			{
				System.out.println("Enter new street name: ");
				street=sc.next();
			}
			System.out.println("Do you want to change the city name?(TRUE or FALSE): ");
			ch=sc.nextBoolean();
			if(ch)
			{
				System.out.println("Enter new city name: ");
				city=sc.next();
			}
			System.out.println("Do you want to change the pin no?(TRUE or FALSE): ");
			ch=sc.nextBoolean();
			if(ch)
			{
				System.out.println("Enter new pin no: ");
				pin=sc.nextInt();
			}
			System.out.println("Do you want to change the state name?(TRUE or FALSE): ");
			ch=sc.nextBoolean();
			if(ch)
			{
				System.out.println("Enter new state name: ");
				state=sc.next();
			}
			System.out.println("After changing new address is : ");
			System.out.println("Premises no: "+pno);
			System.out.println("Street: "+street);
			System.out.println("City: "+city);
			System.out.println("Pin no: "+pin);
			System.out.println("State: "+state);
		}
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		student s=new student();
		s.set_s();
		s.set();
		s.view_s();
		s.view();
		s.change_address();
		
		faculty f=new faculty();
		f.set_f();
		f.set();
		f.view_f();
		f.view();
		f.change_address();

	}

}
class student extends ass2_02
{
	int roll;
	String course;
	void set_s()
	{
		System.out.println("Enter student roll no: ");
		roll=sc.nextInt();
		System.out.println("Enter course of study: ");
		course=sc.next();
	}
	void view_s()
	{
		System.out.println("\nStudent Detils: ");
		System.out.println("Roll no: "+roll);
		System.out.println("Course of study: "+course);
	}
}
class faculty extends ass2_02
{
	int eid;
	String dept;
	String spec;
	void set_f()
	{
		System.out.println("\nEnter employee id: ");
		eid=sc.nextInt();
		System.out.println("Enter department: ");
		dept=sc.next();
		System.out.println("Enter speciallisation: ");
		spec=sc.next();
	}
	void view_f()
	{
		System.out.println("\nFaculty Employee Detils: ");
		System.out.println("Employee id: "+eid);
		System.out.println("Department: "+dept);
		System.out.println("Speciallisation: "+spec);
	}
}
