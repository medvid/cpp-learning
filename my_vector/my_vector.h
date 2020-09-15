#include <array>
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

template<typename T>
class my_vector{
    T *data_m = nullptr;
    size_t size_m = 0;
    size_t capacity_m = 0;
public:
    typedef T value_type;
    typedef value_type* const_iterator;

    my_vector(size_t size, const T& init_val):
        size_m{size}, capacity_m{2*size}
    {
        data_m = new T [capacity_m];
        for(size_t i = 0; i<size_m; ++i){
            data_m[i] = init_val;
        }
    }

    my_vector(const my_vector& rhs):
        size_m{rhs.size_m}, capacity_m{rhs.capacity_m}
    {
        data_m = new T[rhs.capacity_m];
        for(size_t i = 0; i<size_m; ++i){
            data_m[i] = rhs[i];
        }
    }

    void push_back(const T& value)
    {
        size_t capacity_new = capacity_m;
        while (size_m >= capacity_new)
        {
            capacity_new *= 2;
        }
        assert(size_m < capacity_new);
        if (capacity_new > capacity_m)
        {
            T *data_new = new T [capacity_new];
            for (size_t i = 0; i < size_m; i++)
            {
                data_new[i] = data_m[i];
            }
            delete data_m;
            data_m = data_new;
            capacity_m = capacity_new;
        }
        data_m[size_m] = value;
        size_m++;
    }

    T pop_back()
    {
        if (size_m == 0)
        {
            return T();
        }
        return data_m[size_m--];
    }

    void swap(my_vector& rhs)
    {
        std::swap(data_m, rhs.data_m);
        std::swap(capacity_m, rhs.capacity_m);
        std::swap(size_m, rhs.size_m);
    }

    my_vector& operator=(my_vector rhs)
    {
        swap(rhs);
        return *this;
    }

    T& operator[](size_t idx){ return data_m[idx]; }
    constexpr const T& operator[](size_t idx) const { return data_m[idx]; }

    constexpr size_t size() const { return size_m; }

    const_iterator begin() const
    {
        return data_m;
    }
    const_iterator end() const
    {
        return &data_m[size_m - 1];
    }

    ~my_vector(){
       delete[] data_m;
    }
};

template<typename T>
void print(const T& v){
    for(size_t i = 0; i<v.size(); ++i){
        cout << v[i] << endl;
    }
}
