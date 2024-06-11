package edu.princeton.cs.algs4;

public class StackClient{
    public static void main(String[] args)
    {
        Stack st = new Stack();
        System.out.println("Input String is :");
        for(String str : args)
        {
            System.out.println(" " + str);
            st.push(str);
        }
        String[] reversed = new String[args.length];
        int i = 0;
        while(!st.isEmpty())
        {
            reversed[i] = st.pop();
            i = i + 1;
        }
        System.out.println("Reversed string is :");
        for(String strRev : reversed)
            System.out.println(" " + strRev);
    }
}