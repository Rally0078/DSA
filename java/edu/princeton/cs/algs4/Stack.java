package edu.princeton.cs.algs4;

public class Stack {
    public class Node {
        String item;
        Node next;
    }
    private Node top = null;
    Boolean isEmpty(){
        return top == null;
    }
    String pop(){
        String item = top.item;
        top = top.next;
        return item;
    }
    void push(String item){
        Node oldNode = top;
        top = new Node();
        top.item = item;
        top.next = oldNode;
    }
}