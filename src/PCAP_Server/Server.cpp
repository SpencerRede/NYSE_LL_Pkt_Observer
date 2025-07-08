#include "PCAP_Server/Reader.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <unistd.h>

namespace PCAPServer {
    std::string dest_add = "127.0.0.1";
    int dest_port = 5000;

    void serve_packets(const std::vector<PacketData>& packets){
        int sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (sock < 0) {
            perror("socket");
            return;
        }
        
        sockaddr_in dest_addr{};
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(dest_port);
        inet_pton(dest_addr.sin_family, dest_add.c_str(), &dest_addr.sin_addr);

        timeval previous_ts = packets.front().timestamp;

        for (const auto& pkt : packets) {
            std::cout << "Sending packet: " << std::to_string(pkt.timestamp.tv_sec) << "\t";

            // current timestamp of packet
            timeval pkt_ts = pkt.timestamp;

            // difference in time stamps from previous packet to current
            long sec_diff = pkt_ts.tv_sec - previous_ts.tv_sec;
            long usec_diff = pkt_ts.tv_usec - previous_ts.tv_usec;
            long long wait_us = sec_diff * 1000000LL + usec_diff;

            // sleep for the difference in time sent in between packets
            auto target_time = std::chrono::microseconds(wait_us);
            std::cout << "Sleeping for " << (wait_us / 1000000.0) << "s" << std::endl;

            std::this_thread::sleep_for(target_time);

            // send the packet to the UDP socket
            ssize_t sent = sendto(sock, pkt.data.data(), pkt.data.size(), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));

            // set the "previous time stamp" to the current for next iteration
            previous_ts = pkt.timestamp;

            if (sent < 0) perror("sendto");
        }

        close(sock);
    }
} // namespace PCAPServer