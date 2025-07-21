#include "PCAP_Server/Reader.h"
#include "PCAP_Server/Server.h"

#include "Pkt_Observer/Ring_Buff_Forwader.h"
// #include "Observer/Observer.hpp"
#include "utils/RingBuffer.h"

#include <thread>
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Welcome to Spencer's NYSE LL Packet Observer" << std::endl;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <pcap_file>\n";
        return 1;
    }

    // Take the user-specified pcap file and turn it into a stack-stored vector
    std::string pcap_file = argv[1];
    std::thread pcap_read_thread(PCAPServer::read_pcap, pcap_file);

    // auto packets = PCAPServer::read_pcap(pcap_file);
    // std::cout << "Read pcap: " << packets.size() << std::endl;

    // Create the shared RingBuffer
    using RBType = RingBuffer<PacketSlot, 1024>;
    RBType ringBuffer;

    // Spawn the PacketBufferForwarder in a dedicated thread
    PacketBufferForwarder forwarder(ringBuffer, 5000); // Listening on UDP port 5000
    std::thread forwarder_thread(&PacketBufferForwarder::run, &forwarder);

    // Spawn the Observer to process packets from the RingBuffer
    // Observer observer(ringBuffer);
    // std::thread observer_thread(&Observer::run, &observer);

    // spawn threads to serve the pcap file in real-time to 127.0.0.1:5000
    std::thread replay_thread(PCAPServer::serve_packets);

    // TODO: Implement Low-Latency packet capture and decision logic here

    forwarder_thread.join();
    replay_thread.join();
    return 0;
}
