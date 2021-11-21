import java.util.Objects;

class Node<T> {
    private T element;
    private Node<T> next;

    public Node(T itemVal, Node<T> nextItem) {
        element = itemVal;
        next = nextItem;
    }

    public Node(Node<T> nextItem) {
        next = nextItem;
    }

    public Node<T> getNext() {
        return next;
    }

    public T getElement() {
        return element;
    }

    public void setNext(Node<T> next) {
        this.next = next;
    }

    @Override
    public int hashCode() {
        return Objects.hash(element, next);
    }
}

public class LL<T> implements List<T> {
    private Node<T> head;
    private Node<T> tail;
    private Node<T> cur;
    private int listLength;

    public LL() {
        head = tail = cur = new Node<>(null);
        listLength = 0;
    }

    public LL(int maxLength) {
        head = tail = cur = new Node<>(null);
        listLength = 0;
    }

    public LL(int Y, T[] givenList) {
        head = tail = cur = new Node<>(null);
        for (int i = 0; i < Y; i++) {
            var last = new Node<>(givenList[i], null);
            tail.setNext(last);
            tail = last;
            listLength++;
        }
    }

//    @Override
//    public String toString() {
//        StringBuilder answer = new StringBuilder();
//        var temp = head;
//        while (temp != null) {
//            if (temp.getElement() != null) answer.append(temp.getElement()).append(" ");
//            if (temp == cur) {
//                answer.append("| ");
//            }
//            temp = temp.getNext();
//        }
//        return answer.toString();
//    }

    @Override
    public void clear() {
        head = tail = cur = new Node<>(null);
        listLength = 0;
    }

    @Override
    public void insert(T item) {
        var it = new Node<>(item, cur.getNext());
        if (it.getNext() == null) {
            tail = it;
        }
        cur.setNext(it);
        listLength++;
    }

    @Override
    public void append(T item) {
        var last = new Node<>(item, null);
        tail.setNext(last);
        tail = last;
        listLength++;
    }

    @Override
    public T remove() {
        if (cur.getNext() == null) return null;
        var it = cur.getNext();
        if (it == tail) {
            tail = cur;
            tail.setNext(null);
        } else {
            cur.setNext(it.getNext());
        }
        listLength--;
        if (currPos() == listLength) prev();
        return it.getElement();
    }

    @Override
    public void moveToStart() {
        cur = head;
    }

    @Override
    public void moveToEnd() {
        /*
        We are setting the current element as such cur.getNext().getElement() will return the current item. We expect that a moveToEnd() call followed by remove() will delete the last element.
         So, we actually need to set the cur to be the element preceding the tail, when moveToEnd() is called.
         */
        if (listLength == 0) return;
        var temp = head;
        while (temp.getNext() != tail){
            temp = temp.getNext();
        }
        cur = temp;
    }

    @Override
    public void prev() {
        if (cur == head) return;
        var temp = head;
        while (temp.getNext() != cur) {
            temp = temp.getNext();
        }
        cur = temp;
    }

    @Override
    public void next() {
        if (cur.getNext() == null) return;
        cur = cur.getNext();
    }

    @Override
    public int length() {
        return listLength;
    }

    @Override
    public int currPos() {
        var temp = head;
        int i = 0;
        while (temp != cur) {
            temp = temp.getNext();
            i++;
        }
        return i;
    }

    @Override
    public void moveToPos(int pos) {
        assert pos >= 0 && pos < listLength : "Out of bounds";
        cur = head;
        while (pos-- > 0) {
            cur = cur.getNext();
        }
    }

    @Override
    public T getValue() {
        if (cur.getNext() == null) return null;
        return cur.getNext().getElement();
    }

    @Override
    public int Search(T item) {
        boolean isFound = false;
        int i = 0;
        int ret = -1;
        var temp = head;
        while (temp.getNext() != null) {
            temp = temp.getNext();
            if (temp.getElement().equals(item)) {
                isFound = true;
                break;
            }
            i++;
        }
        if (isFound) ret = i;
        return ret;
    }
}
