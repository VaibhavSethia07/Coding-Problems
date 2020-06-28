/*
class Rotate{
    // This function should rotate list counter-
    // clockwise by k and return head node
    
    public Node rotate(Node head, int k) {
        Node temp = head;
        
        Node curr = head;
        int  count = 0;
        Node prev;
        
        while(curr.next != null)
            curr = curr.next;
            
        curr.next = head;
        
        curr = head;
        while(true){
            count++;
            prev = curr;
            curr = curr.next;
            if(count == k){
                head = curr;
                prev.next = null;
                break;
            }
        }
        
        return head;
    }
}

##############################################################################Solution#############################################################################################
*/

class Rotate{
    // This function should rotate list counter-
    // clockwise by k and return head node
    
    public Node rotate(Node head, int k) {
        Node temp = head;
        
        Node curr = head;
        int  count = 0;
        Node prev;
        
        while(curr.next != null)
            curr = curr.next;
            
        curr.next = head;
        
        curr = head;
        while(true){
            count++;
            prev = curr;
            curr = curr.next;
            if(count == k){
                head = curr;
                prev.next = null;
                break;
            }
        }
        
        return head;
    }
}
