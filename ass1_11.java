
public class ass1_11 {
	static class instructor{
		String name;
		int phone;
		public void set(String n,int p)
		{
			name=n;
			phone=p;
		}
		public void view()
		{
			System.out.println("Instructor details: ");
			System.out.println("Name: "+name);
			System.out.println("phone: "+phone);
			System.out.println("");
		
		}
	}
	static class textbook{
		String title,author,publisher;
		public void set(String t,String a,String p)
		{
			title=t;
			author=a;
			publisher=p;
		}
		public void view()
		{
			System.out.println("Text book details: ");
			System.out.println("Title: "+title);
			System.out.println("Author name: "+author);
			System.out.println("Publisher: "+publisher);
			System.out.println("");
		
		}
	}
	static class course{
		String course_name;
		instructor ins;
		textbook book;
		public void set(String c,instructor i,textbook t)
		{
			course_name=c;
			ins=i;
			book=t;
		}
		public void view()
		{
			System.out.println("Course details: ");
			System.out.println("Course name: "+course_name);
			ins.view();
			book.view();
			System.out.println("");
		
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		instructor i=new instructor();
		i.set("Shruti", 893556671);
		i.view();
		textbook t=new textbook();
		t.set("JAVA","ABC","XYZ");
		t.view();
		course c=new course();
		c.set("JAVA Course", i, t);
		c.view();
	}

}
