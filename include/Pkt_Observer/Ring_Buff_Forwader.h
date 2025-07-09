#pragma once
#include "../utils/RingBuffer.h"
#include <cstdint>
#include <memory>
#include <vector>

struct PacketSlot {
    std::unique_ptr<uint8_t[]> data;
    size_t size;
};

class PacketBufferForwarder {
public:
    PacketBufferForwarder(RingBuffer<PacketSlot, 1024>& ringBuffer, uint16_t port)
        : m_ringBuffer(ringBuffer), m_port(port) {}

    void run();

private:
    RingBuffer<PacketSlot, 1024>& m_ringBuffer;
    uint16_t m_port;
};
