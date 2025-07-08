#include "PCAP_Server/PacketData.h"
#include <pcap.h>
#include <iostream>

namespace PCAPServer {
    std::vector<PacketData> read_pcap(const std::string& filename){
        std::cout << "Reading: " << filename << std::endl;

        char errbuf[PCAP_ERRBUF_SIZE];
        pcap_t* handle = pcap_open_offline(filename.c_str(), errbuf);
        if (!handle) {
            std::cout << "Err w/ pcap_open_offline: " << errbuf << std::endl;
        }

        std::vector<PacketData> packets;
        const u_char* data;
        pcap_pkthdr* header;
        while (pcap_next_ex(handle, &header, &data) > 0) {
            // std::cout << "Found pkt: " << header->ts.tv_sec << std::endl;
            PacketData pkt;
            pkt.data.assign(data, data + header->caplen);
            pkt.timestamp = header->ts;
            packets.push_back(std::move(pkt));
        }

        std::cout << "Total: " << packets.size() << " packets" << std::endl;

        pcap_close(handle);
        return packets;
    }
} // namespace PCAPServer