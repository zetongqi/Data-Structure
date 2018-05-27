/********************************* Implementation of the list interface **************************************/
public class List implements list_interface<Object> {
    // the list to store the elements
    private Object[] list;
    // the int variable to indicate the size of the list
    private int list_size;
    // initial size of the list
    private static final int initial_size = 10;

    // constructor
    public List() {
        list_size = 0;
        list = new Object [initial_size];
    }

    public void append(Object elem) {
        if (list.length == list_size) {
            expandArray();
        }
        list[list_size] = elem;
        list_size ++;
    }

    private void expandArray() {
        Object[] newArray = new Object[list_size*2];
        for (int i = 0; i < list_size; i++) {
            newArray[i] = list[i];
        }
        list = newArray;
    }

    public void add(int pos, Object elem) {
        if (list.length == list_size) {
            expandArray();
        }
        for (int i = list.length; i >= pos; i--) {
            list[i+1] = list[i];
        }
        list[pos] = elem;
    }

    public boolean isEmpty() {
        if (list.length == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    // remove the last element in list
    public void pop() {
        Object[] new_array = new Object[list_size];
        for (int i = 0; i < list_size-1; i++) {
            new_array[i] = list[i];
        }
        list = new_array;
    }

    public void delete(int pos) {
        for (int i = pos; i < list.length; i++) {
            list[i] = list[i+1];
        }
    }

    public int size() {
        return list.length;
    }

    public Object get(int pos) {
        return list[pos];
    }

    public void printList() {
        for (int i = 0; i < list.length; i++) {
            if (list[i] == null) {
                break;
            }
            System.out.println(list[i]+"    ");
        }
 
    }
}

