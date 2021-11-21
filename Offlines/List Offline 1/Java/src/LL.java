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
}

public class LL<T> implements List<T> {
    private Node<T> head;
    private Node<T> tail;
    private Node<T> cur;
    private int length;

    public LL() {
        head = tail = cur = new Node<>(null);
        length = 0;
    }

    public LL(int maxLength) {
        head = tail = cur = new Node<>(null);
        length = 0;
    }

    public LL(int Y, T[] givenList) {
        head = tail = cur = new Node<>(null);
        for (int i = 0; i < Y; i++) {
            var last = new Node<>(givenList[i], null);
            tail.setNext(last);
            tail = last;
            length++;
        }
    }

    @Override
    public String toString() {
        StringBuilder answer = new StringBuilder();
        var temp = head;
        while (temp != null) {
            if (temp.getElement() != null) answer.append(temp.getElement()).append(" ");
            if (temp == cur) {
                answer.append("| ");
            }
            temp = temp.getNext();
        }
        return answer.toString();
    }

    @Override
    public void clear() {
        head = tail = cur = new Node<>(null);
        length = 0;
    }

    @Override
    public void insert(T item) {
        var it = new Node<>(item, null);
        it.setNext(cur.getNext());
        if (it.getNext() == null) {
            tail = it;
        }
        cur.setNext(it);
        length++;
    }

    @Override
    public void append(T item) {
        var last = new Node<>(item, null);
        tail.setNext(last);
        tail = last;
        length++;
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
        length--;
        return it.getElement();
    }

    @Override
    public void moveToStart() {
        cur = head;
    }

    @Override
    public void moveToEnd() {
        cur = tail;
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
        return length;
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
        assert pos >= 0 && pos <= length : "Out of bounds";
        cur = head;
        while (pos-- > 0) {
            cur = cur.getNext();
        }
    }

    @Override
    public T getValue() {
        if (cur.getNext() == null) return null;
        var it = cur.getNext().getElement();
        return it;
    }

    @Override
    public int Search(T item) {
        boolean isFound = false;
        int i = 0;
        var temp = head;
        while (temp.getNext() != null) {
            temp = temp.getNext();
            if (temp.getElement() == item) {
                isFound = true;
                break;
            }
            i++;
        }
        int ret = -1;
        if (isFound) ret = i;
        return ret;
    }
}
