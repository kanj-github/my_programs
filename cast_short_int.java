class cast_short_int {
	public static void main(String args[]){
		short s=16384;
		int n=0;
		int m=0x0000ffff;
		n=s&0xffff;
		System.out.println(Integer.toHexString(n));
		int i=s;
		//n=i&0x8000000f;
		System.out.println(Integer.toHexString(i));
		n=131072;
		n|=s;//&m;
		System.out.println(Integer.toHexString(n));
		short s2=(short)i;
		n=s2&0xffff;
		System.out.println(Integer.toHexString(n));
	}
}
