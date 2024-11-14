#include <memory>
#include <memory_resource>
#include <exception>
#include <concepts>


template <typename T, typename Allocator = std::allocator<T>>
class Stack {
public:
    using allocator_type = Allocator;

    class Iterator {
    public:

        Iterator(T* ptr) : ptr_(ptr) {}

        T& operator*() const {
            return *ptr_;
        }

        T* operator->() const {
            return ptr_;
        }

        Iterator& operator++() {
            ++ptr_;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator!=(const Iterator& other) const {
            return ptr_ != other.ptr_;
        }

        bool operator==(const Iterator& other) const {
            return ptr_ == other.ptr_;
        }

    private:
        T* ptr_;
    };

    Stack(std::size_t capacity, allocator_type alloc = allocator_type())
        : allocator_(alloc), size_(0), capacity_(capacity) {
        data_ = allocator_.allocate(capacity_);
    }

    ~Stack() {
        for (std::size_t i = 0; i < size_; ++i) {
            allocator_.destroy(data_ + i);  
        }
        allocator_.deallocate(data_, capacity_); 
    }

    void push(const T& value) {
        if (size_ == capacity_) {
            reallocate();
        }
        allocator_.construct(data_ + size_, value);  
        ++size_;
    }

    void pop() {
        if (size_ > 0) {
            --size_;
            allocator_.destroy(data_ + size_);  
        }
    }

    const T& top() const {
        return data_[size_ - 1];
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    Iterator begin() {
        return Iterator(data_);
    }

    Iterator end() {
        return Iterator(data_ + size_);
    }

private:
    void reallocate() {
        capacity_ *= 2;
        T* new_data = allocator_.allocate(capacity_);
        for (std::size_t i = 0; i < size_; ++i) {
            allocator_.construct(new_data + i, std::move(data_[i]));  
            allocator_.destroy(data_ + i); 
        }
        allocator_.deallocate(data_, capacity_ / 2);  
        data_ = new_data;
    }

    allocator_type allocator_;
    std::size_t size_;
    std::size_t capacity_;
    T* data_; 
};