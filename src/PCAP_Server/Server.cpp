#include "PCAP_Server/Reader.h"
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <unistd.h>

using namespace std::chrono;

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

        timeval front_ts = packets.front().timestamp;
        int64_t base_us = front_ts.tv_sec * 1000000LL + front_ts.tv_usec;

        auto initial_tp = std::chrono::system_clock::now();

        for (const auto& pkt : packets) {
            std::cout << "Sending packet: " << std::to_string(pkt.timestamp.tv_sec) << "\t";

            // calc offset to initial packet
            int64_t pkt_us = pkt.timestamp.tv_sec * 1000000LL + pkt.timestamp.tv_usec;
            auto target_tp = initial_tp + std::chrono::microseconds(pkt_us - base_us);

            std::cout << "Waiting until +" << std::chrono::microseconds(pkt_us - base_us).count() << "us\n";
            std::this_thread::sleep_until(target_tp);

            // send the packet to the UDP socket
            ssize_t sent = sendto(sock, pkt.data.data(), pkt.data.size(), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));

            if (sent < 0) perror("sendto");
        }

        close(sock);
    }
} // namespace PCAPServer