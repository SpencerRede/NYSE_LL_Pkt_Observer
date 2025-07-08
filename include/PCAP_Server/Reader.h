#pragma once
#include "PacketData.h"
#include <vector>
#include <string>

namespace PCAPServer {
    std::vector<PacketData> read_pcap(const std::string& filename);
} // namespace PCAPServer