class A
{
	int size;
	int capacity;
	int x[];
	
	A()
	{
		this(10);
	}
	
	A(int capacity)
	{
		this.capacity = capacity;
		x= new int[capacity];
	}

	void add(int v)
	{
		resize();
		x[size++] = v;
	}

	void resize()
	{
		if(size==capacity)
		{
			capacity = 2*capacity;
			int y[] = new int[capacity];
			int i;
			for(i=0;i<size;i++)
			{
				y[i] = x[i];
			}
		x=y;
		}
	}
}

class GrowArray
{
	public static void main(String ar[])
	{
		A a = new A();
System.out.println(a.size);		
System.out.println(a.capacity);
int i;
for(i=0;i<10;i++)
{
	a.add(i);
}
System.out.println(a.size);		
System.out.println(a.capacity);
	a.add(45);
System.out.println(a.size);		
System.out.println(a.capacity);
	
	}
}