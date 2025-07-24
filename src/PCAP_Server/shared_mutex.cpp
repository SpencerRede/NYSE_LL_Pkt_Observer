#include "PCAP_Server/shared_mutex.h"

std::mutex mtx;
std::condition_variable cv;

bool ready_to_read = true;
bool ready_to_send = false;
bool done = false;

PCAPServer::PacketData curr_pkt;
PCAPServer::PacketData initial_pkt;
