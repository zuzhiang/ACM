import java.io.*;  
import java.util.*;  
import java.text.*;  
import java.math.*;  
public class Main  
{  
    public static void main(String []args)  
    {  
        Scanner cin = new Scanner(new BufferedInputStream(System.in));  
        while(cin.hasNext())  
        {  
            BigInteger a=cin.nextBigInteger();  
			BigInteger b=cin.nextBigInteger();  
			BigInteger c1=a.add(b);   //�����ӷ�  
			               System.out.println("�ӵĽ��Ϊ "+c1);  
			BigInteger c2=a.subtract(b); //��������  
			               System.out.println("���Ľ��Ϊ "+c2);  
			BigInteger c3=a.multiply(b); //�����˷�  
			               System.out.println("�˵Ľ��Ϊ "+c3);  
			BigInteger c4=a.divide(b); //��������  
			               System.out.println("���Ľ��Ϊ "+c4);  
			//BigInteger c5=a.mod(b); //����ģ  
			                BigInteger c5=a.remainder(b);  
			                System.out.println("ģ�Ľ��Ϊ "+c5);  
			BigInteger c6=a.max(b);//ȡ���  
			                System.out.println("���Ϊ "+c6);  
			BigInteger c7=a.min(b); //ȡ��С  
			                System.out.println("��СΪ "+c7);  
			if(a.equals(b)) //�ж��Ƿ����  
			                System.out.println("���");  
			                else System.out.println("�����");  
			BigInteger c8=a.gcd(b); //�����Լ��  
			                System.out.println("���Լ��Ϊ "+c8);  
        }  
    }  
}  