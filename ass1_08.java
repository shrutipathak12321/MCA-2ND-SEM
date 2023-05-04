

public class ass1_08 {
	static class Student{
		int roll;
		String name;
		double score;
		public Student()
		{
			
		}
		public Student(int r)
		{
			roll=r;
		}
		public Student(int r,String n)
		{
			roll=r;
			name=n;
		}
		public Student(int r,String n,double s)
		{
			roll=r;
			name=n;
			score=s;
		}
		public Student(Student st)
		{
			roll=st.roll;
			name=st.name;
			score=st.score;
		}
		public void display(){
			System.out.println("Student details: ");
			System.out.println("Roll: "+roll);
			System.out.println("Name: "+name);
			System.out.println("Score: "+score);
			System.out.println("");

			
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student s= new Student();
		System.out.println("Using constructor with no value: ");
		s.display();
		
		Student s1 = new Student(1);
		System.out.println("Using constructor with roll only: ");
		s1.display();
		
		Student s2 = new Student(2,"A");
		System.out.println("Using constructor with roll and name only: ");
		s2.display();
		
		Student s3 = new Student(3,"B",40.5);
		System.out.println("Using constructor with roll, name and score: ");
		s3.display();
		
		Student s4 = new Student(s3);
		System.out.println("Using copy constructor: ");
		s4.display();
		System.out.println("So,copy constructor works into deep copy ");
	
	}

}
