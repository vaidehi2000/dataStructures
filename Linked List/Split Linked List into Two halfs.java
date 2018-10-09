class SortyList
{
    private class Node
    {
        private int  key;  
        private Node next;  
 
        private Node(int key, Node next)
        {
            this.key  = key;
            this.next = next;
        }
    }
 
    private Node head;   
    private Node first;  
 
    public SortyList()
    {
        head = new Node(0, null);
    }
 
    public SortyList(int first, int ... rest)
    {
        Node last = new Node(first, null);
        this.first = last;
        for (int index = 0; index < rest.length; index += 1)
        {
            last.next = new Node(rest[index], null);
            last = last.next;
        }
        head = new Node(0, null);
    }
 
 
    public SortyList sort()
    {
        first = sort(first);
        return this;
    }
 
    private Node sort(Node unsorted)
    {
 
        if(unsorted == null)
        {
            return unsorted;
        }
        else {
            Node temp = unsorted.next.next;
            Node left = unsorted;
            Node right = unsorted.next;
            left.next = null;
            right.next = null;
            unsorted = temp;
            while (temp.next != null) {
                left.next = temp;
                right.next = temp.next;
                left.next.next = null;
                right.next.next = null;
                temp = temp.next.next;
                unsorted = temp;
            }
            if (left == null || left.next == null) {
                return left;
            }
            if (right == null || right.next == null) {
                return right;
            } else {
                if (left.key <= left.next.key) {
                    sort(left.next);
                }
                if (right.key <= right.next.key) {
                    sort(right.next);
                }
            }
            while (left != null || right != null) {
                if (left != null && right != null) {
                    if (left.key < right.key) {
                        head.next = left;
                        left = left.next;
                    } else {
                        head.next = right;
                        right = right.next;
                    }
                    head = head.next;
                } else if (left == null) {
                    head.next = right;
                    break;
                } else if (right == null) {
                    head.next = left;
                    break;
                }
            }
        }
        return head.next;
    }
 
    public String toString()
    {
        StringBuilder builder = new StringBuilder();
        builder.append('[');
        if (first != null)
        {
            Node temp = first;
            builder.append(temp.key);
            temp = temp.next;
            while (temp != null)
            {
                builder.append(", ");
                builder.append(temp.key);
                temp = temp.next;
            }
        }
        builder.append(']');
        return builder.toString();
    }
 
    public static void main(String[] args)
    {
        System.out.println(new SortyList()                            .sort());
        System.out.println(new SortyList(0)                           .sort());
        System.out.println(new SortyList(1, 0)                        .sort());
        System.out.println(new SortyList(2, 1, 0)                     .sort());
        System.out.println(new SortyList(9, 8, 7, 6, 5, 4, 3, 2, 1, 0).sort());
        System.out.println(new SortyList(5, 8, 4, 9, 0, 1, 2, 3, 7, 6).sort());
    }
}
