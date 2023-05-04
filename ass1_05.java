import java.util.Scanner;
public class ass1_05 {
	public static void main(String args[]) {
		String s1,s2;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter a string: ");
		s1=sc.nextLine();
		s2=s1;
		System.out.println(s1==s2); //true
		System.out.println(s1.equals(s2)); //true
		
		System.out.println("Enter first string: ");
		s1=sc.nextLine();
		System.out.println("Enter second string(same as first): ");
		s2=sc.nextLine();
		System.out.println(s1==s2); //false because it compares the address of the strings
		System.out.println(s1.equals(s2)); //true because it compares the content
		sc.close();

	}

}
