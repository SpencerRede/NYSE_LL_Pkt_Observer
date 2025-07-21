#include "PCAP_Server/PacketData.h"
#include "PCAP_Server/shared_mutex.h"
#include <pcap.h>
#include <iostream>

namespace PCAPServer {
    void read_pcap(const std::string& filename){
        std::cout << "Reading: " << filename << std::endl;

        char errbuf[PCAP_ERRBUF_SIZE];
        pcap_t* handle = pcap_open_offline(filename.c_str(), errbuf);
        if (!handle) {
            std::cout << "Err w/ pcap_open_offline: " << errbuf << std::endl;
        }

        const u_char* data;
        pcap_pkthdr* header;
        
        bool isFirst = true;
        // we want to read a single packet at a time to handle large pcap files
        while (pcap_next_ex(handle, &header, &data) > 0) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [] {return ready_to_read;});

            std::cout << "Read pkt: " << header->ts.tv_sec << std::endl;
            PacketData pkt;
            pkt.data.assign(data, data + header->caplen);
            pkt.timestamp = header->ts;
            
            if (isFirst) {
                initial_pkt = std::move(pkt);
                isFirst = false;
            }
            curr_pkt = std::move(pkt);


            ready_to_read = false;
            ready_to_send = true;
            std::cout << "Read fin: ready_to_send=" << ready_to_send << ", done=" << done << "\n";

            cv.notify_all();
        }

        pcap_close(handle);

        // notify we are done reading the pcap file
        std::unique_lock<std::mutex> lock(mtx);
        done = true;
        cv.notify_all();

        return;
    }
} // namespace PCAPServer