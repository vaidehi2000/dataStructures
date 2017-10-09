public class CircularQueue {

    private int size, current, head;
    private Object[] items;

    public CircularQueue(int maxSize) {
        if (maxSize <= 0) {
            throw new IllegalArgumentException("Queue cannot contain negative ou zero elements");
        }

        this.items = new Object[maxSize];
        this.current = 0;
        this.head = 0;
        this.size = 0;
    }

    public int size() {
        return size;
    }

    public int maxSize() {
        return items.length;
    }

    public boolean isFull() {
        return items.length == size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * Dequeue a object
     * @return the next queue's object
     * @throws Exception when queue is empty
     */
    public Object pop() throws Exception {
        if (isEmpty())
            throw new Exception("Queue is empty");

        Object obj = items[head++];
        head = head % items.length;
        size--;
        return obj;
    }

    /**
     * Enqueue a object
     * @param item the object to queue
     * @throws Exception when queue is full
     */
    public void push(Object item) throws Exception{
        if (isFull()) {
            throw new Exception("Queue is full");
        }

        items[current++] = item;
        current = current % items.length;
        size++;
    }

    public static void main(String[] args) {
        Integer a = new Integer(1);
        Integer b = new Integer(2);
        Integer c = new Integer(3);
        Integer d = new Integer(4);

        CircularQueue queue = new CircularQueue(3);
        try {
            System.out.println("[QUEUE] START TEST");
            queue.push(a); System.out.println("[QUEUE] enqueue " + a);
            queue.push(b); System.out.println("[QUEUE] enqueue " + b);
            queue.push(c); System.out.println("[QUEUE] enqueue " + c);

            System.out.println("[QUEUE] dequeue " + queue.pop().toString());
            System.out.println("[QUEUE] dequeue " + queue.pop().toString());

            queue.push(d); System.out.println("[QUEUE] enqueue " + d);
            queue.push(c); System.out.println("[QUEUE] enqueue " + b);

            System.out.println("[QUEUE] dequeue " + queue.pop().toString());
            System.out.println("[QUEUE] END");
        } catch (Exception ex) {
            System.out.println("[QUEUE] EXCEPTION: " + ex.getMessage());
        }
    }

}

