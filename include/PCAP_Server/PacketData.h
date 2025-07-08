#pragma once
#include <vector>
#include <cstdint>
#include <sys/time.h>

namespace PCAPServer {
    struct PacketData {
        std::vector<uint8_t> data;
        timeval timestamp;
    };
} // namespace PCAPServer