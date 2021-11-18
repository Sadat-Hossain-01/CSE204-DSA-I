public class AList<T> implements List<T> {
    private int maxLength;
    private int listLength;
    private int chunkLength;
    private int cur;
    private T[] listArray;

    public AList() {
        listLength = cur = 0;
    }

    public AList(int chunkLength) {
        this.chunkLength = chunkLength;
        listLength = cur = 0;
        maxLength = chunkLength;
        listArray = (T[]) new Object[maxLength];
    }

    @Override
    public String toString() {
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < listLength; i++) {
            if (i == cur) answer.append("| ");
            answer.append(listArray[i]);
            if (i < listLength - 1) answer.append(" ");
        }
        if (cur == listLength) answer.append(" |");
        return answer.toString();
    }

    public AList(int chunkLength, int Y, T[] givenList) {
        assert Y <= chunkLength : "Given list larger than initial length";
        this.chunkLength = chunkLength;
        maxLength = chunkLength;
        listLength = Y;
        cur = 0;
        listArray = (T[]) new Object[maxLength];
        for (int i = 0; i < Y; i++) {
            listArray[i] = givenList[i];
        }
    }

    @Override
    public void clear() {
        listLength = 0;
        cur = 0;
    }

    @Override
    public void insert(T item) {
        if (listLength == maxLength) {
            maxLength += chunkLength;
            T[] tempArray = (T[]) new Object[maxLength];
            for (int i = 0; i < cur; i++) {
                tempArray[i] = listArray[i];
            }
            for (int i = listLength; i >= cur + 1; i--) {
                tempArray[i] = listArray[i-1];
            }
        }
    }

    @Override
    public void append(T item) {

    }

    @Override
    public T remove() {
        return null;
    }

    @Override
    public void moveToStart() {

    }

    @Override
    public void moveToEnd() {

    }

    @Override
    public void prev() {

    }

    @Override
    public void next() {

    }

    @Override
    public int length() {
        return 0;
    }

    @Override
    public int currPos() {
        return 0;
    }

    @Override
    public void moveToPos(int pos) {

    }

    @Override
    public T getValue() {
        return null;
    }

    @Override
    public int Search(T item) {
        return 0;
    }
}
