/********************************************** list interface ********************************************/
public interface list_interface<E> {
    void append(E elem);
    void add(int pos, E elem);
    boolean isEmpty();
    void pop();
    void delete(int pos);
    int size();
    E get(int pos);
    void printList();
}

