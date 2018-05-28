public interface stack_interface<E> {
    boolean push(E elem);
    boolean pop();
    boolean isEmpty();
    boolean isFull();
    int stackSize();
    int getIndex(E elem);
    E getElem(int index);
    boolean inStack(E elem);
    void printStack();
}