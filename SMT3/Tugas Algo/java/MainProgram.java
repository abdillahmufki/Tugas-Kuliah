package java;

public class MainProgram {
    public static void main(String[] args) {
        tambahnilai tmbhn = new tambahnilai();

        System.out.println("sum from 1 to 10 is " + tmbhn.sum(1, 10));
        System.out.println("sum from 20 to 30 is " + tmbhn.sum(20, 30));
        System.out.println("sum from 40 to 50 is " + tmbhn.sum(40, 50));
    }
}