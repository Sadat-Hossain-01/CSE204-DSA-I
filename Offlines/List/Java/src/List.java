public interface List <T>{
    void clear();
    void insert(T item);
    void append(T item);
    T remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int length();
    int currPos();
    void moveToPos(int pos);
    T getValue();
    int Search(T item);
}
