import java.util.*;

public class basic{
    static class Node{
        Node[] chil;
        boolean eow;

    public Node(){
        chil = new Node[26];
        eow = false;
        for(int i =0;i<26;i++){
            chil[i] = null;
        }
    }
}
static Node root = new Node();

public static void insert(String word){
    Node curr = root;
    for(int i =0;i<word.length();i++){
        int index = word.charAt(i) -'a';
        if(curr.chil[index] == null){
            curr.chil[index]  = new Node();
        }

        if(i == word.length()-1){
            curr.chil[index].eow = true;
                }
                curr = curr.chil[index];
    }
}

public static boolean search(String word){
    Node curr = root;
    for(int i =0;i<word.length();i++){
        int index = word.charAt(i)-'a';
        Node node = curr.chil[index];
        if(node == null) {return false;}
        if(i ==word.length() -1 && node.eow == false){
            return false;
        } 
        curr = curr.chil[index];
    }
    return true;
}
    public static void main(String[] args) {
        String words[] = {"my","name","is","mohit","sahu"};
        for(int i= 0;i<words.length;i++){
            insert(words[i]);
        }

        System.out.println(search("mohit"));
    }
}