#include "Pkt_Observer/Ring_Buff_Forwader.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <thread>
#include <chrono>
#include <iostream>

void PacketBufferForwarder::run() {
    // std::cout << "PacketBufferForwarder::run" << std::endl;
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        std::cout << "Failed to create UDP socket" << std::endl;
        return;
    }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(m_port);

    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        std::cout << "Failed to bind UDP socket" << std::endl;
        close(sock);
        return;
    }

    std::cout << "PacketBufferForwarder listening on port " << m_port << std::endl;

    while (true) {
        uint8_t buffer[2048]; // NYSE max packet size < 1400
        ssize_t len = recv(sock, buffer, sizeof(buffer), 0);

        if (len < 0) {
            std::cout << "recv returned negative, retrying" << std::endl;
            continue;
        }

        PacketSlot slot;
        slot.data = std::make_unique<uint8_t[]>(len);
        std::memcpy(slot.data.get(), buffer, len);
        slot.size = len;

        if (!m_ringBuffer.push(std::move(slot))) {
            std::cout << "RingBuffer full, dropping packet" << std::endl;
        }
    }

    close(sock);
}