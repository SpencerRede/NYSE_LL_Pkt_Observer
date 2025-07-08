#pragma once
#include "PacketData.h"
#include <string>
#include <vector>

namespace PCAPServer {
    void serve_packets(const std::vector<PacketData>& packets);
} // namespace PCAPServer