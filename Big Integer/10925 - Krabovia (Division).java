import java.util.Scanner;
import java.io.*;
import java.math.*;

public class Main {

	private static Scanner sc;

	public static void main(String[] args) {
		sc = new Scanner(System.in);
			int cas=1,n,F;
			while(true){
				 n=sc.nextInt();
				 F=sc.nextInt();
				if(n==0 && F == 0) break;
				BigInteger sum=BigInteger.valueOf(0);

				for(int i=0;i<n;i++){
					BigInteger V=sc.nextBigInteger();
					sum=sum.add(V);
				}
				System.out.println("Bill #"+(cas++)+" costs "+
				sum+": each friend should pay "+sum.divide(BigInteger.valueOf(F))+"\n");

			}

	}
}
