public class LL2<T> implements List<T> {
    private int listLength;
    private Arr<T> Value = new Arr<>();
    private Arr<Integer> Link = new Arr<>();

    public LL2() {

    }

    public LL2(int Y, T[] givenList) {

    }

    public LL2(int chunkLength, int Y, T[] givenList) {

    }

    @Override
    public void clear() {

    }

    @Override
    public void insert(T item) {

    }

    @Override
    public void append(T item) {
        Value.moveToStart();
        Link.moveToStart();
        for (int i=0; i<listLength; i++){
            if (link.get)
        }
    }

    @Override
    public T remove() {

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
        return listLength;
    }

    @Override
    public int currPos() {

    }

    @Override
    public void moveToPos(int pos) {
        assert pos >= 0 && pos < listLength : "Out of bounds";

    }

    @Override
    public T getValue() {

    }

    @Override
    public int Search(T item) {

    }
}
