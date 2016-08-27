import java.util.ArrayList;

class bomb {
	public void explode () {
		System.out.println("BANG!!");
	}
}

class TestListReference {
	
	static void detonate (ArrayList<bomb> list) {
		for (bomb b : list) b.explode();
	}
	
	public static void main (String args[]) {
		ArrayList<bomb> list = new ArrayList<bomb>();
		bomb b = new bomb();
		list.add(b);
		b = null;
		detonate(list);
	}
}
