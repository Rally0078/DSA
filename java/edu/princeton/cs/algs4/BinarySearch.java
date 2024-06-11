package edu.princeton.cs.algs4;
import java.util.Scanner;

public class BinarySearch {
    public static int BinarySearchInt(int[] a, int val)
    {
        int N = a.length;
        int start = 0, end = N-1, mid;
        while(start <= end) 
        {
            mid = (start+end)/2;
            if(val > a[mid])
                start = mid + 1;
            else if (val <a[mid])
                end = mid - 1;
            else
                return mid;
        }
        return -1;
    }
    public static void main(String[] args)
    {
        In in = new In(args[0]);
        int[] a = in.readAllInts();
        System.out.println("Enter a number to search!");
        Scanner sc = new Scanner(System.in);
        In in2 = new In(sc);
        int val = in2.readInt();
        int pos = BinarySearchInt(a, val);
        if(pos == -1)
            System.out.println("Value not found!!");
        else
            System.out.println("Position of " + val + " is " + pos);
    }
}
