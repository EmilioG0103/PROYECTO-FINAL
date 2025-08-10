class HashSet {
private:
    HashTableChaining<int> data; // o <T>
public:
    void Add(int element) {
        if (!data.Contains(element)) {
            data.Add(element);
        }
    }
};
