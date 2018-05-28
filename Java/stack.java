public class stack implements stack_interface<Object> {
    private Object[] stack;
    private int sizeLimit;
    private int stackSize;

    public stack() {
        this.stack = new Object[10];
        this.sizeLimit = 10;
        this.stackSize = 0;
    }

    public stack(int size) {
        this.stack = new Object[size];
        this.sizeLimit = size;
        this.stackSize = 0;
    }

    public boolean isFull() {
        if (stackSize == sizeLimit) {
            return true;
        }
        else {
            return false;
        }
    }

    public boolean isEmpty() {
        if (stackSize == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    public boolean push(Object elem) {
        if (isFull()) {
            System.out.println("Error: Stack is full");
            return false;
        }
        else {
            stack[stackSize] = elem;
            stackSize++;
            return true;
        }
    }

    public int stackSize() {
        return this.stack.length;
    }

    public boolean pop() {
        if (this.isEmpty()) {
            System.out.println("Error: Stack is empty");
            return false;
        }
        else {
            Object [] temp_stack = new Object[stackSize];
            for (int i = 0; i < stackSize - 1; i++) {
                temp_stack[i] = this.stack[i];
            }
            this.stack = temp_stack;
            return true;         
        }
    }

    public int getIndex(Object elem) {
        for (int i = 0; i < this.stack.length; i++) {
            if (this.stack[i] == elem) {
                return i;
            }
        }
        return -1;
    }

    public Object getElem(int index) {
        if (index <= this.stack.length) {
            return this.stack[index];
        }
        else {
            return null;
        }
    }

    public boolean inStack(Object elem) {
        for (int i = 0; i < this.stack.length; i ++) {
            if (this.stack[i] == elem) {
                return true;
            }
        }
        return false;
    }

    public void printStack() {
        for (int i = 0; i <= this.stack.length; i++) {
            if (this.stack[i] == null) {
                break;
            }
            System.out.println(this.stack[i]);
        }
    }
}