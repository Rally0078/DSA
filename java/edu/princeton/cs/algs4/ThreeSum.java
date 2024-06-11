package edu.princeton.cs.algs4;
import java.util.Arrays;
public class ThreeSum{
    public static int countBruteForce(int[] a)
    {
        int N = a.length;
        int count = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = i+1; j < N; j++)
            {
                for(int k = j+1; k < N; k++)
                    if(a[i] + a[j] + a[k] == 0)
                        count++;
            }
        }
        return count;
    }
    public static int countBinarySearch(int[] a)
    {
        int N = a.length;
        Arrays.sort(a);
        int count = 0;
        for(int i = 0; i < N; i ++)
        {
            for(int j = i+1; j < N; j++)
            {
                int pos = BinarySearch.BinarySearchInt(a, -(a[i] + a[j]));
                System.out.println(a[i]+" "+a[j]+", pos = "+pos);
                if(pos != -1)
                    count++;
            }
        }
        return count;
    }
    public static void main(String[] args)
    {
        In in = new In(args[0]);
        int[] a = in.readAllInts();
        Stopwatch stopwatch = new Stopwatch();
        System.out.println(countBruteForce(a));
        Double time = stopwatch.elapsedTime();
        System.out.println("Elapsed time for O(N^3) algorithm = " + time);
        time = stopwatch.elapsedTime();
        System.out.println(countBinarySearch(a));
        Double timeEnd = stopwatch.elapsedTime();
        System.out.println("Elapsed time for O(N^2 log N) algorithm = " + (timeEnd-time));
    }
}