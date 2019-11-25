import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] argv)
	{
		Scanner scanner = new Scanner(System.in);

		while(scanner.hasNext())
		{
			String input = scanner.next();
			String input2 = scanner.next();

			BigInteger a = new BigInteger(input);
			BigInteger b = new BigInteger(input2);

			System.out.println("Add: " + a.add(b));
			System.out.println("Sub: " + a.subtract(b));
			System.out.println("Mul: " + a.multiply(b));
			System.out.println("Div: " + a.divide(b));
		}
	}
}
