class HelloWorld {
private native String print(String abc);
public static void main(String[] args) {
String mystring = new HelloWorld().print("Enter a string:\n");
System.out.println("You Typed :\""+mystring+"\"");
}
static {
System.loadLibrary("HelloWorld");
}
}