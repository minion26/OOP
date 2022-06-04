#include <iostream>

template <class Key, class Value>
class Map {
private:
    struct Pair {
        Key key;
        Value value;
        int index;
        // !=
        // int, const char, int
        // 0,    nullptr,    0
    } elements[100];

    // The total number of elements currently in the Map
    int currentPosition = 0;
public:
    Map()
    {

    }

    Value& operator[](Key index)
    {
        int pos = -1;
        for (int i = 0; i < currentPosition; i++)
            if (elements[i].key == index)
            {
                pos = i;
                break;
            }

        // If the key already exists
        if (pos != -1)
            return elements[pos].value;

        elements[currentPosition].index = currentPosition;
        elements[currentPosition].key = index;

        return elements[currentPosition++].value; //returnez unde sa mi puna, iar in main ii zic ce sa mi puna
    }

    Pair* begin()
    {
        return &elements[0];
    }

    Pair* end()
    {
        return &elements[currentPosition];
    }

    bool Set(Key key, Value value)
    {
        // Key already exists
        for (int i = 0; i < currentPosition; i++)
            if (elements[i].key == key)
            {
                elements[i].value = value;
                return true;
            }

        // Key is added
        if (currentPosition == 100)
        {
            return false;
        }

        elements[currentPosition].index = currentPosition;
        elements[currentPosition].key = key;
        elements[currentPosition++].value = value;
        return true;
    }

    bool Get(const Key& key, Value& value)
    {
        // Check if key exists
        int pos = -1;
        for (int i = 0; i < currentPosition; i++)
            if (elements[i].key == key)
            {
                pos = i;
                break;
            }

        // The key does not exist
        if (pos == -1)
            return false;

        // The key exists
        value = elements[pos].value;
        return true;
    }

    int Count()
    {
        return currentPosition;
    }

    bool Delete(const Key& keyDel)
    {
        int pos = -1;
        for (int i = 0; i < currentPosition; i++)
            if (elements[i].key == keyDel)
            {
                pos = i;
                break;
            }
        if (pos == -1)
            return false; //n am avut ce sterge
        
        for (int j = pos; j < currentPosition - 1; j++)
        {
            elements[j].key = elements[j + 1].key;
            elements[j].value = elements[j + 1].value;
            elements[j].index = elements[j + 1].index;
        }
        currentPosition--;
        return true;
    }
};

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }


    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m.Delete(20);
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}