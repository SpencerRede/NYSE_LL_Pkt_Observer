#pragma once
#include <atomic>
#include <array>
#include <optional>
#include <memory>
#include <cstddef>

template <typename T, size_t Capacity>
class RingBuffer {
public:
    RingBuffer() : head_(0), tail_(0) {}

    bool push(T&& item) {
        size_t current_head = head_.load(std::memory_order_relaxed);
        size_t next_head = (current_head + 1) % Capacity;

        if (next_head == tail_.load(std::memory_order_acquire)) {
            // Buffer is full
            return false;
        }

        buffer_[current_head] = std::move(item);
        head_.store(next_head, std::memory_order_release);
        return true;
    }

    bool pop(T& item) {
        size_t current_tail = tail_.load(std::memory_order_relaxed);

        if (current_tail == head_.load(std::memory_order_acquire)) {
            // Buffer is empty
            return false;
        }

        item = buffer_[current_tail];
        tail_.store((current_tail + 1) % Capacity, std::memory_order_release);
        return true;
    }

private:
    std::array<T, Capacity> buffer_;
    std::atomic<size_t> head_;
    std::atomic<size_t> tail_;
};
