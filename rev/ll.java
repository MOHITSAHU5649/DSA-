 class Node{
    int data;
    Node next;
    
    Node(int val){
        data = val;
        next = null;
    }
}

 class linklist{
    Node head;
    Node tail;
    
    linklist(){
        head = tail = null;
    }
    
    public void pushfront(int val){
        Node newNode = new Node(val);
        if(head == null){
            head = tail = newNode;
            return;
        }else{
            newNode.next = head;
            head = newNode;
        }
    }
    
    void pushback(int val){
        Node newnode = new Node(val);
        if(head == null){
            head = newnode;
            return;
        }else{
            head.next = newnode;
            tail = newnode;
        }
    }
    
    void popfront(){
        if(head == null){
            return;
        }else{
            Node temp;
            temp = head;
            head = head.next;
            temp.next = null;
            
        }
    }
    
    void popback(){
        if(head == null){
            return;
        }
        
         if (head.next == null) {  // sirf 1 node hai
        head = tail = null;
        return;
    }
           Node temp = head;
           while(temp.next != tail){
               temp = temp.next;
           }
           temp.next = null;
           tail = temp;

        
}    

    void insert (int val, int pos){
    if(pos < 0){
        return;
    }
    if(pos == 0){
        pushfront(val);
        return;
    }
    Node temp = head;
   for(int i =0;i<pos-1;i++){
        temp  = temp.next;
    }
    
    Node newnode = new Node(val);
    newnode.next = temp.next;
    temp.next = newnode;
}
    
    int search(int target){
        Node temp = head;
        int index =0;
        while(temp.next != null){
            if(temp.data == target){
                return index;
            }
            
            temp = temp.next;
            index++;
        }
        return -1;
    }
    
    Node reversell(Node head){
        Node prev = null;
        Node curr = head;
        Node next = null;
        
        while(curr!= null){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next; 
        }
        return prev;
    }
    
    Node middle(Node head){
        Node slow = head;
        Node fast = head;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    
    void printlist(){
        Node temp = head;
        while(temp != null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
}


public class ll {
    	public static void main(String[] args) {
	 linklist ll = new linklist();
	 ll.pushfront(5);
	 ll.pushfront(8);
	 ll.pushfront(6);
	 ll.insert(4,1);
	 ll.head = ll.reversell(ll.head);
// 	 ll.popfront();
// 	 ll.popback();
  //  System.out.println(ll.search(6));
	 ll.printlist();
	}
}
