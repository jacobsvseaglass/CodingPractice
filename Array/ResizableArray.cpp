//https://neetcode.io/problems/dynamicArray

class DynamicArray {
public:

    DynamicArray(int capacity)
    {
        //Set data
        _data = new int[capacity];
        //Set size
        _size = 0;
        //set capacity
        _capacity = capacity;
    }

    //Will return the element at index i (assume that index i is valid)
    int get(int i)
    {
        return _data[i];
    }

    //Will set the element at index i to n (assume that index i is valid)
    void set(int i, int n)
    {
        _data[i] = n;
    }

    //Will push the element n to the end of the array
    void pushback(int n)
    {
        if (_size == _capacity)
            resize();

        _data[_size] = n;
        _size++;
    }

    //Will pop and return the element at the end of the array. Assume that the array is non-empty.
    int popback()
    {
        int value = _data[--_size];
        return value;
    }

    void resize()
    {
        int* tempData = new int[_capacity * 2];
        for (int i = 0; i < _size; i++)
        {
            tempData[i] = _data[i];
        }
        delete[] _data;
        _data = tempData;
        _capacity *= 2;
    }

    int getSize()
    {
        return _size;
    }

    int getCapacity()
    {
        return _capacity;
    }

private:
    int _size;
    int _capacity;
    int* _data;
};
