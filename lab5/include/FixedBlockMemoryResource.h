#include <memory_resource>
#include <list>
#include <iostream>
#include <iomanip>
#include <algorithm>

class FixedBlockMemoryResource : public std::pmr::memory_resource {
private:
    class Block {
    public:
        char* ptr;
        size_t size;
        size_t offset;
        Block(char* p, size_t s, size_t o) : ptr(p), size(s), offset(o) {}
    };

    char* memoryBlock_;
    size_t totalSize_;
    std::list<Block> allocatedBlocks_;
        
public:   
    FixedBlockMemoryResource(std::size_t totalSize) : totalSize_(totalSize) {
        memoryBlock_ = new char[totalSize_];
    }

    ~FixedBlockMemoryResource() {
        delete[] memoryBlock_;
    }

    void* do_allocate(size_t bytes, size_t alignment) override {
        size_t offset = 0;
        for (const Block& b : allocatedBlocks_) {
            if ((offset + bytes <= b.offset) || (offset >= b.offset + b.size)) {
                break;
            }
            offset = b.offset + b.size;
        }

        if (offset + bytes > totalSize_) {
            throw std::bad_alloc();
        }

        allocatedBlocks_.emplace_back(memoryBlock_ + offset, bytes, offset);
        allocatedBlocks_.sort([](const Block& lhs, const Block& rhs) {
            return lhs.offset < rhs.offset;
        });

        std::cout << "Allocate " << bytes << " bytes at offset " << offset << "\n";
        printAllocatedBlocks();

        return memoryBlock_ + offset;
    }

    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override {
    std::cout << "Deallocate: " << ptr << " (" << bytes << " bytes)" << std::endl;
    
    for (auto it = allocatedBlocks_.begin(); it != allocatedBlocks_.end(); ++it) {
        if (ptr == memoryBlock_ + it->offset) {  
            allocatedBlocks_.erase(it);  
            printAllocatedBlocks();
            return;
        }
    }
    
    throw std::logic_error("??????: ??????? ??????? ????, ??????? ?? ??? ???????.");
    }

    void printAllocatedBlocks() const {
        std::cout << "Current allocated blocks:\n";
        for (const auto& block : allocatedBlocks_) {
            std::cout << "  Offset: " << std::setw(4) << block.offset
                      << ", Size: " << block.size << "\n";
        }
        std::cout << std::endl;
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }
};
