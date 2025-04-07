import java.util.Scanner;


public class reverse{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number ");
        int num = sc.nextInt(); // 1234

        //1. using algorithm
        //2
        
        StringBuilder sb = new StringBuilder();
        sb.append(num);
        StringBuilder rev = sb.reverse();
        System.out.println(rev);

        //3
        StringBuffer sbb = new StringBuffer(String.valueOf(num));
        StringBuffer rev1 = sbb.reverse();
        System.out.println(rev1); 
    
    }
}