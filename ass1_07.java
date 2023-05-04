
public class ass1_07 {
	static class Student{
		int roll;
		String name;
		double score;
	
		public void set(int r,String n,double s){
			roll=r;
			name=n;
			score=s;
			
		}
		
		public void display(){
			System.out.println("Student details: ");
			System.out.println("Roll: "+roll);
			System.out.println("Name: "+name);
			System.out.println("Score: "+score);
			System.out.println("");
		}
		
		public void copy(Student s){
			s.roll=roll;
			s.name=name;
			s.score=score;
		}		
	}
	
	public static void main(String args[]) {
		Student s= new Student();
		Student s1 = new Student();
		s.set(21, "Shruti Pathak", 50);
		s.display();
		s.copy(s1);
		System.out.println("After copy: ");
		s1.display();
	}	
}
