public class Arr<T> implements List<T> {
    private int maxLength;
    private int listLength;
    private int chunkLength;
    private int cur;
    private T[] listArray;

    public Arr() {
        listLength = cur = 0;
    }

    public Arr(int chunkLength) {
        this.chunkLength = chunkLength;
        listLength = cur = 0;
        maxLength = chunkLength;
        listArray = (T[]) new Object[maxLength];
    }

    public Arr(int chunkLength, int Y, T[] givenList) {
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
    public String toString() {
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < listLength; i++) {
            if (i == cur) answer.append("| ");
            answer.append(listArray[i]);
            if (i < listLength - 1) answer.append(" ");
        }
        if (cur == listLength) {
            if (cur != 0) answer.append(" ");
            answer.append("|");
        }
        return answer.toString();
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
                tempArray[i] = listArray[i - 1];
            }
            tempArray[cur] = item;
            listArray = tempArray;
        } else {
            for (int i = listLength; i > cur; i--) {
                listArray[i] = listArray[i - 1];
            }
            listArray[cur] = item;
        }
        listLength++;
    }

    @Override
    public void append(T item) {
        if (listLength == maxLength) {
            maxLength += chunkLength;
            T[] tempList = (T[]) new Object[maxLength];
            for (int i = 0; i < listLength; i++) {
                tempList[i] = listArray[i];
            }
            tempList[listLength] = item;
            listArray = tempList;
        } else {
            listArray[listLength] = item;
        }
        listLength++;
    }

    @Override
    public T remove() {
        assert cur >= 0 && cur < listLength : "Nothing to remove";
        var ret = listArray[cur];
        for (int i = cur + 1; i < listLength; i++) {
            listArray[i - 1] = listArray[i];
        }
        listLength--;
        return ret;
    }

    @Override
    public void moveToStart() {
        cur = 0;
    }

    @Override
    public void moveToEnd() {
        cur = listLength;
    }

    @Override
    public void prev() {
        if (cur > 0) cur--;
    }

    @Override
    public void next() {
        if (cur < listLength) cur++;
    }

    @Override
    public int length() {
        return listLength;
    }

    @Override
    public int currPos() {
        return cur;
    }

    @Override
    public void moveToPos(int pos) {
        assert pos >= 0 && pos <= listLength : "Out of bounds";
        cur = pos;
    }

    @Override
    public T getValue() {
        assert cur >= 0 && cur < listLength : "No value in this position";
        return listArray[cur];
    }

    @Override
    public int Search(T item) {
        int ret = -1;
        for (int i = 0; i < listLength; i++) {
            if (listArray[i] == item) {
                ret = i;
                break;
            }
        }
        return ret;
    }
}
