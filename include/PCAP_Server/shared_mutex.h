#pragma once

#include "./PacketData.h"
#include <mutex>
#include <condition_variable>

extern std::mutex mtx;
extern std::condition_variable cv;

extern bool ready_to_send;
extern bool ready_to_read;
extern bool done;

extern PCAPServer::PacketData curr_pkt;
extern PCAPServer::PacketData initial_pkt;
