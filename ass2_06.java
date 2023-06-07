import java.util.Scanner;

public class ass2_06 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a integer: ");
        int a = sc.nextInt();
        Integer integer = Integer.valueOf(a);
        System.out.println("Basic type to object => " + integer);
        int b = integer.intValue();
        System.out.println("Object to basic type => " + b);
        String num = String.valueOf(b);
        System.out.println("Basic type to string => " + num);
        Integer newNum = Integer.parseInt(num);
        System.out.println("String (holding numeric data) to  numeric object => " + newNum);
        String newString = Integer.toString(b);
        System.out.println("Object to string => " + newString);
        sc.close();
    }
}