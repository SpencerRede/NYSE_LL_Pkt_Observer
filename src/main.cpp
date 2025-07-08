#include "PCAP_Server/Reader.h"
#include "PCAP_Server/Server.h"
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
    auto packets = PCAPServer::read_pcap(pcap_file);
    std::cout << "Read pcap: " << packets.size() << std::endl;

    // spawn a seperate thread to serve the pcap file in real-time to 127.0.0.1:5000
    std::thread replay_thread(PCAPServer::serve_packets, packets);

    // TODO: Implement Low-Latency packet capture and decision logic here

    
    replay_thread.join();
    return 0;
}
