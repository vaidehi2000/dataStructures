public class CircularStack {

    private int size, current, top;
    private Object[] items;

    public CircularStack(int maxSize) {
        if (maxSize <= 0) {
            throw new IllegalArgumentException("Queue cannot contain negative ou zero elements");
        }

        this.items = new Object[maxSize];
        this.current = 0;
        this.top = 0;
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
     * Get the element on stack's top
     * @return element, generic
     * @throws Exception when stack is empty
     */
    public Object pop() throws Exception {
        if (isEmpty())
            throw new Exception("Queue is empty");

        Object obj = items[top];
        top--;
        size--;
        return obj;
    }

    /**
     * Put a element on stack
     * @param item element to put on stack
     * @throws Exception when the stack is full
     */
    public void push(Object item) throws Exception{
        if (isFull()) {
            throw new Exception("Queue is full");
        }

        top = current;
        items[current++] = item;
        current = current % items.length;
        size++;
    }

    /**
     * Test stack
     * @param args
     */
    public static void main(String[] args) {
        Integer a = new Integer(1);
        Integer b = new Integer(2);
        Integer c = new Integer(3);
        Integer d = new Integer(4);

        CircularStack stack = new CircularStack(3);
        try {
            System.out.println("[STACK] START TEST");
            stack.push(a); System.out.println("[STACK] push " + a);
            stack.push(b); System.out.println("[STACK] push " + b);
            stack.push(c); System.out.println("[STACK] push " + c);
            stack.push(c); System.out.println("[STACK] push " + c);

            System.out.println("[STACK] pop " + stack.pop().toString());
            System.out.println("[STACK] pop " + stack.pop().toString());
            System.out.println("[STACK] pop " + stack.pop().toString());

            stack.push(d); System.out.println("[STACK] push " + d);

            System.out.println("[STACK] pop " + stack.pop().toString());
            System.out.println("[STACK] pop " + stack.pop().toString());

            stack.push(c); System.out.println("[STACK] push " + c);
            System.out.println("[STACK] END");
        } catch (Exception ex) {
            System.out.println("[STACK] EXCEPTION: " + ex.getMessage());
        }
    }
}
