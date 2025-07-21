#include "PCAP_Server/Reader.h"
#include "PCAP_Server/shared_mutex.h"

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

    void serve_packets(){
        int sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (sock < 0) {
            perror("socket");
            return;
        }
        
        sockaddr_in dest_addr{};
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(dest_port);
        inet_pton(dest_addr.sin_family, dest_add.c_str(), &dest_addr.sin_addr);

        auto initial_tp = std::chrono::system_clock::now();

        while (true) {
            std::unique_lock<std::mutex> server_lock(mtx);
            cv.wait(server_lock, [] {return ready_to_send || done;});
            std::cout << "WAIT wakeup: ready_to_send=" << ready_to_send << ", done=" << done << "\n";


            if (done && !ready_to_send) {
                break;
            }
            std::cout << "CurrPacket: " << curr_pkt.timestamp.tv_usec << std::endl;
            auto temp_packet = curr_pkt;
            ready_to_read = true;
            ready_to_send = false;
            cv.notify_all();
            server_lock.unlock();

            std::cout << "Sending packet: " << std::to_string(temp_packet.timestamp.tv_sec) << "\t";

            // calc offset to initial packet
            int64_t pkt_us = temp_packet.timestamp.tv_sec * 1000000LL + temp_packet.timestamp.tv_usec;
            int64_t base_us = initial_pkt.timestamp.tv_sec * 1000000LL + initial_pkt.timestamp.tv_usec;

            auto target_tp = initial_tp + std::chrono::microseconds(pkt_us - base_us);

            std::cout << "Waiting until +" << std::chrono::microseconds(pkt_us - base_us).count() << "us\n";
            std::this_thread::sleep_until(target_tp);

            // send the packet to the UDP socket
            ssize_t sent = sendto(sock, temp_packet.data.data(), temp_packet.data.size(), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));

            if (sent < 0) perror("sendto");

        }

        close(sock);
    }
} // namespace PCAPServer